#include "KundeControllers.h"
#include "../utils/utils.h"
#include "../models/Kunde.h"
#include "../business/KundeDetails.h"

#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include <regex>

// Add definition of your processing function here
using namespace drogon::orm;
using namespace drogon_model::cim_web;

namespace drogon {
    template<>
    inline Kunde fromRequest(const HttpRequest &req) {
        auto json = req.getJsonObject();
        auto kunde = Kunde(*json);
        return kunde;
}
}
void KundeControllers::get(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    LOG_DEBUG << "get";
    auto sort_field = req->getOptionalParameter<std::string>("sort_field").value_or("KUNDENID");
    auto sort_order = req->getOptionalParameter<std::string>("sort_order").value_or("asc");
    auto limit = req->getOptionalParameter<int>("limit").value_or(25);
    auto offset = req->getOptionalParameter<int>("offset").value_or(0);

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();
    const char *sql = "select * \n\
                       from KUNDE \n\
                       order by $sort_field $sort_order";
                       
    // hack workaroun
    auto sql_sub = std::regex_replace(sql, std::regex("\\$sort_field"), sort_field);
    sql_sub = std::regex_replace(sql_sub, std::regex("\\$sort_order"), sort_order);

    *dbClientPtr << std::string(sql_sub)
                 >> [callbackPtr](const Result &result)
                   {
                      if (result.empty()) {
                          auto resp = HttpResponse::newHttpJsonResponse(makeErrResp("resource not found"));
                          resp->setStatusCode(HttpStatusCode::k404NotFound);
                          (*callbackPtr)(resp);
                          return;
                      }

                      Json::Value ret{};
                      for (auto row : result) {
                          Kunde _Kunde{row};
                          KundeDetails KundeDetails{_Kunde};
                          ret.append(KundeDetails.toJson());
                      }

                      auto resp = HttpResponse::newHttpJsonResponse(ret);
                      resp->setStatusCode(HttpStatusCode::k200OK);
                      (*callbackPtr)(resp);
                   }
                 >> [callbackPtr](const DrogonDbException &e)
                   {
                       LOG_ERROR << e.base().what();
                       Json::Value ret{};
                       ret["error"] = "DataBase error";
                       auto resp = HttpResponse::newHttpJsonResponse(ret);
                       resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                       (*callbackPtr)(resp);
                   };
}
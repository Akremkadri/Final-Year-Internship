#include "KundeControllers.h"
#include "../utils/utils.h"
#include "../models/Kunde.h"
#include "../business/KundeDetails.h"
#include "../business/AdminTableReference.h"
#include "../models/Land.h"

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
    drogon_model::cim_web::Land LAND ;
    AdminTableReference Table ;
    Json::Value results ; 

    results  = Table.AdminTableValue<drogon_model::cim_web::Land>(LAND , "TN" , "LAND") ; 
    std::cout << results << std::endl;
    results = Table.AdminTableKeyValue<drogon_model::cim_web::Land>(LAND , "Tunisia" , "LAND_CD" , "LAND") ; 
    std::cout << results << std::endl;

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
 void KundeControllers::getOne(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback, int KUNDENID) const{
        LOG_DEBUG << "getOne kundeID: "<< KUNDENID;
        auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
        auto dbClientPtr = drogon::app().getDbClient();
        LOG_DEBUG << "getone";

        Mapper<Kunde> mp(dbClientPtr);
        mp.findByPrimaryKey(
         KUNDENID,
         [callbackPtr](const Kunde &Kunde) {
             Json::Value ret{};
                    
             KundeDetails KundeDetails{Kunde};
             ret.append(KundeDetails.toJson());
             auto resp = HttpResponse::newHttpJsonResponse(ret);
             resp->setStatusCode(HttpStatusCode::k201Created);
             (*callbackPtr)(resp);
         },
         [callbackPtr](const DrogonDbException &e) {
             const drogon::orm::UnexpectedRows *s = dynamic_cast<const drogon::orm::UnexpectedRows *>(&e.base());
             if(s) {
                 auto resp = HttpResponse::newHttpResponse();
                 resp->setStatusCode(k404NotFound);
                 (*callbackPtr)(resp);
                 return;
             }
             LOG_ERROR << e.base().what();
             Json::Value ret{};
             ret["error"] = "DataBase error";
             auto resp = HttpResponse::newHttpJsonResponse(ret);
             resp->setStatusCode(HttpStatusCode::k500InternalServerError);
             (*callbackPtr)(resp);
    }); 
};

void KundeControllers::createOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,Kunde &&KUNDEN) const {
    LOG_DEBUG << "createOne";
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();
    ValidationModule Validate ; 
    KUNDEN = Validate.PostMappingValidate(KUNDEN) ;
    Mapper<Kunde> mp(dbClientPtr);
    mp.insert(
        KUNDEN,
        [callbackPtr](const Kunde &KUNDEN) {
            Json::Value ret{};
            ret = KUNDEN.toJson();
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k201Created);
            (*callbackPtr)(resp);
        },
        [callbackPtr](const DrogonDbException &e) {
            LOG_ERROR << e.base().what();
            Json::Value ret{};
            ret["error"] = "DataBase error";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k500InternalServerError);
            (*callbackPtr)(resp);
    }); } 

void KundeControllers::updateOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int KUNDENID, Kunde &&pKUNDENID) const {
    LOG_DEBUG << "updateOne ClientID: " << KUNDENID;
    auto jsonPtr = req->jsonObject();
    std::cout << jsonPtr ; 
    if (!jsonPtr) {
      Json::Value ret{};
      ret["error"]="No json object is found in the request";
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(HttpStatusCode::k400BadRequest);
      callback(resp);
      return;
    }

    auto dbClientPtr = drogon::app().getDbClient();

    // blocking IO
    Mapper<Kunde> mp(dbClientPtr);
    Kunde Kunden;
    try {
        Kunden = mp.findFutureByPrimaryKey(KUNDENID).get();
    } catch (const DrogonDbException & e) {
        Json::Value ret{};
        ret["error"] = "resource not found";
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k404NotFound);
        callback(resp);
    }
    ValidationModule Validate ; 

    KUNDENID = Validate.PutMappingValidate( pKUNDENID , KUNDENID ) ; 
    pKUNDENID.setKundenid(KUNDENID) ; 
    pKUNDENID = Validate.TemporaryValidate(pKUNDENID , KUNDENID) ; 

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    mp.insert(
        pKUNDENID,
        [callbackPtr](const Kunde &pKUNDENID) {
            Json::Value ret{};
            ret = pKUNDENID.toJson();
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k201Created);
            (*callbackPtr)(resp);
        },
        [callbackPtr](const DrogonDbException &e) {
            LOG_ERROR << e.base().what();
            Json::Value ret{};
            ret["error"] = "DataBase error";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k500InternalServerError);
            (*callbackPtr)(resp);
    });

}
void KundeControllers::deleteOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int KUNDENID) const {
    LOG_DEBUG << "deleteOne KUNDENID: ";
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();

    Mapper<Kunde> mp(dbClientPtr);
    mp.deleteBy(
        Criteria(Kunde::Cols::_KUNDENID, CompareOperator::EQ, KUNDENID),
        [callbackPtr](const std::size_t count) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(HttpStatusCode::k204NoContent);
            (*callbackPtr)(resp);
        },
        [callbackPtr](const DrogonDbException &e) {
            Json::Value ret{};
            ret["error"] = "DataBase error";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k500InternalServerError);
            (*callbackPtr)(resp);
    });
} 
void KundeControllers::GetAllValidation(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback , std::string Valid_CD) const {
    LOG_DEBUG << "get";
    auto sort_field = req->getOptionalParameter<std::string>("sort_field").value_or("KUNDENID");
    auto sort_order = req->getOptionalParameter<std::string>("sort_order").value_or("asc");
    auto limit = req->getOptionalParameter<int>("limit").value_or(25);
    auto offset = req->getOptionalParameter<int>("offset").value_or(0);

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();
    const char *sql = "select * \n\
                       from KUNDE \n\
                       where VALID_CD = '$Valid_CD' \n\
                       order by $sort_field $sort_order ";
                        
    // hack workaroun
    auto sql_sub = std::regex_replace(sql, std::regex("\\$sort_field"), sort_field);
    sql_sub = std::regex_replace(sql_sub, std::regex("\\$sort_order"), sort_order);
    sql_sub = std::regex_replace(sql_sub, std::regex("\\$Valid_CD"), Valid_CD);

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
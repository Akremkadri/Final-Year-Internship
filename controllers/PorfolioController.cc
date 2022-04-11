#include "PorfolioController.h"
#include "/home/akram/Desktop/WebserverDrogon/WebServer/utils/utils.h"
#include "../models/Portfolio.h"
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <iostream>
// Add definition of your processing function here
using namespace drogon::orm;
using namespace drogon_model::cim_web;

namespace drogon {
    template<>
    inline Portfolio fromRequest(const HttpRequest &req) {
        auto json = req.getJsonObject();
        auto PortFolio = Portfolio(*json);
        return PortFolio;
}
}

void PorfolioController::get(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    LOG_DEBUG << "get";
    auto offset = req->getOptionalParameter<int>("offset").value_or(0);
    auto limit = req->getOptionalParameter<int>("limit").value_or(25);
    auto sortField = req->getOptionalParameter<std::string>("sort_field").value_or("porfolio_id");
    auto sortOrder = req->getOptionalParameter<std::string>("sort_order").value_or("asc");
    auto sortOrderEnum = sortOrder == "asc" ? SortOrder::ASC : SortOrder::DESC;

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();
    Mapper<Portfolio> mp(dbClientPtr);
    mp.orderBy(sortField, sortOrderEnum).offset(offset).limit(limit).findAll(
        [callbackPtr](const std::vector<Portfolio> &Portfolio) {
            Json::Value ret{};
            for (auto j : Portfolio) {
                ret.append(j.toJson());
            }
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k200OK);
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
void PorfolioController::getOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int pPortfolioId) const {
    LOG_DEBUG << "getOne PortfilioID: "<< pPortfolioId;
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();

    Mapper<Portfolio> mp(dbClientPtr);
    mp.findByPrimaryKey(
        pPortfolioId,
        [callbackPtr](const Portfolio &Portfolio) {
            Json::Value ret{};
            ret = Portfolio.toJson();
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
}

void PorfolioController::createOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,  Portfolio &&pPortfolio) const {
    LOG_DEBUG << "createOne";
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();

    Mapper<Portfolio> mp(dbClientPtr);
    mp.insert(
        pPortfolio,
        [callbackPtr](const Portfolio &Portfolio) {
            Json::Value ret{};
            ret = Portfolio.toJson();
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

void PorfolioController::updateOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback,  int pPortfolioId, Portfolio &&pPortfolio) const {
    LOG_DEBUG << "updateOne jobId: " << pPortfolioId;
    auto jsonPtr = req->jsonObject();
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
    Mapper<Portfolio> mp(dbClientPtr);
    Portfolio Portfolio;
    try {
        Portfolio = mp.findFutureByPrimaryKey(pPortfolioId).get();
    } catch (const DrogonDbException & e) {
        Json::Value ret{};
        ret["error"] = "resource not found";
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k404NotFound);
        callback(resp);
    }

    if (pPortfolio.getPorfolioId() != nullptr) {
        Portfolio.setPorfolioId(pPortfolio.getValueOfPorfolioId());}
    if (pPortfolio.getPorfolioName() != nullptr) {
        Portfolio.setPorfolioName(pPortfolio.getValueOfPorfolioName());}
    if (pPortfolio.getDateCreation() != nullptr) {
        Portfolio.setDateCreation(pPortfolio.getValueOfDateCreation());}
    if (pPortfolio.getOpenClosed() != nullptr) {
        Portfolio.setOpenClosed(pPortfolio.getValueOfOpenClosed());}
    
     auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    mp.update(
        Portfolio,
        [callbackPtr](const std::size_t count)
        {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(HttpStatusCode::k204NoContent);
            (*callbackPtr)(resp);
        },
        [callbackPtr](const DrogonDbException &e)
        {
            LOG_ERROR << e.base().what();
            Json::Value ret{};
            ret["error"] = "DataBase error";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(HttpStatusCode::k500InternalServerError);
            (*callbackPtr)(resp);
        });
}

 void PorfolioController::deleteOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int pPortfolioId ) const {
    LOG_DEBUG << "deleteOne Portfolioid: ";
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();

    Mapper<Portfolio> mp(dbClientPtr);
    mp.deleteBy(
        Criteria(Portfolio::Cols::_porfolio_id, CompareOperator::EQ, pPortfolioId),
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
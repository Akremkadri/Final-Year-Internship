/* #include "ClientController.h"
#include "/home/akram/Desktop/WebserverDrogon/WebServer/utils/utils.h"
#include "../models/Client.h"
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
    inline Client fromRequest(const HttpRequest &req) {
        auto json = req.getJsonObject();
        auto client = Client(*json);
        return client;
}
}
void ClientController::get(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) const {
    LOG_DEBUG << "get";
    auto offset = req->getOptionalParameter<int>("offset").value_or(0);
    auto limit = req->getOptionalParameter<int>("limit").value_or(25);
    auto sortField = req->getOptionalParameter<std::string>("sort_field").value_or("Client_Id");
    auto sortOrder = req->getOptionalParameter<std::string>("sort_order").value_or("asc");
    auto sortOrderEnum = sortOrder == "asc" ? SortOrder::ASC : SortOrder::DESC;

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();
    Mapper<Client> mp(dbClientPtr);
    mp.orderBy(sortField, sortOrderEnum).offset(offset).limit(limit).findAll(
        [callbackPtr](const std::vector<Client> &Client) {
            Json::Value ret{};
            for (auto j : Client) {
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
    void ClientController::getOne(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback, int ClientID) const{
        LOG_DEBUG << "getOne PortfilioID: "<< ClientID;
        auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
        auto dbClientPtr = drogon::app().getDbClient();

        Mapper<Client> mp(dbClientPtr);
        mp.findByPrimaryKey(
         ClientID,
         [callbackPtr](const Client &Client) {
             Json::Value ret{};
             ret = Client.toJson();
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
    void ClientController::createOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Client &&pClient) const {
    LOG_DEBUG << "createOne";
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();

    Mapper<Client> mp(dbClientPtr);
    mp.insert(
        pClient,
        [callbackPtr](const Client &Client) {
            Json::Value ret{};
            ret = Client.toJson();
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

void ClientController::updateOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int ClientID, Client &&pClient) const {
    LOG_DEBUG << "updateOne ClientID: " << ClientID;
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
    Mapper<Client> mp(dbClientPtr);
    Client Client;
    try {
        Client = mp.findFutureByPrimaryKey(ClientID).get();
    } catch (const DrogonDbException & e) {
        Json::Value ret{};
        ret["error"] = "resource not found";
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k404NotFound);
        callback(resp);
    }

    if (pClient.getClientId() != nullptr) {
        Client.setClientId(pClient.getValueOfClientId());}

    if (pClient.getName() != nullptr) {
        Client.setName(pClient.getValueOfName());}

    if (pClient.getAccountName() != nullptr) {
        Client.setAccountName(pClient.getValueOfAccountName());}

    if (pClient.getContractLanguage() != nullptr) {
        Client.setContractLanguage(pClient.getValueOfContractLanguage());}

    if (pClient.getCountry() != nullptr) {
        Client.setCountry(pClient.getValueOfCountry());}
        
    if (pClient.getClientManager() != nullptr) {
        Client.setClientManager(pClient.getValueOfClientManager());}

    if (pClient.getClientNature() != nullptr) {
        Client.setClientNature(pClient.getValueOfClientNature());}
        
    if (pClient.getClient() != nullptr) {
        Client.setClient(pClient.getValueOfClient());}

    if (pClient.getRelationshipType() != nullptr) {
        Client.setRelationshipType(pClient.getValueOfRelationshipType());}

    if (pClient.getClientDateOpening() != nullptr) {
        Client.setClientDateOpening(pClient.getValueOfClientDateOpening());}

    if (pClient.getClientDateModifying() != nullptr) {
        Client.setClientDateModifying(pClient.getValueOfClientDateModifying());}
    
    if (pClient.getStatus() != nullptr) {
        Client.setStatus(pClient.getValueOfStatus());}

    
     auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    mp.update(
        Client,
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

 void ClientController::deleteOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int ClientID) const {
    LOG_DEBUG << "deleteOne ClientID: ";
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(std::move(callback));
    auto dbClientPtr = drogon::app().getDbClient();

    Mapper<Client> mp(dbClientPtr);
    mp.deleteBy(
        Criteria(Client::Cols::_Client_Id, CompareOperator::EQ, ClientID),
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
*/
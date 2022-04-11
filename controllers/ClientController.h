#pragma once

#include <drogon/HttpController.h>
#include <../models/Client.h>

using namespace drogon;
using namespace drogon_model::cim_web;

class ClientController : public drogon::HttpController<ClientController>
{
  public:
    METHOD_LIST_BEGIN
     ADD_METHOD_TO(ClientController::get, "/Client", Get);
     ADD_METHOD_TO(ClientController::getOne, "/Client/{1}", Get);
     ADD_METHOD_TO(ClientController::createOne, "/Client", Post);
     ADD_METHOD_TO(ClientController::updateOne, "/Client/{1}", Put);
     ADD_METHOD_TO(ClientController::deleteOne, "/Client/{1}", Delete);
    METHOD_LIST_END
    void get(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) const;
    void getOne(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback, int ClientID) const;
    void createOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Client &&pClient) const;
    void updateOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int ClientID, Client &&pClient) const;
    void deleteOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int ClientID) const;
};

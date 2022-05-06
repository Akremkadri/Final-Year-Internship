#pragma once

#include <drogon/HttpController.h>
#include "../models/Kunde.h"

using namespace drogon;
using namespace drogon_model::cim_web;
class KundeControllers : public drogon::HttpController<KundeControllers>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    ADD_METHOD_TO(KundeControllers::get, "/Kunde", Get);
    ADD_METHOD_TO(KundeControllers::getOne, "/Kunde/{1}", Get, "LoginFilter");
    // ADD_METHOD_TO(KundeControllers::createOne, "/Kunde", Post , "LoginFilter");
    // ADD_METHOD_TO(KundeControllers::updateOne, "/Kunde/{1}", Put , "LoginFilter");
    // ADD_METHOD_TO(KundeControllers::deleteOne, "/Kunde/{1}", Delete, "LoginFilter");
    METHOD_LIST_END
    void get(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) const;
    void getOne(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback, int KUNDENID) const;
    // void createOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Kunde &&KUNDENID) const;
    // void updateOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int KUNDENID, Kunde &&pKUNDENID) const;
    // void deleteOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int KUNDENID) const;
};

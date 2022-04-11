#pragma once
#include <drogon/HttpController.h>
#include <../models/Portfolio.h>

using namespace drogon;
using namespace drogon_model::cim_web;

class PorfolioController : public drogon::HttpController<PorfolioController>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
     ADD_METHOD_TO(PorfolioController::get, "/Porfolio", Get);
     ADD_METHOD_TO(PorfolioController::getOne, "/Porfolio/{1}", Get);
     ADD_METHOD_TO(PorfolioController::createOne, "/Porfolio", Post);
     ADD_METHOD_TO(PorfolioController::updateOne, "/Porfolio/{1}", Put);
     ADD_METHOD_TO(PorfolioController::deleteOne, "/Porfolio/{1}", Delete);
    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void get(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) const;
    void getOne(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback, int pPortfolioId) const;
    void createOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Portfolio &&pPortfolio) const;
    void updateOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int pPortfolioId, Portfolio &&pPortfolio) const;
    void deleteOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int pPortfolioId) const;
};


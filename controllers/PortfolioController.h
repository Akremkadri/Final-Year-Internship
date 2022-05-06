#pragma once

#include <drogon/HttpController.h>
#include "../models/Portfolio.h"
using namespace drogon;

class PortfolioController : public drogon::HttpController<PortfolioController>
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(PortfolioController::get, "/Portfolio", Get);
    // METHOD_ADD(PortfolioController::get, "/{2}/{1}", Get); // path is /PortfolioController/{arg2}/{arg1}
    // METHOD_ADD(PortfolioController::your_method_name, "/{1}/{2}/list", Get); // path is /PortfolioController/{arg1}/{arg2}/list
    // ADD_METHOD_TO(PortfolioController::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    void get(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)> &&callback) const;
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
};

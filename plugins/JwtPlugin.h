#ifndef JWTPLUGIN_H
#define JWTPLUGIN_H

#pragma once

#include <drogon/plugins/Plugin.h>
#include "jwt.h"

class JwtPlugin : public drogon::Plugin<JwtPlugin> {
 public:
    virtual void initAndStart(const Json::Value &config) override;
    virtual void shutdown() override;
    auto init() -> Jwt;

 private:
    Json::Value config;
};
#endif
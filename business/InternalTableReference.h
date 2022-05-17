#ifndef INTERNALTABLEREFERENCE_H
#define INTERNALTABLEREFERENCE_H

#pragma once
#include <iostream>
#include <fstream>
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include "../business/InternalTable.h"


class InternalTableReference
{
public:
    InternalTableReference();
    ~InternalTableReference();
    Json::Value InternalTableReferenceValue(const std::string &Table , const std::string  &Column , const std::string  &Value);
    void Printmap();
    Json::Value SearchJson(const std::string &Table , const std::string  &Column , const std::string  &Value );
private:
std::unordered_map<std::string, Json::Value> my_map;


};

#endif
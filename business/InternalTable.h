#ifndef INTERNALTABLE_H
#define INTERNALTABLE_H

#pragma once
#include <iostream>
#include <fstream>
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <unordered_map>

const std::string defaultPath = "/home/akram/Downloads/internalTables.json";

class InternalTable
{
public:
    InternalTable();
   ~InternalTable();
    // auto InternalTableToMap()
    Json::Value LoadJsonFile(); 
    std::vector<Json::Value> SearchInArray(const Json::Value &json, const std::string &key , const std::string  &value);
    std::string PrintJsonAndKey(const Json::Value& root);
    std::unordered_map<std::string, Json::Value> MapJson();
    void Printall();
    private:
    Json::Value MainJson;

};


#endif
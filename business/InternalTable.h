#ifndef INTERNALTABLE_H
#define INTERNALTABLE_H

#pragma once
#include <iostream>
#include <fstream>
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
 const std::string defaultPath = "/home/akram/Downloads/internalTables.json";
class InternalTable
{
public:
    
    InternalTable();
    ~InternalTable();
    // auto InternalTableToMap()
    Json::Value LoadJsonFile(); 
    std::vector<Json::Value> SearchInArray(const Json::Value &json, const std::string &key , const std::string  &value);
    
};


#endif
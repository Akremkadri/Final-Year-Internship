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
    InternalTable MainTable ;
    InternalTableReference();
    ~InternalTableReference();
    Json::Value InternalTableReferenceValue(const std::string &Table , const std::string  &Column , const std::string  &Value);


};

#endif
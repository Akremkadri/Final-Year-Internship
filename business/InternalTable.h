#ifndef INTERNALTABLE_H
#define INTERNALTABLE_H

#pragma once
#include <iostream>
#include <fstream>
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>

class InternalTable
{
public:
    InternalTable();
    ~InternalTable();
    string LoadJsonFile(); 

private:
string strjson; 

};

#endif
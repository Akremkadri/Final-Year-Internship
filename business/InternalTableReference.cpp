#include "InternalTableReference.h"

InternalTableReference::InternalTableReference()
{

}

InternalTableReference::~InternalTableReference()
{

}

Json::Value InternalTableReference::InternalTableReferenceValue(const std::string &Table , const std::string  &Column , const std::string  &Value)
{
    InternalTable MainTable ;
    Json::Value root ; 
    root = MainTable.LoadJsonFile() ;
    Json::Value column ; 
    std::vector<Json::Value> results ;
    results = MainTable.SearchInArray(root[Table], Column , Value);

    if (results.size()==1) 
    { 
        column = results[0] ; 
        return column ; 
    }
    else 
    {
        std::cout << "error" ; 
         Json::Value ret{};
         ret["error"] = "error";
          return ret;
    }
    
    
}


#include "InternalTableReference.h"

InternalTableReference::InternalTableReference()
{
    InternalTable MainTable ;
    my_map=MainTable.MapJson() ;
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
  void InternalTableReference::Printmap()

  {
      if (my_map.empty())
      std::cout << "fare8a hhh" ; 
    for (const auto& p : my_map ) {
        std::cout << p.first << std::endl; 
    }
  }

  Json::Value InternalTableReference::SearchJson(const std::string &Table , const std::string  &Column , const std::string  &Value) 
  {
      
    Json::Value ret{};
    
    auto i = this->my_map.find(Table);
    if (i == this->my_map.end()) {
        ret["error"] = "InternalTable error";
        return ret;}
    else {
        std::vector<Json::Value> res;
        for (const Json::Value& array : i->second) { // iterate 
            
             if (array[Column].asString() == Value)   // if by "W"
            {
             res.push_back(array);                   // take a copy
            }
           }
            if (res.empty())
            {
                 ret["error"] = "Value Doesnt exist";
                 return ret ;   
            }
            
            else return res[0];}
  
  }

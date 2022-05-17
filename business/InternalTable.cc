#include "InternalTable.h"


InternalTable::InternalTable()
{
  Json::Reader reader;
  
  std::ifstream file(defaultPath);
  file >> MainJson;
    if(reader.parse(file, MainJson, true)){
        //for some reason it always fails to parse
	std::cout  << "Failed to parse configuration\n"
               << reader.getFormattedErrorMessages();}
  
}

InternalTable::~InternalTable()
{

}

Json::Value  InternalTable::LoadJsonFile(){

  Json::Value root;
  Json::Reader reader;
  
  std::ifstream file(defaultPath);
  file >> root;
    if(reader.parse(file, root, true)){
        //for some reason it always fails to parse
	std::cout  << "Failed to parse configuration\n"
               << reader.getFormattedErrorMessages();}
  
  return root; 
}

std::vector<Json::Value> InternalTable::SearchInArray(const Json::Value& root, const std::string &key , const std::string  &value)
{
    std::vector<Json::Value> res;
    for (const Json::Value& array : root)  // iterate over "books"
    {
        if (array[key].asString() == value)   // if by "Petr"
           {
            res.push_back(array[key]);                   // take a copy
           }
    }
    return res;                                    // and return
}
std::string InternalTable::PrintJsonAndKey(const Json::Value& root)
{
  std::string output;
  for ( Json::ValueConstIterator itr = root.begin(); itr != root.end(); itr++)
    {  
    output += "Key: " + itr.key().toStyledString();
     } 
  
  return output;
}
  std::unordered_map<std::string, Json::Value> InternalTable::MapJson(){

    std::unordered_map<std::string, Json::Value> my_map ;
    /* for ( Json::ValueConstIterator  itr = MainJson.begin(); itr != MainJson.end(); itr++)
           {
             const char* str=itr.memberName();
             std::string s(str);
             my_map[s]=VectorJson.get(itr.key().toStyledString() , MainJson) ;} */
           // my_map[itr.key().toStyledString()]=VectorJson.get(itr.key().toStyledString() , MainJson) ;  }
    auto arr = MainJson.getMemberNames();
    for (auto const& id : arr) {
        
        my_map[id]=MainJson[id] ; 
    }
    return my_map ; 
     
  }
  void InternalTable::Printall()
  {

    for (auto const& id : MainJson.getMemberNames()) {
    std::cout << id << std::endl;
    }
    // return JsonFile;
  }






/* auto  InternalTable::InternalTablesToMap(Json::Value root)
{
  InternalMap  std::map<std::string , Json::Value> ; 

  return InternalMap; 
} */

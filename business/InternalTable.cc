#include "InternalTable.h"


InternalTable::InternalTable()
{

}

InternalTable::~InternalTable()
{

}

Json::Value  InternalTable::LoadJsonFile(){

  Json::Value root;
  Json::Reader reader;
  
  std::ifstream file(defaultPath);
  file >> root;
  std::cout << root ; 
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
            res.push_back(array);                   // take a copy
           }
    }
    return res;                                    // and return
}





/* auto  InternalTable::InternalTablesToMap(Json::Value root)
{
  InternalMap  std::map<std::string , Json::Value> ; 

  return InternalMap; 
} */

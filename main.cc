#include <drogon/HttpAppFramework.h>
#include "../business/InternalTableReference.h"

Json::Value root ; 
int main() {    
    InternalTableReference Table; 
   // root = Table.LoadJsonFile() ;
    Json::Value results ;
    results = Table.InternalTableReferenceValue("ACCOUNT_FREQUENCY", "ACCOUNT_FREQUENCY_CD" , "W");
    std::cout << results ; 

    //for (auto i: results)
    //std::cout << i << ' ';
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0",80);
    //Load config file
    drogon::app().loadConfigFile("../config.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}

#ifndef ADMINTABLEREFERENCE_H
#define ADMINTABLEREFERENCE_H


#pragma once
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <iostream>
#include <regex>
#include <drogon/HttpController.h>
#include <drogon/orm/DbClient.h>
#include <drogon/orm/Mapper.h>
 
using namespace drogon;
using namespace drogon::orm; 
class AdminTableReference
{
public:
    AdminTableReference();
    ~AdminTableReference();
    template <typename T> auto AdminTableValue(const T &Model , const std::string &PrimaryKey , const std::string &Column ){
    dbClientPtr = drogon::app().getDbClient();
    LOG_DEBUG << "getOne admintable: ";
    Mapper<T> mp(dbClientPtr);
    Json::Value ret{};
    try {
    ret = mp.findByPrimaryKey(PrimaryKey).toJson();
    return ret[Column] ; }
    catch  (const std::exception& e)
        {
             std::cerr << "exception caught: " << e.what() << '\n';
        }
        std::cout << "0 values found" << std::endl ; 
        ret[Column] = "" ; 
        return ret ; 
    } ; 
    template <typename U> auto AdminTableKeyValue(const U &Model , const std::string &Column , const std::string &PrimaryKey , const std::string &ColumnName) {
        dbClientPtr = drogon::app().getDbClient();
        LOG_DEBUG << "getkey value" ;  
        Mapper<U> mp(dbClientPtr);
        Json::Value ret{} ;
        try{
            ret = mp.findOne(Criteria(ColumnName,CompareOperator::EQ,Column)).toJson() ; 
            return ret[PrimaryKey] ; 
        }
        catch  (const std::exception& e)
        {
             std::cerr << "exception caught: " << e.what() << '\n';
        }
        std::cout << "0 values found" << std::endl ; 
        ret[ColumnName] = "" ; 
        return ret ; 
    } ; 
   
private:
 drogon::orm::DbClientPtr dbClientPtr ;
    

};

#endif
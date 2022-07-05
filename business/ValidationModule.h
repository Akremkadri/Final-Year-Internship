#ifndef VALIDATIONMODULE_H
#define VALIDATIONMODULE_H

#pragma once
#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <regex>
#include <drogon/HttpController.h>
#include <drogon/orm/DbClient.h>
#include <drogon/orm/Mapper.h>


using namespace drogon;
using namespace drogon::orm; 
class ValidationModule
{
public:
    ValidationModule();
    ~ValidationModule();
    template <typename T> std::vector<T> GetMappingValidate( const T &Model , const std::string &ValidCd)
    {
      dbClientPtr = drogon::app().getDbClient();
      LOG_DEBUG << "getOne admintable: ";
      Mapper<T> mp(dbClientPtr);
      std::vector<T> ret;
      try
      {
          ret = mp.findBy(Criteria("VALID_CD",CompareOperator::EQ,ValidCd)) ;
          return ret ; 
      }
      catch(const std::exception& e)
      {
         std::cerr << e.what() << '\n';
      }
      
      return std::vector<T>() ; 
    };
    template <typename T> T PostMappingValidate(T &Model ) const {
      try
      {
         Model.setValidCd("N") ; 
         Model.setAktid(Model.getValueOfKundenid()) ;
         return Model ; 
      }
      catch(const std::exception& e)
      {
         std::cerr << e.what() << '\n';
         std::cout << "Wrong Creation Model" << std::endl ; 
      }
      return Model ; 
    };
    template <typename T> long int PutMappingValidate(T &Model , long int PrimaryKey  ){
      dbClientPtr = drogon::app().getDbClient();
      Mapper<T> mp(dbClientPtr); 
      T TemporaryModel ; 
      int i ;
      try
      {
         TemporaryModel = mp.findByPrimaryKey(PrimaryKey) ; 

      }
      catch(const std::exception& e)
      {
         std::cerr << e.what() << '\n';
         std::cout << "Row doesnt Exist" << std::endl ; 
         return 0 ; 
      }
      Mapper<T> vp(dbClientPtr); 
      TemporaryModel.setValidCd("V") ;
      TemporaryModel.setValidid(TemporaryModel.getValueOfKundenid() + 1000000000 ) ; 
      int Size_t ; 
      Size_t = vp.update(TemporaryModel) ; 
      if (Size_t)
      {
         std::cout << "updated succesfully" << std::endl ; 
      } ;
      return (PrimaryKey + 1000000000) ;
    }; 
    template <typename T> auto DeleteMappingValidate(T &Model ) 
    {
      Model.setValidCd("D") ; 
      Model.setValidid(Model.getValueOfKundenid()) ;
      return Model ; 
    }; 
    template <typename T> auto TemporaryValidate(T &Model , long int PrimaryKey ) {
      Model.setValidCd("T") ; 
      Model.setAktid(PrimaryKey - 1000000000) ;
      return Model ; 
    }; 
    template <typename T> auto Validate (T &Model1 , T &Model2 , long int PrimaryKey ){
      dbClientPtr = drogon::app().getDbClient();
      Mapper<T> mp(dbClientPtr);
      Model1.setValidCd("A") ; 
      Model1.setAktid(0) ;
      long int Size_t ;
      try
      {
         Size_t = mp.update(Model1) ; 
          if (Size_t)
         {
              std::cout << "updated succesfully" << std::endl ; 
         } ;
      }
      catch(const std::exception& e)
      {
         std::cerr << e.what() << '\n';
         std::cout << "Row doesnt Exist" << std::endl ; 
         return 0 ; 
      }
      try
      {
         Size_t = mp.deleteOne(Model2) ; 
          if (Size_t)
         {
              std::cout << "Deleted succesfully" << std::endl ; 
         } ;
      }
      catch(const std::exception& e)
      {
         std::cerr << e.what() << '\n';
         std::cout << "Row doesnt Exist" << std::endl ; 
         return 0 ; 
      }
      
    };

private:
    drogon::orm::DbClientPtr dbClientPtr ;

};

#endif
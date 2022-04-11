

#include "Portfolio.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::cim_web;

const std::string Portfolio::Cols::_porfolio_id = "porfolio_id";
const std::string Portfolio::Cols::_porfolio_name = "porfolio_name";
const std::string Portfolio::Cols::_date_Creation = "date_Creation";
const std::string Portfolio::Cols::_open_closed = "open_closed";
const std::string Portfolio::primaryKeyName = "porfolio_id";
const bool Portfolio::hasPrimaryKey = true;
const std::string Portfolio::tableName = "portfolio";

const std::vector<typename Portfolio::MetaData> Portfolio::metaData_={
{"porfolio_id","int32_t","int(11)",4,1,1,1},
{"porfolio_name","std::string","varchar(255)",255,0,0,1},
{"date_Creation","::trantor::Date","date",0,0,0,0},
{"open_closed","int32_t","int(11)",4,0,0,0}
};
const std::string &Portfolio::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Portfolio::Portfolio(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["porfolio_id"].isNull())
        {
            porfolioId_=std::make_shared<int32_t>(r["porfolio_id"].as<int32_t>());
        }
        if(!r["porfolio_name"].isNull())
        {
            porfolioName_=std::make_shared<std::string>(r["porfolio_name"].as<std::string>());
        }
        if(!r["date_Creation"].isNull())
        {
            auto daysStr = r["date_Creation"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            dateCreation_=std::make_shared<::trantor::Date>(t*1000000);
        }
        if(!r["open_closed"].isNull())
        {
            openClosed_=std::make_shared<int32_t>(r["open_closed"].as<int32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            porfolioId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            porfolioName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            auto daysStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            dateCreation_=std::make_shared<::trantor::Date>(t*1000000);
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            openClosed_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

Portfolio::Portfolio(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            porfolioId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            porfolioName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[2]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            dateCreation_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            openClosed_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

Portfolio::Portfolio(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("porfolio_id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["porfolio_id"].isNull())
        {
            porfolioId_=std::make_shared<int32_t>((int32_t)pJson["porfolio_id"].asInt64());
        }
    }
    if(pJson.isMember("porfolio_name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["porfolio_name"].isNull())
        {
            porfolioName_=std::make_shared<std::string>(pJson["porfolio_name"].asString());
        }
    }
    if(pJson.isMember("date_Creation"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["date_Creation"].isNull())
        {
            auto daysStr = pJson["date_Creation"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            dateCreation_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("open_closed"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["open_closed"].isNull())
        {
            openClosed_=std::make_shared<int32_t>((int32_t)pJson["open_closed"].asInt64());
        }
    }
}

void Portfolio::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            porfolioId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            porfolioName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[2]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            dateCreation_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            openClosed_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

void Portfolio::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("porfolio_id"))
    {
        if(!pJson["porfolio_id"].isNull())
        {
            porfolioId_=std::make_shared<int32_t>((int32_t)pJson["porfolio_id"].asInt64());
        }
    }
    if(pJson.isMember("porfolio_name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["porfolio_name"].isNull())
        {
            porfolioName_=std::make_shared<std::string>(pJson["porfolio_name"].asString());
        }
    }
    if(pJson.isMember("date_Creation"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["date_Creation"].isNull())
        {
            auto daysStr = pJson["date_Creation"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            dateCreation_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("open_closed"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["open_closed"].isNull())
        {
            openClosed_=std::make_shared<int32_t>((int32_t)pJson["open_closed"].asInt64());
        }
    }
}

const int32_t &Portfolio::getValueOfPorfolioId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(porfolioId_)
        return *porfolioId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Portfolio::getPorfolioId() const noexcept
{
    return porfolioId_;
}
void Portfolio::setPorfolioId(const int32_t &pPorfolioId) noexcept
{
    porfolioId_ = std::make_shared<int32_t>(pPorfolioId);
    dirtyFlag_[0] = true;
}
const typename Portfolio::PrimaryKeyType & Portfolio::getPrimaryKey() const
{
    assert(porfolioId_);
    return *porfolioId_;
}

const std::string &Portfolio::getValueOfPorfolioName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(porfolioName_)
        return *porfolioName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Portfolio::getPorfolioName() const noexcept
{
    return porfolioName_;
}
void Portfolio::setPorfolioName(const std::string &pPorfolioName) noexcept
{
    porfolioName_ = std::make_shared<std::string>(pPorfolioName);
    dirtyFlag_[1] = true;
}
void Portfolio::setPorfolioName(std::string &&pPorfolioName) noexcept
{
    porfolioName_ = std::make_shared<std::string>(std::move(pPorfolioName));
    dirtyFlag_[1] = true;
}

const ::trantor::Date &Portfolio::getValueOfDateCreation() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(dateCreation_)
        return *dateCreation_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Portfolio::getDateCreation() const noexcept
{
    return dateCreation_;
}
void Portfolio::setDateCreation(const ::trantor::Date &pDateCreation) noexcept
{
    dateCreation_ = std::make_shared<::trantor::Date>(pDateCreation.roundDay());
    dirtyFlag_[2] = true;
}
void Portfolio::setDateCreationToNull() noexcept
{
    dateCreation_.reset();
    dirtyFlag_[2] = true;
}

const int32_t &Portfolio::getValueOfOpenClosed() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(openClosed_)
        return *openClosed_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Portfolio::getOpenClosed() const noexcept
{
    return openClosed_;
}
void Portfolio::setOpenClosed(const int32_t &pOpenClosed) noexcept
{
    openClosed_ = std::make_shared<int32_t>(pOpenClosed);
    dirtyFlag_[3] = true;
}
void Portfolio::setOpenClosedToNull() noexcept
{
    openClosed_.reset();
    dirtyFlag_[3] = true;
}

void Portfolio::updateId(const uint64_t id)
{
    porfolioId_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &Portfolio::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "porfolio_name",
        "date_Creation",
        "open_closed"
    };
    return inCols;
}

void Portfolio::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getPorfolioName())
        {
            binder << getValueOfPorfolioName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getDateCreation())
        {
            binder << getValueOfDateCreation();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getOpenClosed())
        {
            binder << getValueOfOpenClosed();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Portfolio::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    return ret;
}

void Portfolio::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getPorfolioName())
        {
            binder << getValueOfPorfolioName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getDateCreation())
        {
            binder << getValueOfDateCreation();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getOpenClosed())
        {
            binder << getValueOfOpenClosed();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Portfolio::toJson() const
{
    Json::Value ret;
    if(getPorfolioId())
    {
        ret["porfolio_id"]=getValueOfPorfolioId();
    }
    else
    {
        ret["porfolio_id"]=Json::Value();
    }
    if(getPorfolioName())
    {
        ret["porfolio_name"]=getValueOfPorfolioName();
    }
    else
    {
        ret["porfolio_name"]=Json::Value();
    }
    if(getDateCreation())
    {
        ret["date_Creation"]=getDateCreation()->toDbStringLocal();
    }
    else
    {
        ret["date_Creation"]=Json::Value();
    }
    if(getOpenClosed())
    {
        ret["open_closed"]=getValueOfOpenClosed();
    }
    else
    {
        ret["open_closed"]=Json::Value();
    }
    return ret;
}

Json::Value Portfolio::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getPorfolioId())
            {
                ret[pMasqueradingVector[0]]=getValueOfPorfolioId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getPorfolioName())
            {
                ret[pMasqueradingVector[1]]=getValueOfPorfolioName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getDateCreation())
            {
                ret[pMasqueradingVector[2]]=getDateCreation()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getOpenClosed())
            {
                ret[pMasqueradingVector[3]]=getValueOfOpenClosed();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getPorfolioId())
    {
        ret["porfolio_id"]=getValueOfPorfolioId();
    }
    else
    {
        ret["porfolio_id"]=Json::Value();
    }
    if(getPorfolioName())
    {
        ret["porfolio_name"]=getValueOfPorfolioName();
    }
    else
    {
        ret["porfolio_name"]=Json::Value();
    }
    if(getDateCreation())
    {
        ret["date_Creation"]=getDateCreation()->toDbStringLocal();
    }
    else
    {
        ret["date_Creation"]=Json::Value();
    }
    if(getOpenClosed())
    {
        ret["open_closed"]=getValueOfOpenClosed();
    }
    else
    {
        ret["open_closed"]=Json::Value();
    }
    return ret;
}

bool Portfolio::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("porfolio_id"))
    {
        if(!validJsonOfField(0, "porfolio_id", pJson["porfolio_id"], err, true))
            return false;
    }
    if(pJson.isMember("porfolio_name"))
    {
        if(!validJsonOfField(1, "porfolio_name", pJson["porfolio_name"], err, true))
            return false;
    }
    else
    {
        err="The porfolio_name column cannot be null";
        return false;
    }
    if(pJson.isMember("date_Creation"))
    {
        if(!validJsonOfField(2, "date_Creation", pJson["date_Creation"], err, true))
            return false;
    }
    if(pJson.isMember("open_closed"))
    {
        if(!validJsonOfField(3, "open_closed", pJson["open_closed"], err, true))
            return false;
    }
    return true;
}
bool Portfolio::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                   const std::vector<std::string> &pMasqueradingVector,
                                                   std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Portfolio::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("porfolio_id"))
    {
        if(!validJsonOfField(0, "porfolio_id", pJson["porfolio_id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("porfolio_name"))
    {
        if(!validJsonOfField(1, "porfolio_name", pJson["porfolio_name"], err, false))
            return false;
    }
    if(pJson.isMember("date_Creation"))
    {
        if(!validJsonOfField(2, "date_Creation", pJson["date_Creation"], err, false))
            return false;
    }
    if(pJson.isMember("open_closed"))
    {
        if(!validJsonOfField(3, "open_closed", pJson["open_closed"], err, false))
            return false;
    }
    return true;
}
bool Portfolio::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                 const std::vector<std::string> &pMasqueradingVector,
                                                 std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Portfolio::validJsonOfField(size_t index,
                                 const std::string &fieldName,
                                 const Json::Value &pJson,
                                 std::string &err,
                                 bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}

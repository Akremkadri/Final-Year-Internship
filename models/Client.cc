

#include "Client.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::cim_web;

const std::string Client::Cols::_Client_Id = "Client_Id";
const std::string Client::Cols::_Name = "Name";
const std::string Client::Cols::_Account_name = "Account_name";
const std::string Client::Cols::_Contract_Language = "Contract_Language";
const std::string Client::Cols::_Country = "Country";
const std::string Client::Cols::_CLIENT_Manager = "CLIENT_Manager";
const std::string Client::Cols::_Client_Nature = "Client_Nature";
const std::string Client::Cols::_Client = "Client";
const std::string Client::Cols::_Relationship_Type = "Relationship_Type";
const std::string Client::Cols::_Client_Date_Opening = "Client_Date_Opening";
const std::string Client::Cols::_Client_Date_Modifying = "Client_Date_Modifying";
const std::string Client::Cols::_Status = "Status";
const std::string Client::primaryKeyName = "Client_Id";
const bool Client::hasPrimaryKey = true;
const std::string Client::tableName = "client";

const std::vector<typename Client::MetaData> Client::metaData_={
{"Client_Id","int32_t","int(11)",4,1,1,1},
{"Name","std::string","varchar(255)",255,0,0,1},
{"Account_name","std::string","varchar(255)",255,0,0,1},
{"Contract_Language","std::string","varchar(255)",255,0,0,1},
{"Country","std::string","varchar(255)",255,0,0,1},
{"CLIENT_Manager","std::string","varchar(255)",255,0,0,0},
{"Client_Nature","std::string","varchar(255)",255,0,0,0},
{"Client","std::string","varchar(255)",255,0,0,1},
{"Relationship_Type","std::string","varchar(255)",255,0,0,1},
{"Client_Date_Opening","::trantor::Date","date",0,0,0,1},
{"Client_Date_Modifying","::trantor::Date","date",0,0,0,1},
{"Status","int8_t","tinyint(1)",1,0,0,1}
};
const std::string &Client::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Client::Client(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["Client_Id"].isNull())
        {
            clientId_=std::make_shared<int32_t>(r["Client_Id"].as<int32_t>());
        }
        if(!r["Name"].isNull())
        {
            name_=std::make_shared<std::string>(r["Name"].as<std::string>());
        }
        if(!r["Account_name"].isNull())
        {
            accountName_=std::make_shared<std::string>(r["Account_name"].as<std::string>());
        }
        if(!r["Contract_Language"].isNull())
        {
            contractLanguage_=std::make_shared<std::string>(r["Contract_Language"].as<std::string>());
        }
        if(!r["Country"].isNull())
        {
            country_=std::make_shared<std::string>(r["Country"].as<std::string>());
        }
        if(!r["CLIENT_Manager"].isNull())
        {
            clientManager_=std::make_shared<std::string>(r["CLIENT_Manager"].as<std::string>());
        }
        if(!r["Client_Nature"].isNull())
        {
            clientNature_=std::make_shared<std::string>(r["Client_Nature"].as<std::string>());
        }
        if(!r["Client"].isNull())
        {
            client_=std::make_shared<std::string>(r["Client"].as<std::string>());
        }
        if(!r["Relationship_Type"].isNull())
        {
            relationshipType_=std::make_shared<std::string>(r["Relationship_Type"].as<std::string>());
        }
        if(!r["Client_Date_Opening"].isNull())
        {
            auto daysStr = r["Client_Date_Opening"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateOpening_=std::make_shared<::trantor::Date>(t*1000000);
        }
        if(!r["Client_Date_Modifying"].isNull())
        {
            auto daysStr = r["Client_Date_Modifying"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateModifying_=std::make_shared<::trantor::Date>(t*1000000);
        }
        if(!r["Status"].isNull())
        {
            status_=std::make_shared<int8_t>(r["Status"].as<int8_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 12 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            clientId_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            accountName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            contractLanguage_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            country_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            clientManager_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 6;
        if(!r[index].isNull())
        {
            clientNature_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 7;
        if(!r[index].isNull())
        {
            client_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 8;
        if(!r[index].isNull())
        {
            relationshipType_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 9;
        if(!r[index].isNull())
        {
            auto daysStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateOpening_=std::make_shared<::trantor::Date>(t*1000000);
        }
        index = offset + 10;
        if(!r[index].isNull())
        {
            auto daysStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateModifying_=std::make_shared<::trantor::Date>(t*1000000);
        }
        index = offset + 11;
        if(!r[index].isNull())
        {
            status_=std::make_shared<int8_t>(r[index].as<int8_t>());
        }
    }

}

Client::Client(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 12)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            clientId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            contractLanguage_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            country_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            clientManager_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            clientNature_=std::make_shared<std::string>(pJson[pMasqueradingVector[6]].asString());
        }
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        dirtyFlag_[7] = true;
        if(!pJson[pMasqueradingVector[7]].isNull())
        {
            client_=std::make_shared<std::string>(pJson[pMasqueradingVector[7]].asString());
        }
    }
    if(!pMasqueradingVector[8].empty() && pJson.isMember(pMasqueradingVector[8]))
    {
        dirtyFlag_[8] = true;
        if(!pJson[pMasqueradingVector[8]].isNull())
        {
            relationshipType_=std::make_shared<std::string>(pJson[pMasqueradingVector[8]].asString());
        }
    }
    if(!pMasqueradingVector[9].empty() && pJson.isMember(pMasqueradingVector[9]))
    {
        dirtyFlag_[9] = true;
        if(!pJson[pMasqueradingVector[9]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[9]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateOpening_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[10].empty() && pJson.isMember(pMasqueradingVector[10]))
    {
        dirtyFlag_[10] = true;
        if(!pJson[pMasqueradingVector[10]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[10]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateModifying_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[11].empty() && pJson.isMember(pMasqueradingVector[11]))
    {
        dirtyFlag_[11] = true;
        if(!pJson[pMasqueradingVector[11]].isNull())
        {
            status_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[11]].asInt64());
        }
    }
}

Client::Client(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("Client_Id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["Client_Id"].isNull())
        {
            clientId_=std::make_shared<int32_t>((int32_t)pJson["Client_Id"].asInt64());
        }
    }
    if(pJson.isMember("Name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["Name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["Name"].asString());
        }
    }
    if(pJson.isMember("Account_name"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["Account_name"].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson["Account_name"].asString());
        }
    }
    if(pJson.isMember("Contract_Language"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["Contract_Language"].isNull())
        {
            contractLanguage_=std::make_shared<std::string>(pJson["Contract_Language"].asString());
        }
    }
    if(pJson.isMember("Country"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["Country"].isNull())
        {
            country_=std::make_shared<std::string>(pJson["Country"].asString());
        }
    }
    if(pJson.isMember("CLIENT_Manager"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["CLIENT_Manager"].isNull())
        {
            clientManager_=std::make_shared<std::string>(pJson["CLIENT_Manager"].asString());
        }
    }
    if(pJson.isMember("Client_Nature"))
    {
        dirtyFlag_[6]=true;
        if(!pJson["Client_Nature"].isNull())
        {
            clientNature_=std::make_shared<std::string>(pJson["Client_Nature"].asString());
        }
    }
    if(pJson.isMember("Client"))
    {
        dirtyFlag_[7]=true;
        if(!pJson["Client"].isNull())
        {
            client_=std::make_shared<std::string>(pJson["Client"].asString());
        }
    }
    if(pJson.isMember("Relationship_Type"))
    {
        dirtyFlag_[8]=true;
        if(!pJson["Relationship_Type"].isNull())
        {
            relationshipType_=std::make_shared<std::string>(pJson["Relationship_Type"].asString());
        }
    }
    if(pJson.isMember("Client_Date_Opening"))
    {
        dirtyFlag_[9]=true;
        if(!pJson["Client_Date_Opening"].isNull())
        {
            auto daysStr = pJson["Client_Date_Opening"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateOpening_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("Client_Date_Modifying"))
    {
        dirtyFlag_[10]=true;
        if(!pJson["Client_Date_Modifying"].isNull())
        {
            auto daysStr = pJson["Client_Date_Modifying"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateModifying_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("Status"))
    {
        dirtyFlag_[11]=true;
        if(!pJson["Status"].isNull())
        {
            status_=std::make_shared<int8_t>((int8_t)pJson["Status"].asInt64());
        }
    }
}

void Client::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 12)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            clientId_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            contractLanguage_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            country_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            clientManager_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        dirtyFlag_[6] = true;
        if(!pJson[pMasqueradingVector[6]].isNull())
        {
            clientNature_=std::make_shared<std::string>(pJson[pMasqueradingVector[6]].asString());
        }
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        dirtyFlag_[7] = true;
        if(!pJson[pMasqueradingVector[7]].isNull())
        {
            client_=std::make_shared<std::string>(pJson[pMasqueradingVector[7]].asString());
        }
    }
    if(!pMasqueradingVector[8].empty() && pJson.isMember(pMasqueradingVector[8]))
    {
        dirtyFlag_[8] = true;
        if(!pJson[pMasqueradingVector[8]].isNull())
        {
            relationshipType_=std::make_shared<std::string>(pJson[pMasqueradingVector[8]].asString());
        }
    }
    if(!pMasqueradingVector[9].empty() && pJson.isMember(pMasqueradingVector[9]))
    {
        dirtyFlag_[9] = true;
        if(!pJson[pMasqueradingVector[9]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[9]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateOpening_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[10].empty() && pJson.isMember(pMasqueradingVector[10]))
    {
        dirtyFlag_[10] = true;
        if(!pJson[pMasqueradingVector[10]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[10]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateModifying_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[11].empty() && pJson.isMember(pMasqueradingVector[11]))
    {
        dirtyFlag_[11] = true;
        if(!pJson[pMasqueradingVector[11]].isNull())
        {
            status_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[11]].asInt64());
        }
    }
}

void Client::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("Client_Id"))
    {
        if(!pJson["Client_Id"].isNull())
        {
            clientId_=std::make_shared<int32_t>((int32_t)pJson["Client_Id"].asInt64());
        }
    }
    if(pJson.isMember("Name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["Name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["Name"].asString());
        }
    }
    if(pJson.isMember("Account_name"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["Account_name"].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson["Account_name"].asString());
        }
    }
    if(pJson.isMember("Contract_Language"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["Contract_Language"].isNull())
        {
            contractLanguage_=std::make_shared<std::string>(pJson["Contract_Language"].asString());
        }
    }
    if(pJson.isMember("Country"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["Country"].isNull())
        {
            country_=std::make_shared<std::string>(pJson["Country"].asString());
        }
    }
    if(pJson.isMember("CLIENT_Manager"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["CLIENT_Manager"].isNull())
        {
            clientManager_=std::make_shared<std::string>(pJson["CLIENT_Manager"].asString());
        }
    }
    if(pJson.isMember("Client_Nature"))
    {
        dirtyFlag_[6] = true;
        if(!pJson["Client_Nature"].isNull())
        {
            clientNature_=std::make_shared<std::string>(pJson["Client_Nature"].asString());
        }
    }
    if(pJson.isMember("Client"))
    {
        dirtyFlag_[7] = true;
        if(!pJson["Client"].isNull())
        {
            client_=std::make_shared<std::string>(pJson["Client"].asString());
        }
    }
    if(pJson.isMember("Relationship_Type"))
    {
        dirtyFlag_[8] = true;
        if(!pJson["Relationship_Type"].isNull())
        {
            relationshipType_=std::make_shared<std::string>(pJson["Relationship_Type"].asString());
        }
    }
    if(pJson.isMember("Client_Date_Opening"))
    {
        dirtyFlag_[9] = true;
        if(!pJson["Client_Date_Opening"].isNull())
        {
            auto daysStr = pJson["Client_Date_Opening"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateOpening_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("Client_Date_Modifying"))
    {
        dirtyFlag_[10] = true;
        if(!pJson["Client_Date_Modifying"].isNull())
        {
            auto daysStr = pJson["Client_Date_Modifying"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            clientDateModifying_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("Status"))
    {
        dirtyFlag_[11] = true;
        if(!pJson["Status"].isNull())
        {
            status_=std::make_shared<int8_t>((int8_t)pJson["Status"].asInt64());
        }
    }
}

const int32_t &Client::getValueOfClientId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(clientId_)
        return *clientId_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Client::getClientId() const noexcept
{
    return clientId_;
}
void Client::setClientId(const int32_t &pClientId) noexcept
{
    clientId_ = std::make_shared<int32_t>(pClientId);
    dirtyFlag_[0] = true;
}
const typename Client::PrimaryKeyType & Client::getPrimaryKey() const
{
    assert(clientId_);
    return *clientId_;
}

const std::string &Client::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getName() const noexcept
{
    return name_;
}
void Client::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[1] = true;
}
void Client::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[1] = true;
}

const std::string &Client::getValueOfAccountName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(accountName_)
        return *accountName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getAccountName() const noexcept
{
    return accountName_;
}
void Client::setAccountName(const std::string &pAccountName) noexcept
{
    accountName_ = std::make_shared<std::string>(pAccountName);
    dirtyFlag_[2] = true;
}
void Client::setAccountName(std::string &&pAccountName) noexcept
{
    accountName_ = std::make_shared<std::string>(std::move(pAccountName));
    dirtyFlag_[2] = true;
}

const std::string &Client::getValueOfContractLanguage() const noexcept
{
    const static std::string defaultValue = std::string();
    if(contractLanguage_)
        return *contractLanguage_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getContractLanguage() const noexcept
{
    return contractLanguage_;
}
void Client::setContractLanguage(const std::string &pContractLanguage) noexcept
{
    contractLanguage_ = std::make_shared<std::string>(pContractLanguage);
    dirtyFlag_[3] = true;
}
void Client::setContractLanguage(std::string &&pContractLanguage) noexcept
{
    contractLanguage_ = std::make_shared<std::string>(std::move(pContractLanguage));
    dirtyFlag_[3] = true;
}

const std::string &Client::getValueOfCountry() const noexcept
{
    const static std::string defaultValue = std::string();
    if(country_)
        return *country_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getCountry() const noexcept
{
    return country_;
}
void Client::setCountry(const std::string &pCountry) noexcept
{
    country_ = std::make_shared<std::string>(pCountry);
    dirtyFlag_[4] = true;
}
void Client::setCountry(std::string &&pCountry) noexcept
{
    country_ = std::make_shared<std::string>(std::move(pCountry));
    dirtyFlag_[4] = true;
}

const std::string &Client::getValueOfClientManager() const noexcept
{
    const static std::string defaultValue = std::string();
    if(clientManager_)
        return *clientManager_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getClientManager() const noexcept
{
    return clientManager_;
}
void Client::setClientManager(const std::string &pClientManager) noexcept
{
    clientManager_ = std::make_shared<std::string>(pClientManager);
    dirtyFlag_[5] = true;
}
void Client::setClientManager(std::string &&pClientManager) noexcept
{
    clientManager_ = std::make_shared<std::string>(std::move(pClientManager));
    dirtyFlag_[5] = true;
}
void Client::setClientManagerToNull() noexcept
{
    clientManager_.reset();
    dirtyFlag_[5] = true;
}

const std::string &Client::getValueOfClientNature() const noexcept
{
    const static std::string defaultValue = std::string();
    if(clientNature_)
        return *clientNature_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getClientNature() const noexcept
{
    return clientNature_;
}
void Client::setClientNature(const std::string &pClientNature) noexcept
{
    clientNature_ = std::make_shared<std::string>(pClientNature);
    dirtyFlag_[6] = true;
}
void Client::setClientNature(std::string &&pClientNature) noexcept
{
    clientNature_ = std::make_shared<std::string>(std::move(pClientNature));
    dirtyFlag_[6] = true;
}
void Client::setClientNatureToNull() noexcept
{
    clientNature_.reset();
    dirtyFlag_[6] = true;
}

const std::string &Client::getValueOfClient() const noexcept
{
    const static std::string defaultValue = std::string();
    if(client_)
        return *client_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getClient() const noexcept
{
    return client_;
}
void Client::setClient(const std::string &pClient) noexcept
{
    client_ = std::make_shared<std::string>(pClient);
    dirtyFlag_[7] = true;
}
void Client::setClient(std::string &&pClient) noexcept
{
    client_ = std::make_shared<std::string>(std::move(pClient));
    dirtyFlag_[7] = true;
}

const std::string &Client::getValueOfRelationshipType() const noexcept
{
    const static std::string defaultValue = std::string();
    if(relationshipType_)
        return *relationshipType_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Client::getRelationshipType() const noexcept
{
    return relationshipType_;
}
void Client::setRelationshipType(const std::string &pRelationshipType) noexcept
{
    relationshipType_ = std::make_shared<std::string>(pRelationshipType);
    dirtyFlag_[8] = true;
}
void Client::setRelationshipType(std::string &&pRelationshipType) noexcept
{
    relationshipType_ = std::make_shared<std::string>(std::move(pRelationshipType));
    dirtyFlag_[8] = true;
}

const ::trantor::Date &Client::getValueOfClientDateOpening() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(clientDateOpening_)
        return *clientDateOpening_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Client::getClientDateOpening() const noexcept
{
    return clientDateOpening_;
}
void Client::setClientDateOpening(const ::trantor::Date &pClientDateOpening) noexcept
{
    clientDateOpening_ = std::make_shared<::trantor::Date>(pClientDateOpening.roundDay());
    dirtyFlag_[9] = true;
}

const ::trantor::Date &Client::getValueOfClientDateModifying() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(clientDateModifying_)
        return *clientDateModifying_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Client::getClientDateModifying() const noexcept
{
    return clientDateModifying_;
}
void Client::setClientDateModifying(const ::trantor::Date &pClientDateModifying) noexcept
{
    clientDateModifying_ = std::make_shared<::trantor::Date>(pClientDateModifying.roundDay());
    dirtyFlag_[10] = true;
}

const int8_t &Client::getValueOfStatus() const noexcept
{
    const static int8_t defaultValue = int8_t();
    if(status_)
        return *status_;
    return defaultValue;
}
const std::shared_ptr<int8_t> &Client::getStatus() const noexcept
{
    return status_;
}
void Client::setStatus(const int8_t &pStatus) noexcept
{
    status_ = std::make_shared<int8_t>(pStatus);
    dirtyFlag_[11] = true;
}

void Client::updateId(const uint64_t id)
{
    clientId_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &Client::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "Name",
        "Account_name",
        "Contract_Language",
        "Country",
        "CLIENT_Manager",
        "Client_Nature",
        "Client",
        "Relationship_Type",
        "Client_Date_Opening",
        "Client_Date_Modifying",
        "Status"
    };
    return inCols;
}

void Client::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAccountName())
        {
            binder << getValueOfAccountName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getContractLanguage())
        {
            binder << getValueOfContractLanguage();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getCountry())
        {
            binder << getValueOfCountry();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getClientManager())
        {
            binder << getValueOfClientManager();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getClientNature())
        {
            binder << getValueOfClientNature();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[7])
    {
        if(getClient())
        {
            binder << getValueOfClient();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[8])
    {
        if(getRelationshipType())
        {
            binder << getValueOfRelationshipType();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[9])
    {
        if(getClientDateOpening())
        {
            binder << getValueOfClientDateOpening();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[10])
    {
        if(getClientDateModifying())
        {
            binder << getValueOfClientDateModifying();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[11])
    {
        if(getStatus())
        {
            binder << getValueOfStatus();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Client::updateColumns() const
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
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    if(dirtyFlag_[6])
    {
        ret.push_back(getColumnName(6));
    }
    if(dirtyFlag_[7])
    {
        ret.push_back(getColumnName(7));
    }
    if(dirtyFlag_[8])
    {
        ret.push_back(getColumnName(8));
    }
    if(dirtyFlag_[9])
    {
        ret.push_back(getColumnName(9));
    }
    if(dirtyFlag_[10])
    {
        ret.push_back(getColumnName(10));
    }
    if(dirtyFlag_[11])
    {
        ret.push_back(getColumnName(11));
    }
    return ret;
}

void Client::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAccountName())
        {
            binder << getValueOfAccountName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getContractLanguage())
        {
            binder << getValueOfContractLanguage();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getCountry())
        {
            binder << getValueOfCountry();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getClientManager())
        {
            binder << getValueOfClientManager();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[6])
    {
        if(getClientNature())
        {
            binder << getValueOfClientNature();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[7])
    {
        if(getClient())
        {
            binder << getValueOfClient();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[8])
    {
        if(getRelationshipType())
        {
            binder << getValueOfRelationshipType();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[9])
    {
        if(getClientDateOpening())
        {
            binder << getValueOfClientDateOpening();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[10])
    {
        if(getClientDateModifying())
        {
            binder << getValueOfClientDateModifying();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[11])
    {
        if(getStatus())
        {
            binder << getValueOfStatus();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Client::toJson() const
{
    Json::Value ret;
    if(getClientId())
    {
        ret["Client_Id"]=getValueOfClientId();
    }
    else
    {
        ret["Client_Id"]=Json::Value();
    }
    if(getName())
    {
        ret["Name"]=getValueOfName();
    }
    else
    {
        ret["Name"]=Json::Value();
    }
    if(getAccountName())
    {
        ret["Account_name"]=getValueOfAccountName();
    }
    else
    {
        ret["Account_name"]=Json::Value();
    }
    if(getContractLanguage())
    {
        ret["Contract_Language"]=getValueOfContractLanguage();
    }
    else
    {
        ret["Contract_Language"]=Json::Value();
    }
    if(getCountry())
    {
        ret["Country"]=getValueOfCountry();
    }
    else
    {
        ret["Country"]=Json::Value();
    }
    if(getClientManager())
    {
        ret["CLIENT_Manager"]=getValueOfClientManager();
    }
    else
    {
        ret["CLIENT_Manager"]=Json::Value();
    }
    if(getClientNature())
    {
        ret["Client_Nature"]=getValueOfClientNature();
    }
    else
    {
        ret["Client_Nature"]=Json::Value();
    }
    if(getClient())
    {
        ret["Client"]=getValueOfClient();
    }
    else
    {
        ret["Client"]=Json::Value();
    }
    if(getRelationshipType())
    {
        ret["Relationship_Type"]=getValueOfRelationshipType();
    }
    else
    {
        ret["Relationship_Type"]=Json::Value();
    }
    if(getClientDateOpening())
    {
        ret["Client_Date_Opening"]=getClientDateOpening()->toDbStringLocal();
    }
    else
    {
        ret["Client_Date_Opening"]=Json::Value();
    }
    if(getClientDateModifying())
    {
        ret["Client_Date_Modifying"]=getClientDateModifying()->toDbStringLocal();
    }
    else
    {
        ret["Client_Date_Modifying"]=Json::Value();
    }
    if(getStatus())
    {
        ret["Status"]=getValueOfStatus();
    }
    else
    {
        ret["Status"]=Json::Value();
    }
    return ret;
}

Json::Value Client::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 12)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getClientId())
            {
                ret[pMasqueradingVector[0]]=getValueOfClientId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[1]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getAccountName())
            {
                ret[pMasqueradingVector[2]]=getValueOfAccountName();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getContractLanguage())
            {
                ret[pMasqueradingVector[3]]=getValueOfContractLanguage();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getCountry())
            {
                ret[pMasqueradingVector[4]]=getValueOfCountry();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getClientManager())
            {
                ret[pMasqueradingVector[5]]=getValueOfClientManager();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[6].empty())
        {
            if(getClientNature())
            {
                ret[pMasqueradingVector[6]]=getValueOfClientNature();
            }
            else
            {
                ret[pMasqueradingVector[6]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[7].empty())
        {
            if(getClient())
            {
                ret[pMasqueradingVector[7]]=getValueOfClient();
            }
            else
            {
                ret[pMasqueradingVector[7]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[8].empty())
        {
            if(getRelationshipType())
            {
                ret[pMasqueradingVector[8]]=getValueOfRelationshipType();
            }
            else
            {
                ret[pMasqueradingVector[8]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[9].empty())
        {
            if(getClientDateOpening())
            {
                ret[pMasqueradingVector[9]]=getClientDateOpening()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[9]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[10].empty())
        {
            if(getClientDateModifying())
            {
                ret[pMasqueradingVector[10]]=getClientDateModifying()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[10]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[11].empty())
        {
            if(getStatus())
            {
                ret[pMasqueradingVector[11]]=getValueOfStatus();
            }
            else
            {
                ret[pMasqueradingVector[11]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getClientId())
    {
        ret["Client_Id"]=getValueOfClientId();
    }
    else
    {
        ret["Client_Id"]=Json::Value();
    }
    if(getName())
    {
        ret["Name"]=getValueOfName();
    }
    else
    {
        ret["Name"]=Json::Value();
    }
    if(getAccountName())
    {
        ret["Account_name"]=getValueOfAccountName();
    }
    else
    {
        ret["Account_name"]=Json::Value();
    }
    if(getContractLanguage())
    {
        ret["Contract_Language"]=getValueOfContractLanguage();
    }
    else
    {
        ret["Contract_Language"]=Json::Value();
    }
    if(getCountry())
    {
        ret["Country"]=getValueOfCountry();
    }
    else
    {
        ret["Country"]=Json::Value();
    }
    if(getClientManager())
    {
        ret["CLIENT_Manager"]=getValueOfClientManager();
    }
    else
    {
        ret["CLIENT_Manager"]=Json::Value();
    }
    if(getClientNature())
    {
        ret["Client_Nature"]=getValueOfClientNature();
    }
    else
    {
        ret["Client_Nature"]=Json::Value();
    }
    if(getClient())
    {
        ret["Client"]=getValueOfClient();
    }
    else
    {
        ret["Client"]=Json::Value();
    }
    if(getRelationshipType())
    {
        ret["Relationship_Type"]=getValueOfRelationshipType();
    }
    else
    {
        ret["Relationship_Type"]=Json::Value();
    }
    if(getClientDateOpening())
    {
        ret["Client_Date_Opening"]=getClientDateOpening()->toDbStringLocal();
    }
    else
    {
        ret["Client_Date_Opening"]=Json::Value();
    }
    if(getClientDateModifying())
    {
        ret["Client_Date_Modifying"]=getClientDateModifying()->toDbStringLocal();
    }
    else
    {
        ret["Client_Date_Modifying"]=Json::Value();
    }
    if(getStatus())
    {
        ret["Status"]=getValueOfStatus();
    }
    else
    {
        ret["Status"]=Json::Value();
    }
    return ret;
}

bool Client::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("Client_Id"))
    {
        if(!validJsonOfField(0, "Client_Id", pJson["Client_Id"], err, true))
            return false;
    }
    if(pJson.isMember("Name"))
    {
        if(!validJsonOfField(1, "Name", pJson["Name"], err, true))
            return false;
    }
    else
    {
        err="The Name column cannot be null";
        return false;
    }
    if(pJson.isMember("Account_name"))
    {
        if(!validJsonOfField(2, "Account_name", pJson["Account_name"], err, true))
            return false;
    }
    else
    {
        err="The Account_name column cannot be null";
        return false;
    }
    if(pJson.isMember("Contract_Language"))
    {
        if(!validJsonOfField(3, "Contract_Language", pJson["Contract_Language"], err, true))
            return false;
    }
    else
    {
        err="The Contract_Language column cannot be null";
        return false;
    }
    if(pJson.isMember("Country"))
    {
        if(!validJsonOfField(4, "Country", pJson["Country"], err, true))
            return false;
    }
    else
    {
        err="The Country column cannot be null";
        return false;
    }
    if(pJson.isMember("CLIENT_Manager"))
    {
        if(!validJsonOfField(5, "CLIENT_Manager", pJson["CLIENT_Manager"], err, true))
            return false;
    }
    if(pJson.isMember("Client_Nature"))
    {
        if(!validJsonOfField(6, "Client_Nature", pJson["Client_Nature"], err, true))
            return false;
    }
    if(pJson.isMember("Client"))
    {
        if(!validJsonOfField(7, "Client", pJson["Client"], err, true))
            return false;
    }
    else
    {
        err="The Client column cannot be null";
        return false;
    }
    if(pJson.isMember("Relationship_Type"))
    {
        if(!validJsonOfField(8, "Relationship_Type", pJson["Relationship_Type"], err, true))
            return false;
    }
    else
    {
        err="The Relationship_Type column cannot be null";
        return false;
    }
    if(pJson.isMember("Client_Date_Opening"))
    {
        if(!validJsonOfField(9, "Client_Date_Opening", pJson["Client_Date_Opening"], err, true))
            return false;
    }
    else
    {
        err="The Client_Date_Opening column cannot be null";
        return false;
    }
    if(pJson.isMember("Client_Date_Modifying"))
    {
        if(!validJsonOfField(10, "Client_Date_Modifying", pJson["Client_Date_Modifying"], err, true))
            return false;
    }
    else
    {
        err="The Client_Date_Modifying column cannot be null";
        return false;
    }
    if(pJson.isMember("Status"))
    {
        if(!validJsonOfField(11, "Status", pJson["Status"], err, true))
            return false;
    }
    else
    {
        err="The Status column cannot be null";
        return false;
    }
    return true;
}
bool Client::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 12)
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
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
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
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[6].empty())
      {
          if(pJson.isMember(pMasqueradingVector[6]))
          {
              if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[7].empty())
      {
          if(pJson.isMember(pMasqueradingVector[7]))
          {
              if(!validJsonOfField(7, pMasqueradingVector[7], pJson[pMasqueradingVector[7]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[7] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[8].empty())
      {
          if(pJson.isMember(pMasqueradingVector[8]))
          {
              if(!validJsonOfField(8, pMasqueradingVector[8], pJson[pMasqueradingVector[8]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[8] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[9].empty())
      {
          if(pJson.isMember(pMasqueradingVector[9]))
          {
              if(!validJsonOfField(9, pMasqueradingVector[9], pJson[pMasqueradingVector[9]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[9] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[10].empty())
      {
          if(pJson.isMember(pMasqueradingVector[10]))
          {
              if(!validJsonOfField(10, pMasqueradingVector[10], pJson[pMasqueradingVector[10]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[10] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[11].empty())
      {
          if(pJson.isMember(pMasqueradingVector[11]))
          {
              if(!validJsonOfField(11, pMasqueradingVector[11], pJson[pMasqueradingVector[11]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[11] + " column cannot be null";
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
bool Client::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("Client_Id"))
    {
        if(!validJsonOfField(0, "Client_Id", pJson["Client_Id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("Name"))
    {
        if(!validJsonOfField(1, "Name", pJson["Name"], err, false))
            return false;
    }
    if(pJson.isMember("Account_name"))
    {
        if(!validJsonOfField(2, "Account_name", pJson["Account_name"], err, false))
            return false;
    }
    if(pJson.isMember("Contract_Language"))
    {
        if(!validJsonOfField(3, "Contract_Language", pJson["Contract_Language"], err, false))
            return false;
    }
    if(pJson.isMember("Country"))
    {
        if(!validJsonOfField(4, "Country", pJson["Country"], err, false))
            return false;
    }
    if(pJson.isMember("CLIENT_Manager"))
    {
        if(!validJsonOfField(5, "CLIENT_Manager", pJson["CLIENT_Manager"], err, false))
            return false;
    }
    if(pJson.isMember("Client_Nature"))
    {
        if(!validJsonOfField(6, "Client_Nature", pJson["Client_Nature"], err, false))
            return false;
    }
    if(pJson.isMember("Client"))
    {
        if(!validJsonOfField(7, "Client", pJson["Client"], err, false))
            return false;
    }
    if(pJson.isMember("Relationship_Type"))
    {
        if(!validJsonOfField(8, "Relationship_Type", pJson["Relationship_Type"], err, false))
            return false;
    }
    if(pJson.isMember("Client_Date_Opening"))
    {
        if(!validJsonOfField(9, "Client_Date_Opening", pJson["Client_Date_Opening"], err, false))
            return false;
    }
    if(pJson.isMember("Client_Date_Modifying"))
    {
        if(!validJsonOfField(10, "Client_Date_Modifying", pJson["Client_Date_Modifying"], err, false))
            return false;
    }
    if(pJson.isMember("Status"))
    {
        if(!validJsonOfField(11, "Status", pJson["Status"], err, false))
            return false;
    }
    return true;
}
bool Client::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                              const std::vector<std::string> &pMasqueradingVector,
                                              std::string &err)
{
    if(pMasqueradingVector.size() != 12)
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
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
              return false;
      }
      if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
      {
          if(!validJsonOfField(6, pMasqueradingVector[6], pJson[pMasqueradingVector[6]], err, false))
              return false;
      }
      if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
      {
          if(!validJsonOfField(7, pMasqueradingVector[7], pJson[pMasqueradingVector[7]], err, false))
              return false;
      }
      if(!pMasqueradingVector[8].empty() && pJson.isMember(pMasqueradingVector[8]))
      {
          if(!validJsonOfField(8, pMasqueradingVector[8], pJson[pMasqueradingVector[8]], err, false))
              return false;
      }
      if(!pMasqueradingVector[9].empty() && pJson.isMember(pMasqueradingVector[9]))
      {
          if(!validJsonOfField(9, pMasqueradingVector[9], pJson[pMasqueradingVector[9]], err, false))
              return false;
      }
      if(!pMasqueradingVector[10].empty() && pJson.isMember(pMasqueradingVector[10]))
      {
          if(!validJsonOfField(10, pMasqueradingVector[10], pJson[pMasqueradingVector[10]], err, false))
              return false;
      }
      if(!pMasqueradingVector[11].empty() && pJson.isMember(pMasqueradingVector[11]))
      {
          if(!validJsonOfField(11, pMasqueradingVector[11], pJson[pMasqueradingVector[11]], err, false))
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
bool Client::validJsonOfField(size_t index,
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
        case 3:
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
        case 4:
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
        case 5:
            if(pJson.isNull())
            {
                return true;
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
        case 6:
            if(pJson.isNull())
            {
                return true;
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
        case 7:
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
        case 8:
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
        case 9:
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
            break;
        case 10:
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
            break;
        case 11:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
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
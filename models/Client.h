

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace cim_web
{

class Client
{
  public:
    struct Cols
    {
        static const std::string _Client_Id;
        static const std::string _Name;
        static const std::string _Account_name;
        static const std::string _Contract_Language;
        static const std::string _Country;
        static const std::string _CLIENT_Manager;
        static const std::string _Client_Nature;
        static const std::string _Client;
        static const std::string _Relationship_Type;
        static const std::string _Client_Date_Opening;
        static const std::string _Client_Date_Modifying;
        static const std::string _Status;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = int32_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Client(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Client(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Client(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Client() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column Client_Id  */
    ///Get the value of the column Client_Id, returns the default value if the column is null
    const int32_t &getValueOfClientId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getClientId() const noexcept;
    ///Set the value of the column Client_Id
    void setClientId(const int32_t &pClientId) noexcept;

    /**  For column Name  */
    ///Get the value of the column Name, returns the default value if the column is null
    const std::string &getValueOfName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getName() const noexcept;
    ///Set the value of the column Name
    void setName(const std::string &pName) noexcept;
    void setName(std::string &&pName) noexcept;

    /**  For column Account_name  */
    ///Get the value of the column Account_name, returns the default value if the column is null
    const std::string &getValueOfAccountName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getAccountName() const noexcept;
    ///Set the value of the column Account_name
    void setAccountName(const std::string &pAccountName) noexcept;
    void setAccountName(std::string &&pAccountName) noexcept;

    /**  For column Contract_Language  */
    ///Get the value of the column Contract_Language, returns the default value if the column is null
    const std::string &getValueOfContractLanguage() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getContractLanguage() const noexcept;
    ///Set the value of the column Contract_Language
    void setContractLanguage(const std::string &pContractLanguage) noexcept;
    void setContractLanguage(std::string &&pContractLanguage) noexcept;

    /**  For column Country  */
    ///Get the value of the column Country, returns the default value if the column is null
    const std::string &getValueOfCountry() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getCountry() const noexcept;
    ///Set the value of the column Country
    void setCountry(const std::string &pCountry) noexcept;
    void setCountry(std::string &&pCountry) noexcept;

    /**  For column CLIENT_Manager  */
    ///Get the value of the column CLIENT_Manager, returns the default value if the column is null
    const std::string &getValueOfClientManager() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getClientManager() const noexcept;
    ///Set the value of the column CLIENT_Manager
    void setClientManager(const std::string &pClientManager) noexcept;
    void setClientManager(std::string &&pClientManager) noexcept;
    void setClientManagerToNull() noexcept;

    /**  For column Client_Nature  */
    ///Get the value of the column Client_Nature, returns the default value if the column is null
    const std::string &getValueOfClientNature() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getClientNature() const noexcept;
    ///Set the value of the column Client_Nature
    void setClientNature(const std::string &pClientNature) noexcept;
    void setClientNature(std::string &&pClientNature) noexcept;
    void setClientNatureToNull() noexcept;

    /**  For column Client  */
    ///Get the value of the column Client, returns the default value if the column is null
    const std::string &getValueOfClient() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getClient() const noexcept;
    ///Set the value of the column Client
    void setClient(const std::string &pClient) noexcept;
    void setClient(std::string &&pClient) noexcept;

    /**  For column Relationship_Type  */
    ///Get the value of the column Relationship_Type, returns the default value if the column is null
    const std::string &getValueOfRelationshipType() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getRelationshipType() const noexcept;
    ///Set the value of the column Relationship_Type
    void setRelationshipType(const std::string &pRelationshipType) noexcept;
    void setRelationshipType(std::string &&pRelationshipType) noexcept;

    /**  For column Client_Date_Opening  */
    ///Get the value of the column Client_Date_Opening, returns the default value if the column is null
    const ::trantor::Date &getValueOfClientDateOpening() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getClientDateOpening() const noexcept;
    ///Set the value of the column Client_Date_Opening
    void setClientDateOpening(const ::trantor::Date &pClientDateOpening) noexcept;

    /**  For column Client_Date_Modifying  */
    ///Get the value of the column Client_Date_Modifying, returns the default value if the column is null
    const ::trantor::Date &getValueOfClientDateModifying() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getClientDateModifying() const noexcept;
    ///Set the value of the column Client_Date_Modifying
    void setClientDateModifying(const ::trantor::Date &pClientDateModifying) noexcept;

    /**  For column Status  */
    ///Get the value of the column Status, returns the default value if the column is null
    const int8_t &getValueOfStatus() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int8_t> &getStatus() const noexcept;
    ///Set the value of the column Status
    void setStatus(const int8_t &pStatus) noexcept;


    static size_t getColumnNumber() noexcept {  return 12;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<Client>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Client>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> clientId_;
    std::shared_ptr<std::string> name_;
    std::shared_ptr<std::string> accountName_;
    std::shared_ptr<std::string> contractLanguage_;
    std::shared_ptr<std::string> country_;
    std::shared_ptr<std::string> clientManager_;
    std::shared_ptr<std::string> clientNature_;
    std::shared_ptr<std::string> client_;
    std::shared_ptr<std::string> relationshipType_;
    std::shared_ptr<::trantor::Date> clientDateOpening_;
    std::shared_ptr<::trantor::Date> clientDateModifying_;
    std::shared_ptr<int8_t> status_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[12]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where Client_Id = ?";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where Client_Id = ?";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "Client_Id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "Name,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "Account_name,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "Contract_Language,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "Country,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "CLIENT_Manager,";
            ++parametersCount;
        }
        if(dirtyFlag_[6])
        {
            sql += "Client_Nature,";
            ++parametersCount;
        }
        if(dirtyFlag_[7])
        {
            sql += "Client,";
            ++parametersCount;
        }
        if(dirtyFlag_[8])
        {
            sql += "Relationship_Type,";
            ++parametersCount;
        }
        if(dirtyFlag_[9])
        {
            sql += "Client_Date_Opening,";
            ++parametersCount;
        }
        if(dirtyFlag_[10])
        {
            sql += "Client_Date_Modifying,";
            ++parametersCount;
        }
        if(dirtyFlag_[11])
        {
            sql += "Status,";
            ++parametersCount;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        sql +="default,";
        if(dirtyFlag_[1])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[2])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[3])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[4])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[5])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[6])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[7])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[8])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[9])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[10])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[11])
        {
            sql.append("?,");

        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        sql.append(1, ')');
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace cim_web
} // namespace drogon_model



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

class Portfolio
{
  public:
    struct Cols
    {
        static const std::string _porfolio_id;
        static const std::string _porfolio_name;
        static const std::string _date_Creation;
        static const std::string _open_closed;
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
    explicit Portfolio(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Portfolio(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Portfolio(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Portfolio() = default;

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

    /**  For column porfolio_id  */
    ///Get the value of the column porfolio_id, returns the default value if the column is null
    const int32_t &getValueOfPorfolioId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getPorfolioId() const noexcept;
    ///Set the value of the column porfolio_id
    void setPorfolioId(const int32_t &pPorfolioId) noexcept;

    /**  For column porfolio_name  */
    ///Get the value of the column porfolio_name, returns the default value if the column is null
    const std::string &getValueOfPorfolioName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getPorfolioName() const noexcept;
    ///Set the value of the column porfolio_name
    void setPorfolioName(const std::string &pPorfolioName) noexcept;
    void setPorfolioName(std::string &&pPorfolioName) noexcept;

    /**  For column date_Creation  */
    ///Get the value of the column date_Creation, returns the default value if the column is null
    const ::trantor::Date &getValueOfDateCreation() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getDateCreation() const noexcept;
    ///Set the value of the column date_Creation
    void setDateCreation(const ::trantor::Date &pDateCreation) noexcept;
    void setDateCreationToNull() noexcept;

    /**  For column open_closed  */
    ///Get the value of the column open_closed, returns the default value if the column is null
    const int32_t &getValueOfOpenClosed() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getOpenClosed() const noexcept;
    ///Set the value of the column open_closed
    void setOpenClosed(const int32_t &pOpenClosed) noexcept;
    void setOpenClosedToNull() noexcept;


    static size_t getColumnNumber() noexcept {  return 4;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<Portfolio>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Portfolio>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> porfolioId_;
    std::shared_ptr<std::string> porfolioName_;
    std::shared_ptr<::trantor::Date> dateCreation_;
    std::shared_ptr<int32_t> openClosed_;
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
    bool dirtyFlag_[4]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where porfolio_id = ?";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where porfolio_id = ?";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "porfolio_id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "porfolio_name,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "date_Creation,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "open_closed,";
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
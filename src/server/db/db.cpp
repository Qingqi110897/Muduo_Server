#include"db.hpp"
#include<muduo/base/Logging.h>

// 数据库配置信息
static string server ="127.0.0.1";
static string user ="root";
static string password ="123456";
static string dbname="chat";

MySQL::MySQL()
{
    //只是相当于开辟一片空间不进行真正的连接
    _conn=mysql_init(nullptr);
}

// 释放数据库连接资源
MySQL::~MySQL()
{
    if (_conn != nullptr)
        mysql_close(_conn);
}

//连接数据库
bool MySQL::connect()
{
    MYSQL *p = mysql_real_connect(_conn, server.c_str(), user.c_str(),
                                  password.c_str(), dbname.c_str(), 3306, nullptr, 0);
    if(p!=nullptr)
    {
         // C和C++代码默认的编码字符是ASCII，如果不设置，从MySQL上拉下来的中文显示？
         mysql_query(_conn, "set names gbk");
         LOG_INFO << "connect mysql success!";
         return true;
    }
    else
    {
        LOG_INFO << "connect mysql fail!";
        return false;
    }

}

bool MySQL::update(string sql)
{
    //mysql_query() 函数的返回值 为 0 时表示成功，非零时表示失败
    if(mysql_query(_conn,sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":"
                 << sql << "更新失败!";
        return false;
    }

    return true;
}

MYSQL_RES *MySQL::query(string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":"
                 << sql << "查询失败!";
        return nullptr;
    }
    
    return mysql_use_result(_conn);
}

//获取连接
MYSQL*MySQL::getConnection()
{
    return _conn;
}
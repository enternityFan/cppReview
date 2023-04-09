/*
@Project ：cppReview 
@File ：connectMysqlLogin.c
@Author ：HuntingGame
@Date ：2023-04-04 9:33 
C'est la vie!!! enjoy ur day :D
*/

/*
 * 这个用来实现一个sql验证登录的代码
 * 在testcpp数据库中有一个名为user的table，用来存放登录人员的账户密码等；
 */




#include<iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "mysql/mysql.h"
using namespace std;



class workerManager
{
public:
    workerManager();
    ~workerManager();
    //和数据库有关的操作
    void insertData(const char* sqlstr);
    void queryData(const char* sqlstr);
    //和业务有关的操作
    void display();//TODO 懒得写了忽然

private:
    const char *host = "127.0.0.1";
    const char *user = "root";
    const char *upwd = "123456";
    const char *dbs = "testcpp";
    unsigned int port = 3306;
    MYSQL mysql;


};
workerManager::workerManager() {
    // 初始化mysql库
    if(0==mysql_library_init(0,NULL,NULL)){
        cout<<"mysql_library_init() successed!!"<<endl;
    }else{
        cout<<"mysql_library_init() failed!!"<<endl;

    }
    //初始化数据结构
    if(NULL != mysql_init(&mysql)){
        cout<<"init success!"<<endl;
    }else{
        cout<<"init failed!"<<endl;

    }
    //设置数据库的编码类型
    if(0==mysql_options(&mysql,MYSQL_SET_CHARSET_NAME,"utf8")){
        cout<<"setting database encode success!"<<endl;
    }else{
        cout<<"setting database encode failed!"<<endl;

    }
    //连接数据库
    if(NULL != mysql_real_connect(&mysql,host,user,upwd,dbs,port,NULL,0)){
        cout<<"database connect success"<<endl;
    }else{
        cout<<"database connect failed!"<<endl;
    }


}
workerManager::~workerManager() {
    mysql_close(&mysql);
    mysql_library_end();
}
void workerManager::insertData(const char* sqlstr){
    if(0==mysql_query(&mysql,sqlstr)){
        cout<<"insert success!"<<endl;
    }else{
        cout<<"insert failed"<<endl;
    }

}
void workerManager::queryData(const char* sqlstr){
    MYSQL_RES *result=NULL;
    if(0==mysql_query(&mysql,sqlstr)){
        cout<<"query success!"<<endl;

        //一次性取得数据集
        result =mysql_store_result(&mysql);

        //取得并打印行数
        my_ulonglong rowcount = mysql_num_rows(result);
        cout << "row count: " << rowcount << endl;

        //取得并打印各字段的名称
        unsigned int fieldcount = mysql_num_fields(result);
        MYSQL_FIELD *field = NULL;

        for (unsigned int i = 0; i < fieldcount; i++) {
            field = mysql_fetch_field_direct(result, i);
            cout << field->name << "\t\t";
        }
        cout << endl;

        //打印各行
        MYSQL_ROW row = NULL;
        row = mysql_fetch_row(result);
        while (NULL != row) {
            for (int i = 0; i < fieldcount; i++) {
                cout << row[i] << "\t\t";
            }
            cout << endl;
            row = mysql_fetch_row(result);
        }


    }else{
        cout << "mysql_query() select data failed" << endl;
        mysql_close(&mysql);

    }
}

void workerManager::display() {
    ;

}


int main() {
    workerManager wm;
    string querystr = "select * from user;";
    string insertstr = "insert into user values('123','123');";
    wm.queryData(querystr.c_str());
    wm.insertData(insertstr.c_str());
    wm.queryData(querystr.c_str());

    return 0;
}

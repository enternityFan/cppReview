/*
@Project ��cppReview 
@File ��connectMysqlLogin.c
@Author ��HuntingGame
@Date ��2023-04-04 9:33 
C'est la vie!!! enjoy ur day :D
*/

/*
 * �������ʵ��һ��sql��֤��¼�Ĵ���
 * ��testcpp���ݿ�����һ����Ϊuser��table��������ŵ�¼��Ա���˻�����ȣ�
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
    //�����ݿ��йصĲ���
    void insertData(const char* sqlstr);
    void queryData(const char* sqlstr);
    //��ҵ���йصĲ���
    void display();//TODO ����д�˺�Ȼ

private:
    const char *host = "127.0.0.1";
    const char *user = "root";
    const char *upwd = "123456";
    const char *dbs = "testcpp";
    unsigned int port = 3306;
    MYSQL mysql;


};
workerManager::workerManager() {
    // ��ʼ��mysql��
    if(0==mysql_library_init(0,NULL,NULL)){
        cout<<"mysql_library_init() successed!!"<<endl;
    }else{
        cout<<"mysql_library_init() failed!!"<<endl;

    }
    //��ʼ�����ݽṹ
    if(NULL != mysql_init(&mysql)){
        cout<<"init success!"<<endl;
    }else{
        cout<<"init failed!"<<endl;

    }
    //�������ݿ�ı�������
    if(0==mysql_options(&mysql,MYSQL_SET_CHARSET_NAME,"utf8")){
        cout<<"setting database encode success!"<<endl;
    }else{
        cout<<"setting database encode failed!"<<endl;

    }
    //�������ݿ�
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

        //һ����ȡ�����ݼ�
        result =mysql_store_result(&mysql);

        //ȡ�ò���ӡ����
        my_ulonglong rowcount = mysql_num_rows(result);
        cout << "row count: " << rowcount << endl;

        //ȡ�ò���ӡ���ֶε�����
        unsigned int fieldcount = mysql_num_fields(result);
        MYSQL_FIELD *field = NULL;

        for (unsigned int i = 0; i < fieldcount; i++) {
            field = mysql_fetch_field_direct(result, i);
            cout << field->name << "\t\t";
        }
        cout << endl;

        //��ӡ����
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

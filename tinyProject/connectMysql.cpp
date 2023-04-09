/*
@Project ��cppReview 
@File ��connectMysql.c
@Author ��HuntingGame
@Date ��2023-04-04 8:10 
C'est la vie!!! enjoy ur day :D
*/

/*
 * �����������ʵ������mysql
 * https://blog.csdn.net/winter2121/article/details/103333986
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "mysql/mysql.h"
using namespace std;

int main(){

    const char *host = "127.0.0.1";
    const char *user = "root";
    const char *upwd = "123456";
    const char *dbs = "testcpp";
    unsigned int port = 3306;


    MYSQL mydata;

    if(0==mysql_library_init(0,NULL,NULL)){
        cout<<"mysql_library_init() successed!!"<<endl;
    }else{
        cout<<"mysql_library_init() failed!!"<<endl;
        return -1;
    }

    //��ʼ�����ݽṹ
    if(NULL != mysql_init(&mydata)){
        cout<<"init success!"<<endl;
    }else{
        cout<<"init failed!"<<endl;
        return -1;
    }

    //�������ݿ��������
    if(0==mysql_options(&mydata,MYSQL_SET_CHARSET_NAME,"utf8")){
        cout<<"setting database encode success!"<<endl;
    }else{
        cout<<"setting database encode failed!"<<endl;
        return -1;
    }

    //�������ݿ�
    if(NULL != mysql_real_connect(&mydata,host,user,upwd,dbs,port,NULL,0)){
        cout<<"database connect success"<<endl;
    }else{
        cout<<"database connect failed!"<<endl;
        return -1;
    }

    //��������
    string sqlstr;
    sqlstr="INSERT INTO tb_user VALUES (5, 'tom',8,'1');";
    if(0==mysql_query(&mydata,sqlstr.c_str())){
        cout<<"insert success!"<<endl;
    }else{
        cout<<"insert failed"<<endl;
    }

    string sqlstr_select = " select * from tb_user;";
    //��ʾ��ѯ���
    MYSQL_RES *result=NULL;
    if(0==mysql_query(&mydata,sqlstr_select.c_str())){
        cout<<"query success!"<<endl;

        //һ����ȡ�����ݼ�
        result =mysql_store_result(&mydata);

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
        mysql_close(&mydata);
        return -1;
    }




    mysql_close(&mydata);
    mysql_library_end();
    return 0;
}
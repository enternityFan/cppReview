/*
@Project ：cppReview 
@File ：learningJson.c
@Author ：HuntingGame
@Date ：2023-04-03 11:07 
C'est la vie!!! enjoy ur day :D
*/

#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include <json/value.h>
#include <json/json.h>

using namespace Json;	// jsoncpp的命名空间
using namespace std;

void readJson()
{
    // 1. 将磁盘文件数据读出 -> string
    ifstream ifs("test2.json");
    Reader rd;
    Value root;
    rd.parse(ifs,root);

    // 3 打印输出
    // 遍历数组
    for (int i=0;i<root.size();++i){
        Value sub = root[i];
        if (sub.isInt() )
            cout << sub.asInt() << " " << endl;
        else if (sub.isDouble())
            cout << sub.asDouble() << " " << endl;
        else if (sub.isString())
            cout << sub.asString() << " " << endl;
        else if (sub.isBool())
            cout << sub.asBool() << " " << endl;
        else if (sub.isArray())
        {
            for (int j=0;j<sub.size();++j){
                cout << sub[j].asString() << " ";
            }
            cout << endl;

        }
        else if (sub.isObject()) {
            cout << sub["name"].asString() << " " << sub["age"].asInt() << " " << endl;
        }
    }
    ifs.close();

}

int main()
{
    // 组织数据, 并写入到磁盘文件
    // [12, 19.8, true, "hello", ["a", "b", "c"], {"name":"xiaoming"}, "age":12]
    Value root = Value(arrayValue);
    root.append(12);
    root.append(19.8);
    root.append(true);
    Value arr = Value(arrayValue);
    arr.append("a");
    arr.append("b");
    arr.append("v");
    root.append(arr);
    Value redirect;
    redirect["name"] = "xiaoming";
    redirect["age"] = 12;
    root.append(redirect);

    string st = root.toStyledString();
    cout << "v style:" << st << endl;
    ofstream ofs("test2.json");
    ofs << st;
    ofs.close();
    readJson();



    return 0;

}
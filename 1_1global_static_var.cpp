//
// Created by 14064 on 2022-12-16.
//
#include <iostream>

using namespace std;
//ȫ�ֱ���
int g_a = 10;
int g_b = 10;

//ȫ�ֳ���
const int c_g_a = 10;
const int c_g_b = 10;

int main() {

    //�ֲ�����
    int a = 10;
    int b = 10;

    //��ӡ��ַ
    cout << "�ֲ�����a��ַΪ�� " << (long long)&a << endl;
    cout << "�ֲ�����b��ַΪ�� " << (long long)&b << endl;

    cout << "ȫ�ֱ���g_a��ַΪ�� " <<  (long long)&g_a << endl;
    cout << "ȫ�ֱ���g_b��ַΪ�� " <<  (long long)&g_b << endl;

    //��̬����
    static int s_a = 10;
    static int s_b = 10;

    cout << "��̬����s_a��ַΪ�� " << (long long)&s_a << endl;
    cout << "��̬����s_b��ַΪ�� " << (long long)&s_b << endl;

    cout << "�ַ���������ַΪ�� " << (long long)&"hello world" << endl;
    cout << "�ַ���������ַΪ�� " << (long long)&"hello world1" << endl;

    cout << "ȫ�ֳ���c_g_a��ַΪ�� " << (long long)&c_g_a << endl;
    cout << "ȫ�ֳ���c_g_b��ַΪ�� " << (long long)&c_g_b << endl;

    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "�ֲ�����c_l_a��ַΪ�� " << (long long)&c_l_a << endl;
    cout << "�ֲ�����c_l_b��ַΪ�� " << (long long)&c_l_b << endl;

    system("pause");

    return 0;
}
/*
@Project ��cppReview 
@File ��Logger.c
@Author ��HuntingGame
@Date ��2023-04-15 10:01 
C'est la vie!!! enjoy ur day :D
*/

#include"Logger.h"
#include<stdexcept>
#include<iostream>
#include<stdarg.h>
#include<string.h>
#include<time.h>
#include<mutex>
using namespace Sakura::Logger;

Logger * Logger::m_instance=nullptr;
const char * Logger::m_Level[LEVEL_COUNT]={
        "DEBUG",
        "INFO",
        "WARN",
        "ERRO",
        "FATAL"
};

Logger::Logger() : m_len(0),m_max(0),levels(DEBUG)
{

}

Logger::~Logger()
{
    close();
}

//�򿪲�������־�ļ�
void Logger::open(const std::string &fileName)
{
    m_fileName=fileName;
    m_fout.open(fileName,std::ios::app);
    if(m_fout.fail())
    {
        throw std::logic_error("open file failed "+fileName);
    }
    //����־�ļ���ʼ�������
    m_fout.seekp(0,std::ios::end);
    //��ȡ����ǰ�ļ���������λ��
    m_len=m_fout.tellp();
}
//�ر��ļ�
void Logger::close()
{
    m_fout.close();
}
//����Logger����
Logger *Logger::getInstance()
{
    if(m_instance==nullptr)
    {
        std::mutex mtx;
        mtx.lock();
        m_instance=new Logger();
        mtx.unlock();
    }
    return m_instance;
}

/**
 * @brief:��ӡ��־
 * @param:����һ:��־���𣬲���������ӡ��־�ĵ��ļ���������������ӡ��־���ڵ��кţ�������:��ӡ��ʽ,����5:C++�еĲ�������
*/
void Logger::log(Level level,const char *fileName,int line,const char *format,...)
{
    //���˵ͼ�����־
    if(levels>level)
    {
        return;
    }
    if (m_fout.fail())
    {
        throw std::logic_error("open file failed "+m_fileName);
    }
    //��ȡ��ǰʱ���
    auto timeTicks=time(nullptr);
    //����ǰʱ���ת��Ϊʱ��ṹ��
    auto ptns=localtime(&timeTicks);
    //�洢��ʽ�����ʱ��
    char timeArray[32];
    //��ʼ���ַ�����
    memset(timeArray,0,sizeof(timeArray));
    //��ʽ��ʱ��ṹ��
    strftime(timeArray,sizeof(timeArray),"[%Y-%m-%d %H:%M:%S]",ptns);

    //��־��ʽ���Ľ��(���� ��־���� ��־��ӡλ��:��־��ӡ���к�λ��)
    const char *fmt="%s %s %s:%d ";
    //��ȡ��ʽ������ַ�������
    int size=snprintf(nullptr,0,fmt,timeArray,m_Level[level],fileName,line);
    if(size>0)
    {
        char *buffer=new char[size+1];
        memset(buffer,0,size+1);
        snprintf(buffer,size+1,fmt,timeArray,m_Level[level],fileName,line);
        std::cout<<buffer<<std::endl;
        //���ַ���д����־��
        m_fout<<buffer;
        m_len+=size;
        delete []buffer;
    }

    //��ȡд����־����
    va_list arg_ptr;
    va_start(arg_ptr,format);
    size=vsnprintf(nullptr,0,format,arg_ptr);
    va_end(arg_ptr);
    if(size>0)
    {
        char *content=new char[size+1];
        va_start(arg_ptr,format);
        vsnprintf(content,size+1,format,arg_ptr);
        va_end(arg_ptr);
        std::cout<<content<<std::endl;
        m_fout<<content;
        m_len+=size;
        delete []content;
    }
    m_fout<<"\n";
    //ˢ���ļ�����
    m_fout.flush();

    if(m_len>=m_max && m_max>0)
    {
        rotate();
    }

    //std::cout<<timeArray<<std::endl;
}

//��־����
void Logger::rotate()
{
    close();
    //��ȡ��ǰʱ���
    auto timeTicks=time(nullptr);
    //����ǰʱ���ת��Ϊʱ��ṹ��
    auto ptns=localtime(&timeTicks);
    //�洢��ʽ�����ʱ��
    char timeArray[32];
    //��ʼ���ַ�����
    memset(timeArray,0,sizeof(timeArray));
    //��ʽ��ʱ��ṹ��
    strftime(timeArray,sizeof(timeArray),".%Y-%m-%d_%H-%M-%S",ptns);
    std::string fileName=m_fileName+timeArray;
    if(rename(m_fileName.c_str(),fileName.c_str())!=0)
    {
        return;
    }
    open(m_fileName);
}


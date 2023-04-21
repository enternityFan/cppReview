/*
@Project ��cppReview 
@File ��Logger.c
@Author ��HuntingGame
@Date ��2023-04-15 10:01 
C'est la vie!!! enjoy ur day :D
*/

#ifndef LOGGER_H
#define LOGGER_H

#include<string>
#include<fstream>

namespace Sakura
{
    namespace Logger{

#define debug(format,...) \
    Logger::getInstance()->log(Logger::DEBUG,__FILE__,__LINE__,format,##__VA_ARGS__);

#define info(format,...) \
    Logger::getInstance()->log(Logger::INFO,__FILE__,__LINE__,format,##__VA_ARGS__);

#define warn(format,...) \
    Logger::getInstance()->log(Logger::WARN,__FILE__,__LINE__,format,##__VA_ARGS__);

#define erro(format,...) \
    Logger::getInstance()->log(Logger::ERRO,__FILE__,__LINE__,format,##__VA_ARGS__);

#define fatal(format,...) \
    Logger::getInstance()->log(Logger::FATAL,__FILE__,__LINE__,format,##__VA_ARGS__);


        class Logger{

        public:
            //��־����
            enum Level
            {
                DEBUG=0,
                INFO,
                WARN,
                ERRO,
                FATAL,
                LEVEL_COUNT  //��¼��־�������
            };

            //�򿪲�������־�ļ�
            void open(const std::string &fileName);
            //�ر��ļ�
            void close();
            //����Logger����
            static Logger *getInstance();
            //��ӡ��־
            void log(Level level,const char *fileName,int line,const char *format,...);
            //������־����
            void setLevel(Level level)
            {
                levels=level;
            }
            //������־�ļ�����ֽڳ���
            void setMax(int bytes)
            {
                m_max=bytes;
            }
            //��־����
            void rotate();

        private:
            Logger();
            ~Logger();

        private:
            //������־�ļ�����λ��
            std::string m_fileName;
            //�ļ����������
            std::fstream m_fout;
            //�����־����
            static const char *m_Level[LEVEL_COUNT];
            //��������
            static Logger*m_instance;
            //��ǰ��־����(���ڹ��˵ͼ�����־����)
            Level levels;
            //��־�ļ���ŵ�����ֽ�������
            int m_max;
            //��־�ļ���ǰ�ֽ�������
            int m_len;
        };
    }
}
#endif //LOGGER_H

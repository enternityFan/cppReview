#define WINDOWS 0
#if (WINDOWS == 1)
#include "windows.h"
#include "winsock.h"
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#endif
#include<iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAXLINE 80
#define SERV_PORT 6666

using namespace std;







int main() {
    sockaddr_in servaddr,cliaddr;
    socklen_t cliaddr_len;
    string buf;
    string str;
    int i,n;
    // 1.�����׽���

    int listenfd,connfd;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    // 2.bind�׽���
    bind(listenfd,(sockaddr *)&servaddr,sizeof(servaddr));

    // 3.�����׽���
    listen(listenfd,20);
    cout <<"accept !" << endl;
    while(1){
        cliaddr_len = sizeof(cliaddr);
        // 4.�����µ��ļ���������ͻ��˽���ͨ��
        connfd = accept(listenfd,(sockaddr *)&cliaddr,&cliaddr_len);
        n = read(connfd,buf,MAXLINE);



    }







    //system("pause");
    return 0;
}

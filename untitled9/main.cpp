#include "mainwindow.h"
#include <QApplication>
#include <arpa/inet.h>
#include <iostream>
using namespace std;
#include "csocket.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


//    struct in_addr addr;
//    addr.s_addr=inet_addr("192.168.1.1");


//   int fd=   StartTcpServerSock(6789,1000,1000);
//   int cl_fd=WaitTcpConnect(fd,1000,NULL,NULL);
//   char buf[30];
//   memset(buf,0,30);
//   while(1){
//   RecvDataByTcp(cl_fd,buf,3);
//   cout<<buf<<endl;
//   SendDataByTcp(cl_fd,buf,3);
//   }
    return a.exec();
}

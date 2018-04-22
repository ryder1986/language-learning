#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <thread>
#include <functional>
#include <sys/ioctl.h>
using namespace std;
#include "csocket.h"
class Session{
    public:
    Session(int fd)
    {
        skt=fd;
        int ul = 0;
        ioctl(fd, FIONBIO, &ul); //设置为阻塞模式
//        auto func_send=bind(&Session::send,this);
//        std::thread([func_send](){
//           // std::this_thread::sleep_for(std::chrono::milliseconds(after));
//            func_send();
//        }).detach();
         cout<<"new connection"<<endl;
        auto func_recv=bind(&Session::recv,this);
        std::thread([func_recv](){
           // std::this_thread::sleep_for(std::chrono::milliseconds(after));
            func_recv();
        }).detach();
    }
    int send(char *buf,int len)
    {
         int ret= SendDataByTcp(skt,buf,len);
         if(ret){
              cout<<"send  "<<ret<<" bytes"<<endl;
         }else{
              cout<<"send  fail"<<endl;
         }
//        while(1){
//            this_thread::sleep_for(chrono::seconds(1));
//        }
    }
    int recv()
    {
        while(1){
          int ret=RecvDataByTcp(skt,buf,1000);
          if(ret){
             cout<<"read  "<<ret<<" bytes"<<endl;
          }else{
                cout<<"ret  "<<ret<<endl;
                  cout<<"socket maybe closed,retry read after 1sec"  <<endl;
                  this_thread::sleep_for(chrono::seconds(1));
          }
        }
    }

private:
    int skt;
    char buf[1000];
};

class Tcpserver{
public:
    Tcpserver(int p):port(p)
    {
        fd= StartTcpServerSock(port,1000,1000);
        auto func=bind(&Tcpserver::listen,this);

        std::thread([func](){
           // std::this_thread::sleep_for(std::chrono::milliseconds(after));
            func();
        }).detach();
    }

    void listen()
    {
        while(1){
            cout<<"listening again"<<endl;
           int cl_fd=WaitTcpConnect(fd,1,NULL,NULL);
            if(cl_fd>0){
                Session *s=new Session(cl_fd);
                clients.push_back(s);
            }

        }
    }
    void send_test()
    {
        if(clients.size())
        {
            clients[0]->send("123456",6);
        }
    }

private:
    int port;
    int fd;
    vector <Session *> clients;
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
        Tcpserver server;
};

#endif // MAINWINDOW_H

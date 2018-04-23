#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <thread>
#include <functional>
#include <sys/ioctl.h>
using namespace std;
#include "csocket.h"
#define BUF_SIZE 10
class Session{
public:
    Session(int fd,string ip,int port):quit(false),client_ip(ip),
        client_port(port)
    {
        skt=fd;
        int ul = 0;
        ioctl(fd, FIONBIO, &ul);
        cout<<"new connection"<<endl;
        auto func_recv=bind(&Session::recv,this);

        trd=new thread([func_recv](){func_recv();});
    }
    ~Session()
    {
         cout<<"session deleteing "<<ip()<<endl;
        quit=true;
        trd->join();
        delete trd;

    }

    int send(char *buf,int len)
    {
        int ret= SendDataByTcp(skt,buf,len);
        if(ret){
            cout<<"send  "<<ret<<" bytes"<<endl;
        }else{
            cout<<"send  fail"<<endl;
        }
    }
    int recv()
    {
        while(!quit){
            int ret=RecvDataByTcp1(skt,buf,BUF_SIZE);
            if(ret){
                cout<<"read  "<<ret<<" bytes"<<endl;
            }else{
                cout<<"ret  "<<ret<<endl;
                break;
                cout<<"socket maybe closed,retry read after 1sec"  <<endl;
                this_thread::sleep_for(chrono::seconds(1));
            }

        }
        end_this(this);
    }
    string ip()
    {
        return client_ip;
    }
    int port()
    {
        return client_port;
    }


private:
    int skt;
    bool quit;
    char buf[BUF_SIZE];
    std::thread *trd;
    string client_ip;
    int client_port;
public:
    function <void(Session *)> end_this=[](Session *){ cout<<"we  can quit now"<<endl;};

};
#define IP_STR_LEN 20
#include <cstring>
#include <algorithm>
class Tcpserver{
public:
    Tcpserver(int p):port(p),quit(false)
    {
        fd= StartTcpServerSock(port,1000,1000);
        auto func=bind(&Tcpserver::listen,this);
        trd=new thread([func](){func();});
    }
    ~Tcpserver()
    {
        quit=true;
        trd->join();
        int sz=clients.size();
        for(int i=sz-1;i>=0;i--)
        {
            delete clients[i];
            clients.pop_back();
        }
        delete trd;
    }

    void listen()
    {
        while(!quit){

            memset(peer_ip,0,IP_STR_LEN);
            int cl_fd=WaitTcpConnect(fd,1,peer_ip,&peer_port);
            if(cl_fd>0){
                cout<<"get connect from "<<peer_ip<<":"<<peer_port<<endl;
                Session *s=new Session(cl_fd,peer_ip,peer_port);
                s->end_this=bind(&Tcpserver::quit_session,this,placeholders::_1);
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
    void size()
    {
 cout<<clients.size();
    }
private:
    void quit_session(Session *s)
    {
      //  delete s;
        vector <Session *>::iterator e=find(clients.begin(),clients.end(),s);
      clients.erase(e);
        thread([s](){
        //   cout<<"try to delete "<<s->ip()<<endl;
           // this_thread::sleep_for(chrono::milliseconds(100));
            delete s;
 // cout<<"try to delete  "<<s->ip()<<"done"<<endl;
        }).detach();
//        cout<<"quiting"<<endl;
//        cout<<s->ip()<<endl;
   //     vector <Session *>::iterator e=find(clients.begin(),clients.end(),s);
//   //     delete s;
 //         clients.erase(e);
//        cout<<"done"<<endl;
    }

    bool quit;
    int port;
    std::thread *trd;
    unsigned short peer_port;
    int fd;
    vector <Session *> clients;
    char peer_ip[IP_STR_LEN];

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

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Tcpserver server;
};

#endif // MAINWINDOW_H

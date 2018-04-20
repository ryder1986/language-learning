#include <iostream>


////////////////////test.cpp
#include<iostream>
#include<string>
#include<memory>
//#include"Timer.hpp"
using namespace std;
void EchoFunc(std::string&& s){
    std::cout << "test : " << s << endl;
}
#include "test.h"
int main(){
    Test t;
#if 0
    Timer t1;
    Timer t2;
    Timer t3;
    Timer t4;
        //周期性执行定时任务
    t1.StartTimer(100, std::bind(EchoFunc,"f1!"));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "try to expire timer!" << std::endl;
 //   t.Expire();

    //周期性执行定时任务
    t2.StartTimer(100, std::bind(EchoFunc,  "f2!"));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "try to expire timer!" << std::endl;
   // t.Expire();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    //只执行一次定时任务
    //同步
    t3.SyncWait(1000, EchoFunc, "f3");
    //异步
    t4.AsyncWait(1000, EchoFunc, "f4");

    std::this_thread::sleep_for(std::chrono::seconds(1));
#endif
    while(1)
        ;
    return 0;
}

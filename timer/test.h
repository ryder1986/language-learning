#ifndef TEST_H
#define TEST_H
#include <thread>
#include <functional>
#include <iostream>
using namespace std;
class Timer1{
public:
    Timer1():quit(false)
    {

    }
    void start(int interval)
    {
function <void()> timed_func1=[]{  cout<<"2"<<endl;};
              //   function <void()> timed_func1;
     function <void()> timed_func2=timed_func;

        thread([this,interval,timed_func2]
        {
            while(!quit){
                try{
                //    timed_func();
                }catch(exception e){
                    cout<<"excption"<<endl;

                }
                cout<<"1"<<endl;
                this_thread::sleep_for(chrono::microseconds(interval));
            }
        }
        ).detach();
    }
    void stop()
    {
        quit=true;
    }

private:
    function <void()> timed_func=[]{cout<<"3"<<endl;
    bool quit;
};

class Test
{
public:
    Test();
};

#endif // TEST_H

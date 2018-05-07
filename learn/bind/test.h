#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <functional>
using namespace std;
class Member{
public:
    void fun(function <void(int) >ff)
    {
        ff(17);
    }
};

class Test
{
public:
    Test();
    void fun(int ss)
    {
        cout<<ss<<"fun in Test"<<endl;
        num=456;
    }
    int num;
};

#endif // TEST_H

#include "test.h"

Test::Test()
{
    num=123;
    Member m;
    auto f=bind(&Test::fun,this,placeholders::_1);
    m.fun(f);
    cout<<num<<endl;
}


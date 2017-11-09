#include <iostream>

using namespace std;
class father{
public:
  virtual  void test()
    {
         cout << "i am father!" << endl;
    }
};
class child:public father{
    public:
    void test()
    {
         cout << "i am child!" << endl;
    }
};
class childchild:public child{
    public:
    void test()
    {
         cout << "i am child child!" << endl;
    }
};

int main()
{
    father *f;//=new father();
    child *c=new child();
    childchild *cc=new childchild();

    child *c1;
    f=c;
    f->test();
    f=cc;
    cc->test();
    return 0;
}


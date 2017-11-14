#include <iostream>
using namespace std;
class test2{
public:
	test2(int x):c(x){};
	int c;
};
class test1{
public:
	test1(int p)
	{}
	test1(int p,char d)
	{}

	test1( )
	{}
// test1(){
//
//test2 tt(22);
//
// };
//	test1():x(13)
//	{}
int x;
//test2 ttt;
};
class test{

public:
	test():a(1),b('p'),ss(a),ppp(111)
	{//
//		test1 *t1;

	//	t1=new test1();
	//	cout<<t1.x<<endl;
	}
	int a;
	char b;

	 void fun() const
	{
			char c='o';

				cout<<b<<endl;


	}
private:

		typedef int index;
		index t;
		const int ppp;
		int &ss;
	 	test1 ttt;
};

int main()
{

	cout<<"test"<<endl;
	test t;
	//  test::index ss;
	t.fun();
}

#include <iostream>
using namespace std;


template <class T>
T show( T a)
{
	cout<<a<<"\n";
	return a;
}

int main()
{


	show(3.2);
	show(3);
	show(123123);
	show(123123123213123123);
	int rst=show(1.234);
	cout<<"rst:"<<rst;
	return 0;
}

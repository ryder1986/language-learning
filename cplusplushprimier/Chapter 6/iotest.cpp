
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream os;
	os.open("test.txt");
	char tt;
	os>>tt;
	//os.close();
	cout<<tt;


	while(os.good()){
		os>>tt;
		if(os.eof())
		{
			cout << "****";
		}
		cout<<tt;
	}

	if(os.eof())
	{
		cout << "****";
	}
	return 0;

}

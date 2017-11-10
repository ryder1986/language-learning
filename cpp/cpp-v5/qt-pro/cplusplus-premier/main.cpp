#include <iostream>
#include <vector>
int main()
{

	 using namespace std;
	 vector<int> arr(10);
	 arr[0]=5;
	 cout<<arr[0]<<endl;
	 vector<int>::iterator p;
	 p=arr.begin();
	 cout<<p.<<endl;
    // pass iterators to the first and one past the last element to print
//    void print(vector<int>::const_iterator beg,
//               vector<int>::const_iterator end)
//    {
//        while (beg != end) {
//            cout << *beg++;
//            if (beg != end) cout << " "; // no space after last element
//        }
//        cout << endl;
//    }

	return 0;


}

#include <iostream>
#include "test.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Test t;

    while(1){
        this_thread::sleep_for(chrono::microseconds(1000000));
       t.t1.test1++;
    }
    return 0;
}


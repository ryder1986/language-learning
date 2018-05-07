#include <iostream>
#include "tcpserver.h"
using namespace std;

int main()
{
    cout << " tcp server start !" << endl;
    Tcpserver s(12345);
    while(1)
        ;
    return 0;
}


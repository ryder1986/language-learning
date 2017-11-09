// waiting.cpp -- using clock() in a time-delay loop
#include <iostream>
#include <ctime> // describes clock() function, clock_t type
int main()
{
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;  // convert to clock ticks
    cout << "starting\a\n";
    clock_t start = clock();
    volatile  int i=9;
    volatile  int j=9;
    volatile  int k=9;
    volatile  int m=9;
    while (clock() - start < delay )        // wait until time elapses
    {
    	// note the semicolon
      	i++;
     	i++;
     	i++;
     	i++;
     	i++;
     	i++;
     	i++;
     	i++;
     	m=i+j;
            }
    cout << "done \a\n";
    // cin.get();
    // cin.get();
    return 0; 
}

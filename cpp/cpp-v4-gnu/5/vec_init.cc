/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Contracts Department
 * 	75 Arlington Street, Suite 300
 * 	Boston, MA 02216
 * 	Fax: (617) 848-7047
*/ 

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;


int main()
{
    
    vector<int> ivec;                // empty vector
    int cnt = 10;
    // add elements 10...1 to ivec
    while (cnt > 0)
        ivec.push_back(cnt--);        // int postfix decrement

    vector<int>::iterator iter = ivec.begin();
    // prints 10 9 8 ... 1 
    while (iter != ivec.end())
        cout << *iter++ << endl; // iterator postfix increment

// Alternative loop using comma operator in the for expression
{
    int cnt = ivec.size();
    // add elements from size...1 to ivec
    for(vector<int>::size_type ix = 0; 
                    ix != ivec.size(); ++ix, --cnt)   
        ivec[ix] = cnt;

    vector<int>::iterator iter = ivec.begin();
    // prints 10 9 8 ... 1 
    while (iter != ivec.end())
        cout << *iter++ << endl; // iterator postfix increment
}
    return 0;
}

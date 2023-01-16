
/*  C++ Vector begin(): This function is used to point the first element of the vector.

    begin() vs front()
    The begin() function is used to return an iterator pointing to the first element of the vector while front() function is used to return a reference to the same element in the vector container.

    Syntax: Consider a vector 'v' and syntax would be:

                    iterator it =v.begin();  


    Parameter:
    It does not contain any parameter.

    Return value:
    It returns an iterator pointing to the first element of the vector.
    
*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<char> v{'a','e','i','o','u'};  
    vector<char>::iterator itr;  
    
    itr=v.begin();  
    cout << *itr;  


    return 0;  
}  
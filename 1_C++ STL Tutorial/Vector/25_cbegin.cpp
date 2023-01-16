
/*  C++ Vector cbegin(): This function is used to point the first element of the vector container.


    cbegin() vs begin():
        + The cbegin() function returns the constant iterator while begin() function returns an iterator. 
        + The element pointed by the end() function can be modified but not by cend() function.



    Syntax: Consider a vector 'v'. Syntax would be:

                    const_iterator itr=v.cbegin();  


*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v{1,2,3,4,5};  
    vector<int>::const_iterator itr=v.cbegin()+2;  

    *itr = 6;  
    std::cout << *itr;  

    return 0;  
}  
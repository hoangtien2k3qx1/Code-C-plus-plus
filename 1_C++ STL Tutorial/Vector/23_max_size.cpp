
/*  C++ Vector max_size(): This function is used to provide the maximum size that vector can hold.

    Syntax: Consider a vector 'v' and maximum size 'm'. Syntax would be :

                 int m=v.max_size();  


    Parameter:
    It does not contain any parameter.

    Return value:
    It returns the maximum number of elements that vector can hold.



*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v{1,2,3,4,5};  
    
    std::cout<<v.max_size() <<std::endl;  


    return 0;  
}  
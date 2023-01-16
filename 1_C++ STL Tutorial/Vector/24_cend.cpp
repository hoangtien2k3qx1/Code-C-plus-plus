
/*  C++ Vector cend(): This function is used to point to the past-the-last element (element after the last element) in the vector.

    cend() vs end() difference:
        + The cend() function returns the constant iterator while end() function returns an iterator. 
        + The element pointed by the end() functioncan be modified but not by the cend() function.



    Syntax: Consider a vector 'v', Syntax would be:

            const_iterator itr=v.cend();  


    Parameter:
    It does not contain any parameter.

    Return value:
    It returns a constant iterator pointing to thepast-the-last element in the vector.

*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<char> v{'T','u','t','o','r','i','a','l'};  
    vector<char>::const_iterator citr;  

    for(citr=v.cbegin(); citr!=v.cend(); citr++)  
        std::cout<<*citr;  



    return 0;  
}  
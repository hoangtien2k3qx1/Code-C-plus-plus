
/* C++ Vector crbegin(): 

    + The crbegin() function stands for reverse beginning. 
    + It is used to point the last character of the vector container.
 

    crbegin() vs rbegin():
    The crbegin() function returns the constant reverse iterator while 
    rbegin() function returns the reverse iterator. The element pointed by the rbegin() function can be modified but not by crbegin() function.


    Syntax:
                const_reverse_iterator itr=v.crbegin();  

*/

#include <iostream>     
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string> v{"Mango","banana","strawberry","kiwi"};  
    vector<string>::const_reverse_iterator itr=v.crbegin();  

    cout << *itr;  


    return 0;  
}  
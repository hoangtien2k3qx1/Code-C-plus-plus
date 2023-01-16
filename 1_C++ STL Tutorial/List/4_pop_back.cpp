
/*  C++ List pop_back():

    C++ List pop_back() function removes the last element from the list and reduces 
    the size of the list by one.

    Syntax
                void  pop_back();  

    Parameter:
    It does not contain any parameter.

    Return value:
    It does not return any value.

*/

#include <iostream>  
#include<list>  
using namespace std;  
int main()  
{  
    list<int> li={6,7,8,9};  
    list<int>::iterator itr;  

    li.pop_back();  
    li.pop_back();  

    for(itr=li.begin();itr!=li.end();++itr)  
        cout<<*itr<<" ";  

    return 0;  
}  
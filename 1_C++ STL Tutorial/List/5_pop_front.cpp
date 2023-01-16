
/*  C++ List pop_front():

    C++ List pop_front() function removes the first element from the list and therefore, 
    reducing the size of the list by one.


    Syntax:
                    pop_front();  

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
    list<int> li={20,30,40,50};  

    li.pop_front();  
    list<int>::iterator itr;  

    for(itr=li.begin();itr!=li.end();++itr)  
        cout << *itr << " ";  


    return 0;  
}  
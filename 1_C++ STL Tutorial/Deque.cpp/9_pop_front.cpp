
/*  C++ Deque pop_front():

    C++ Deque pop_front() function removes the first element from the deque 
    and the size of the container is reduced by one

    Syntax:
                    pop_front();   

    Parameter:
    It does not contain any parameter.

    Return value:
    It does not return any value.

*/
#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> d={10, 20, 30, 40, 50};  
    deque<int>::iterator itr;  

    d.pop_front();  
    for(itr=d.begin();itr!=d.end();++itr)  
        cout<<*itr<<" ";

    return 0;  
}  
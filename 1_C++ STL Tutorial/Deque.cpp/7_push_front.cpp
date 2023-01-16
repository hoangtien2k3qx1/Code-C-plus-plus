
/*  C++ Deque push_front():

    C++ Deque push_front() function inserts new element in the beginning of the deque container 
    and the size of the container is increased by one.


    Syntax:
                    push_front(value_type val);   


    Parameter:
    val: New value to be added in the beginning.

    Return value:
    It does not return any value.

*/
#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> d={200,300,400,500};  
    deque<int>::iterator itr;  
    
    d.push_front(100);  
    for(itr=d.begin();itr!=d.end();++itr)  
        cout<<*itr<<" ";  

    return 0;  
}  
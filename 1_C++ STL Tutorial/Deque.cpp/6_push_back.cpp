
/*  C++ Deque push_back():

    C++ Deque push_back() function adds a new element at the end of the deque container 
    and the size of the container is increased by one.


    Syntax:
                push_back(value_type val);  


    Parameter:
    val: New value to be inserted at the end of the deque container.

    Return value
    It does not return any value.

*/
#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> d={10,20,30,40};  
    deque<int>::iterator itr;  
    
    d.push_back(50);  
    for(itr=d.begin(); itr!=d.end(); ++itr)  
        cout<<*itr<<" ";  

    return 0;  
}  
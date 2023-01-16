
/*  C++ Deque swap():

    C++ Deque swap() function exchanges the content of a given deque with 
    the deque passed in the parameter of same type.

    Conditions:
    Type of deque cannot be different.
    Size of deque can vary.

    Syntax:
                    swap(deque& second);  

    Parameter:
    second: It is an another deque container whose content is to be swapped with the given deque.

    Return value:
    It does not return any value.

*/

#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> first={1,2,3,4};  
    deque<int> second={10,20,30,40,50};  

    first.swap(second);  

    cout<<"Content of first deque:";  
    for(deque<int>::iterator itr=first.begin();itr!=first.end();++itr)  
        cout<<*itr<<" ";  

    cout<<'\n';  

    cout<<"Content of second deque:";  
    for(deque<int>::iterator itr=second.begin();itr!=second.end();++itr)  
        cout<<*itr<<" ";  


    return 0;  
}  
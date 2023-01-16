
/*  C++ Deque pop_back():

    C++ Deque pop_back() function removes the last element from the the deque container 
    and the size of the deque is reduced by one.

    Syntax:
                    pop_back(); 

    Parameter:
    It does not contain any parameter.

    Return value:
    It does not return any value.

*/
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> d={1,2,3,4,5};  
    deque<int>::iterator itr; 

    d.pop_back();  
    for(itr=d.begin();itr!=d.end();++itr)  
        cout<<*itr<<" "; 
         
    return 0;  
}  
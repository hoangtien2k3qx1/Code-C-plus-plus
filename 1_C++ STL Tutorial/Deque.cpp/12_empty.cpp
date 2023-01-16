
/*  C++ Deque empty():

    C++ Deque empty() function checks whether the container is empty or not. 
    If the container is empty, it returns 1 otherwise 0.

    Syntax:
                empty()  

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
    deque<int> first={5,6,7};  
    if(first.empty())  
        cout<<"Deque is empty";  
    else  
        cout<<"Deque is not empty";  
    return 0;  
}  
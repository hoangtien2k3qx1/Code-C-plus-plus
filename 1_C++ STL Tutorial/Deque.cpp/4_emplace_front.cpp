
/*  C++ Deque emplace_front():

    C++ Deque emplace_front() function adds a new element to the beginning of the deque container 
    and the size of the container is increased by one.


    Syntax:
                emplace_front(value_type val); 


    Parameter:
    val: New value is to be inserted at the beginning of the deque.

    Return value:
    It does not return any value.

*/
#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<string> fruit={"mango","banana"};  

    fruit.emplace_front("apple");  
    fruit.emplace_front("strawberry");  

    for(deque<string>::iterator itr=fruit.begin();itr!=fruit.end();++itr)  
        std::cout << *itr<<" "; 
         
    return 0;  
}  
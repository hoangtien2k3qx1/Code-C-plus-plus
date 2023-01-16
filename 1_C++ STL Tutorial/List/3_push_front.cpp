
/*  C++ List push_front():

    C++ List push_front() function adds a new element in the beginning of the list. 
    Therefore, increasing the size of the list by one.

    Syntax:
                push_front(const value_type& x);  


*/

#include <iostream>  
#include<list>  
using namespace std;  
int main()  
{  
    list<int> li={20,30,40,50};  

    li.push_front(10);  

    list<int>::iterator itr;  

    for(itr=li.begin();itr!=li.end();++itr)  
        cout<<*itr<<" "; 

    return 0;  
}  
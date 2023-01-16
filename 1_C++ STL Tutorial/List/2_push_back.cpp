
/*  C++ List push_back():

    C++ List push_back() inserts a new element at the end of the list and the size of 
    the list container increases by one.

    Syntax:
                push_back(const value_type& x);  

*/

#include <iostream>  
#include<list>  
using namespace std;  
  
int main()  
{  
    list<string> li={"C"," C++"," .Net"};  
    list<string>::iterator itr;  

    li.push_back(" java");  
    li.push_back(" PHP");  

    for(itr=li.begin();itr!=li.end();++itr)  
        cout<<*itr;  
        
    return 0;  
}  
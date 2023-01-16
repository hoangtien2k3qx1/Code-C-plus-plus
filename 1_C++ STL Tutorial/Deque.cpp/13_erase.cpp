
/*  C++ Deque erase():

    C++ Deque erase() function removes the element from the specified position 
    or range and this effectively reduces the size of the deque by the number of elements removed.

    Syntax:
            iterator erase(iterator pos);  

            iterator erase(iterator first, iterator last);  

*/
#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> d={1,2,3,4};  
    deque<int>::iterator itr;  

    cout<<"Content of deque:";  
    for(itr=d.begin();itr!=d.end();++itr)  
        cout<<*itr<<" ";  

    cout<<'\n';  

    d.erase(d.begin() + 1);
    
    cout<<"After erasing second and third element,Content of deque:"; 
    for(itr = d.begin(); itr != d.end(); ++itr) {
        cout << *itr << " ";
    }

    d.erase(d.begin()+1,d.begin()+3); 

    cout<<"\nAfter erasing second and third element,Content of deque:";  
    for(itr=d.begin();itr!=d.end();++itr)  
        cout<<*itr<<" ";  

    return 0;  
}  

/*  C++ Deque emplace(): 
    
    C++ Deque emplace() function inserts a new element just before the specified position and 
    the size of the container is increased by one.
    (Hàm này sẽ chèn một phần tử mới trước phần tử)


    Syntax:
                iterator emplace(const_iterator position, value_type val);   

    
    Parameter:
    position: It defines the position before which the new element is to be inserted.

    val: New value which is to be inserted.

    Return value:
    It returns an iterator to the newly constructed element.



*/

#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> deq={7, 8, 4, 5};  

    deque<int>::iterator itr;  

    deq.emplace(deq.begin(), 1);  
    
    for(itr=deq.begin(); itr!=deq.end(); ++itr)  
        std::cout << *itr <<" ";  
        
    return 0;  
}  


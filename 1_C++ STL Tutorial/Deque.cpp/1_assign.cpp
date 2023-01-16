
/*  C++ Deque assign():  It assigns new content and replacing the old one. // chỉ định ra một phần tử mới thay thế phần tử cũ
    
    + function assigns new contents to the deque container and the size of the container is modified 
    accordingly.

    Syntax:
                void assign(InputIterator first, InputIterator last);  
                void assign(int n, value_type val);   


    Parameter:
        (first,last): It defines the range between which the new elements to be inserted.

        n:  It defines the new size of the deque container.
        val:  New value to be inserted.


*/

// #include <iostream>  
// #include<deque>  
// using namespace std;  
// int main()  
// {  
//     deque<int> first = {1, 2, 3, 4};  
//     deque<int> second;  

//     second.assign(first.begin(), first.end());  

//     for(deque<int>::iterator itr = second.begin(); itr != second.end(); ++itr)  
//         std::cout << *itr << " ";  


//     return 0;  
// }  


#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> deq;  
    deque<int>::iterator itr;  

    deq.assign(5, 6);  
    for(itr=deq.begin(); itr!=deq.end(); ++itr)  
        std::cout << *itr <<" ";  

    return 0;  
}  
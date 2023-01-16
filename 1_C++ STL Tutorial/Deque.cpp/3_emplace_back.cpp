
/*  C++ emplace_back():

    C++ Deque emplace_back() function adds a new element at the end of the deque and the size of the container is increased by one.


    Syntax:
                emplace_back(value_type val); 

  
    Parameter:
    val: New value to be inserted at the end of the deque.

    Return value:
    It does not return any value


*/

#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<int> d={1, 2, 3, 4};  
 
    d.emplace_back(5);  
    for(deque<int>::iterator itr = d.begin(); itr!=d.end(); ++itr)  
        std::cout << *itr <<" ";  


    return 0;  
}  



// #include <iostream>  
// #include<deque>  
// using namespace std;  
// int main()  
// {  
//     deque<char> ch={'j','a','v'};  

//     ch.emplace_back('a');  
//     for(deque<char>::iterator itr = ch.begin(); itr!=ch.end(); ++itr)  
//         std::cout << *itr; 

//     return 0;  
// }  
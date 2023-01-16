
/*  C++ Vector crend(): This function is used to point the element preceding the first element in the vector container. Itrefers as reverse end.

    Syntax: 
                const_reverse_iterator itr=v.crend();  




*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string>str{"java","C","C++",".Net"};  
    vector<string>::const_reverse_iterator itr=str.crend()-1;  

    std::cout<< *itr;  


    
    return 0;  
}  
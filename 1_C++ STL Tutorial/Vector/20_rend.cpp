
/*  C++ Vector rend(): The rend() function stands for 'reverse end' and is used to point the element preceding the first element of the vector.

    # rend() : stand for " reverse end " ( đảo ngược chuỗi or mảng )

    Syntax:  Consider a vector 'v'. Syntax would be:

                    reverse_iterator ritr = v.rend();  



    Parameter:
    It does not contain any parameter.

    Return value:
    It returns a reverse iterator pointing to the reverse end of the vector container.


*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v{1,2,3,4,5};  

    vector<int>::reverse_iterator ritr;  

    for(ritr = v.rbegin(); ritr != v.rend(); ritr++)  
        std::cout<< *ritr<<" "; 


    return 0;  
}  


//! ////////////////////////////////////
#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string> v {"Computer science","electronics","electrical","mechanical"};  
    vector<string>::reverse_iterator ritr;  
    vector<string>::iterator itr;  

    std::cout<<"Strings are :";  
    for(itr=v.begin(); itr!=v.end(); itr++)  
        cout << *itr << ", ";  

    cout<<'\n';  

    cout<<"Reverse strings are :";  
    for(ritr=v.rbegin();ritr!=v.rend();ritr++)  
        cout << *ritr << ", ";  


    return 0;  
}  

/*  C++ Vector operator[]():    This function is used to access a specified element.
    ( hàm này dùng để truy cập đến các phần tử )

    !Syntax Consider a vector 'v' and position 'pos'. Syntax would be:

                v.operator[ ](pos);  



    Parameter
    pos: It defines the position of the element.

    Return value
    It returns the element of specified location.


*/

#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string> v{"C","C++","java"};  

    for(int i=0; i<v.size(); i++)  
        cout << v.operator[](i) << " ";  



    return 0;  
}  



///

#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v{1,2,3,4,5};
    
    for(int i=0; i<v.size(); i++)  
        cout << v.operator[](i) << " ";  


    return 0;  
}  
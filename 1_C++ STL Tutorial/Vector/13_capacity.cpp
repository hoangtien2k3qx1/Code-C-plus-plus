
/*  C++ Vector capacity() : sức chứa

    * this function detemines the curent capacity of the vector.
    ( hàm này sẽ quyết đinh xem sức chứa của vector )


    !Syntax: 
            v.capacity();

    
    Parameter:
        It does not contain any parameter.

    Return value:
        It returns the current allocated capacity of the vector.

*/

#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    
    vector<int> v {1, 2, 3, 4, 5};  
    
    int c = v.capacity();  
    cout << "Capacity of the vector is: " << c;  


    
    return 0;  
}  
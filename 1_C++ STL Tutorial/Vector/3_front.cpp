
/*  *C++ Vector front()
    # syntax front C++ :
            v.front();  


    * It gives a reference to the first element of vector.

    Parameter
    This function does not contain any parameter.

    Return value
    This function returns the first element of the vector.


    ! Hàm này đưa ra mà hinh console phần tử đầu tiên của vector

*/

#include<iostream>  
#include<vector>  
using namespace std;  

int main()  
{

    vector<string>  v {"java","C","C++"}; 
    //c1
    cout << v.front() << endl;
    //c2
    cout << v[0] << endl; // lấy ra phàn tử đầu tiên
    //c3
    cout << *(v.begin()) << endl;

    
    
    return 0;   
}  

/*  C++ Vector back()

    ! syntax back:
        v.back(); 


    ! Parameter
    This function does not contain any parameter.

    ! Return value
    This function returns the last element of vector

    ! Hàm này sẽ đưa ra cái element cuối cùng của vector

*/



#include<iostream>  
#include<vector>  
using namespace std;  
int main() {  


    vector<string> v {"SamSung","Apple","Tien"};  
    //c1
    cout << v.back() << endl; // hàm vector back nó sẽ in ra phần tử cuối cùng Function
    //c2
    cout << v[v.size() - 1] << endl; // cách lấy ra phần tử cuối cùng
    //c3
    cout << *(v.end() - 1) << endl;


    return 0;   
}  
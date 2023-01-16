
/*  C++ Vector empty(): this functions determines whether the vector is empty or not.
    ! Hàm này chỉ ra xem cái vector đó có trống rỗng hay là không

    Syntax:     
            bool empty();


    Parameter:
    It does not contain any parameter.

    Return value:
    It returns a boolean value either 0 or 1.

*/
// Example 1: Vector empty
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v;  
    if(v.empty())  
        cout<<"Vector v is empty";  
    else  
        cout<<"Vector v is not empty";  
    return 0;  
}  


// Example 2: Vector not empty
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<char> v1{'j','a','v','a'};  
    if(v1.empty())  
        cout<<"Vector v1 is empty";  
    else  
        cout<<"Vector v1 is not empty";  
    return 0;  
}  

/*  C++ Vector assign(): 

    This function assigns new values to the vector and replacing the old ones.
    ( hàm này gán các giá trị mới cho vector và thay các giá trị cũ )

    !Syntax: 
            v.assign(first,last);  
            v.assign(n,val);  

    !Parameter:
    (first,last) :It defines the range.first is an input iterator pointing to the first element and last is an input iterator refering to the past the last element.

        + n : Number of times the value to be occurred.
        + val : It defines the value which is to be assigned.

    !ReturnL:
    val : It defines the value which is to be assigned.

*/
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v {1,2,3,4,5};  
    vector<int> v1;  // tạo ra một vector mới

    v1.assign(v.begin() + 1, v.end()-1);  // gán vector v (cũ) cho vector v1 mới

    for(int i = 0; i < v1.size(); i++)  
        cout << v1[i] << " "; 

    cout << endl;
    for(auto & x : v1) {
        cout << x << " ";
    }

    return 0;  
}  
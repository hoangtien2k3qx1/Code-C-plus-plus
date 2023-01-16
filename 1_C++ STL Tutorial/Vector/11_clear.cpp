
/*  C++ Vector clear() :
    * This function removes all elements from the vector.
    ( hàm này sẽ loại bỏ tất cả các phần tử khỏi vector )

    !Syntax: 
            v.clear();



    !Parameter:
        It does not contain any parameter.

    !Return value:
        It does not return any value.

*/
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int>  v {1,2,3,4,5};  
    cout <<"Elements of v vector are: ";  
    for(int i=0; i<v.size(); i++)  
        cout << v[i] << " ";


    cout << endl;

    v.clear();  
    cout << "Elements are cleared the vector: ";
    for(int i=0; i<v.size(); i++)  
        cout << v[i];  


    return 0;  
}  



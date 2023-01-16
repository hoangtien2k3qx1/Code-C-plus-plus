
/*  C++ Vector push_back() : this function adds a new element at the end of the vector.

    Syntax: 
            v.push_back(i) 
    
    ! i is the value which is to be inserted at the end of the vector.

    Return value: This function does not return any value.

*/

#include<iostream>  
#include<vector>  
using namespace std;  

int main()  
{  
    vector<char> v;  
    v.push_back('j');  
    v.push_back('a');  
    v.push_back('v');  
    v.push_back('a');  

    for(int i=0; i<v.size(); i++)  
        cout << v[i];  

    return 0;  
}  
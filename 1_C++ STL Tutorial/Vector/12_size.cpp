
/*  C++ Vector size() : 

    Syntax: 
            int n=v.size();  


    Parameter
    It does not contain any parameter.

    Return value
    It returns the number of elements in the vector.


*/

#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string> v{"Welcome to javaTpoint", "c"};  
    cout<<"Size of the string is :" << v.size() << endl;


    vector<int> v1{1,2,3,4,5};  
    cout<<"Size of the vector is :" << v1.size() << endl; 



    return 0;  
}  
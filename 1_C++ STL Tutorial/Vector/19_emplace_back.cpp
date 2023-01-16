
/*  C++ Vector emplace_back(): this function is used to insert a new element at the end of the vector.

    Syntax: Consider a vector 'v'. Syntax would be :

                    v.emplace_back(args);  


    Parameter:
        args: Arguments forwarded to construct the new element.


*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<char> v{'C','+'};  
    
    v.emplace_back('+');  
    for(int i=0; i<v.size(); i++)  
        cout << v[i];  


    return 0;  
}  
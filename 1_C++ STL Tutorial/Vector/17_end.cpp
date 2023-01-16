
/*  C++ Vector end():   This function returns an iterator referring to the past-last-element in the vector container.

    Syntax: Consider a vector v. Syntax would be:

                iterator it=v.end()  


    Parameter
    It does not contain any parameter.

    Return value
    It returns an iterator following the last element.



*/

#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v{10,20,20,40};  
    vector<int>::iterator it;  

    for(it=v.begin(); it!=v.end(); it++)  
        cout << *it << " ";  



    return 0;
}  
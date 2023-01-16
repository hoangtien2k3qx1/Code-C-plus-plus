
/*  C++ Vector emplace(): This function inserts a new element just before the position pos and size of the vector container increases.


    Syntax: Consider a vector 'v'. Syntax would be:

                Iterator it=v.emplace(pos, args);  


    Parameter:
            pos: It defines the position before which the new element is to be inserted.
            args: Arguments forwarded to construct the new element.

    Return value:
    It returns an iterator to the newly inserted element.


*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v{1,2,3,4,5};  

    cout<<"Elements of vector v are :";  
    for(int i=0;i<v.size();i++)  
        cout<<v[i]<<" ";  

    cout<<'\n';  

    cout<<"After adding two elements, elements are :";  
    vector<int>::iterator it=v.emplace(v.begin()+2,8);  
    v.emplace(it,9);  
    for(int i=0;i<v.size();i++)  
        cout<<v[i]<<" ";  



    return 0;  
}  
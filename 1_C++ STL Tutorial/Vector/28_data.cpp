
/*  C++ Vector data(): This function returns a pointer to an array internally used by a vector to store its elements.


    Syntax:
                    data_type *p=v.data();  


    Parameter:
    It does not contain any parameter.

    Return value:
    It returns a pointer to an array.


*/

#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v {10,20,30,40,50};

    int *k = v.data();  
    for(int i=0; i<v.size(); i++)  
        cout << *k++ << " ";  



    return 0;  
}  
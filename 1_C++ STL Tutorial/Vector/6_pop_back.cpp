
/*  C++ Vector pop_back(): It delete the last element and reduce the size of the vector by one.
                        

    Syntax:     
            v.pop_back();

    
    Parameter
    It does not contain any parameter.

    Return value
    It does not return any value.

*/

#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string> v {"welcome", "to", "javaTpoint", "tutorial"};  

    cout << "Initial string is:\t ";  
    for(int i=0; i<v.size(); i++)  
        cout << v[i]<< " ";  

    cout<<'\n';  

    cout << "After delete last string, string is:\t ";  
    v.pop_back();  
    for(int i=0; i<v.size(); i++)  
        cout << v[i] << " ";  


    cout << endl;

    
    vector<int> v1 = {1, 2, 3, 4, 5};
    v1.pop_back();
    for(int i=0; i<v1.size(); i++) {
        cout << v1[i] << " ";
    }


    return 0;  
}  
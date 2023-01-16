
/*  C++ Vector swap(): // hoán đổi 2 vector

    * This function is used to exchange the elements specified in two vectors.

    ! Syntax:    
        v1.swap(v2);  

    Parameter: 
    v2: v2 is a vector, whose value is to be swapped with another vector.   

    Return value: 
    It does not return any value.

*/



#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int>  v1 = {1, 2, 3, 4, 5};  
    vector<int>  v2 = {6, 7, 8, 9, 10};  

    cout<<"Before swapping,elements of v1 are :";  
    for (int i=0; i<v1.size(); i++)  
        cout << v1[i] << " ";  

    cout << '\n';  

    cout << "Before swapping,elements of v2 are :";  
    for(int i=0;i<v2.size();i++)  
        cout << v2[i] << " ";  

    cout <<'\n';  


    v1.swap(v2);
    cout << "After swapping,elements of v1 are :";   
    for(int i=0;i<v1.size();i++)  
        cout << v1[i] << " ";  

    cout <<'\n';  

    cout << "After swapping,elements of v2 are:";  
    for(int i=0;i<v2.size();i++)  
        cout << v2[i] << " ";  



    return 0;  
}  
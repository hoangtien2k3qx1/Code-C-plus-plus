
/*  C++ Vector resize(): 
    *It modifies the size of the vector to the specified valueL:
    ( nó sử đổi kích thước của vector với giá trị chỉ định )

    !Syntax: 
            + v.resize(n);
            + v.resize(n, val);  



    Parameter: 
        n : It is the new vector size.
        val : If n is greater than the current vector size, then value(val) is inserted in the added space.


    Return value: 
    It does not return any value.



*/

#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<int> v;  
    for(int i=1; i<=10; i++)  
    {  
        v.push_back(i);  
    }  
    cout<<"Initial elements are: ";  
    for(int i=0;i<v.size();i++)  
        cout<<v[i]<<" ";  

    v.resize(5);  // resest size ( đặt lại kích thước cho vector)

    cout<<'\n';  

    cout<<"After resizing its size to 5, elements are: ";  
    for(int i=0;i<v.size();i++)  
        cout<<v[i]<<" ";  


    cout << endl;

    v.resize(8, 12);
    for(auto & x : v) {
        cout << x << " ";
    }

    return 0;  
}  
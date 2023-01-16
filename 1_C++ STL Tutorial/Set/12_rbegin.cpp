
/*  C++ set rbegin():   Reverse begin => lấy ra phần tử cuối cùng

    C++ set rbegin() function is used to return a reverse iterator referring to the last element of the set container.


*/

#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main ()  
{  
    set<int> myset= {10,50,30,40,20};  
        
    // show content:  
    cout<<"Elements are: "<<endl;  
    // set<int>::reverse_iterator rit;  
    // for (rit=myset.rbegin(); rit!=myset.rend(); ++rit)  
    //     cout << *rit<< '\n';  


    cout << *myset.begin() << endl;
    cout << *myset.rbegin() << endl;


    cout << myset.size() << endl;
    
    return 0;  
}  
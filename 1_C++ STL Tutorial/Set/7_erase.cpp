
/*



*/

#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main ()  
{  
    set<int> myset;  
    set<int>::iterator it;  
    
    myset = {10, 20, 30, 40};  
        
    cout<<"Before erasing the element: \n";  
    for (it=myset.begin(); it!=myset.end(); ++it)  
        cout << *it<< '\n';  
    
    myset.erase(30);                  // erasing by value  
    
    cout<<"\nAfter erasing the element: \n";  
    for (it=myset.begin(); it!=myset.end(); ++it)  
        cout << *it<< '\n';  
    return 0;  
}  
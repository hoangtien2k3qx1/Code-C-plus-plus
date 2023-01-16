
/*
    Syntax:
            void clear();                 //until C++ 11  
            void clear() noexcept;      //since C++ 11  


*/

#include <iostream>  
#include <set>  
using namespace std;  
  
int main() {  
  
    set<int> myset = {10,20,30,40};   
    
    cout << "Initial size of set before clear operation = " << myset.size() << endl;  
    
    myset.clear();  
    
    cout << "Size of set after clear operation = " << myset.size() << endl;  
    
    return 0;  
}  
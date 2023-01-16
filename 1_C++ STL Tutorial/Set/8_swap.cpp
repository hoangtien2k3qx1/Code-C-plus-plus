
/*
    Syntax:
            void swap (set& x);  

*/

#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main () {  
    int myints[] = {10,20,30,40,50,60};  
    set<int> first (myints,myints+3);  
    set<int> second (myints+3,myints+6);    
    
    first.swap(second);  
    
    cout << "first set contains:";  
    for (set<int>::iterator it = first.begin(); it!=first.end(); ++it)  
        cout << ' ' << *it;  
    cout << '\n';  
    
    cout << "second set contains:";  
    for (set<int>::iterator it = second.begin(); it!=second.end(); ++it)  
        cout << ' ' << *it;  
    cout << '\n';  
    
    return 0;  
}  
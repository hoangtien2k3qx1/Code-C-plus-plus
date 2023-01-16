
/*  C++ set count():




*/

#include <iostream>  
#include <set>  
  
using namespace std;  
   
int main()  
{  
    // initialize container  
    set<int> mp;  
   
    // insert elements in random order  
    mp.insert(30);  
    mp.insert(40);  
    mp.insert(60);  
    mp.insert(20);  
    mp.insert(50);  
   
    // checks if key 30 is present or not  
    if (mp.count(30))  
        cout << "The key 30 is present\n";  
    else  
        cout << "The key 30 is not present\n";  
   
    // checks if key 100 is present or not  
    if (mp.count(100))  
        cout << "The key 100 is present\n";  
    else  
        cout << "The key 100 is not present\n";  
   
    return 0;  
}  
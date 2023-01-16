
/*
    C++ map erase() function


*/

#include <iostream>  
#include <map>  
using namespace std;  
  
int main ()  
{  
    map<char,int> mymap;  
    map<char,int>::iterator it;  
    mymap['a']=10;  
    mymap['b']=20;  
    mymap['c']=30;  
    mymap['d']=40;  
        
    cout<<"Before erasing the element: \n";  
    for (it = mymap.begin(); it != mymap.end(); ++it)  
        std::cout << it->first << " => " << it->second << '\n';  
        
    it = mymap.find('b');  
    mymap.erase (it);  // mymap.erase('b'); 
    
    
    cout<<"\nAfter erasing the element: \n";  
    for (it=mymap.begin(); it!=mymap.end(); ++it)  
        std::cout << it->first << " => " << it->second << '\n';  
        
    return 0;  
}  
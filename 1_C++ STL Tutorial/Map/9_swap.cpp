
/*
    C++ map swap() function // hàm hoán đổi cũng giống giống copy ấy mà

    


*/

#include <iostream>  
#include <map>  
  
using namespace std;  
  
int main ()  
{  
    map<char,int> map1,map2;  
    
    map1['x'] = 100;  
    map1['y'] = 200;  
    
    map2['a'] = 110;  
    map2['b'] = 220;  
    map2['c'] = 330;  
    
    map1.swap(map2);  
    
    cout << "map1 contains:\n";  
    for (map<char,int>::iterator it=map1.begin(); it!=map1.end(); ++it)  
        cout << it->first << " => " << it->second << '\n';  
    
    cout << "map2 contains:\n";  
    for (map<char,int>::iterator it=map2.begin(); it!=map2.end(); ++it)  
        cout << it->first << " => " << it->second << '\n';  
    
    return 0;  
}  
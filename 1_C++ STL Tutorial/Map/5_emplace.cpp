
/*
    C++ map emplace() function

    template <class...Args>  
    pair<iterator, bool> emplace (Args&&... args);    //since C++ 11


*/

#include <iostream>  
#include <utility>  
#include <string>  
   
using namespace std;  
   
#include <map>  
int main()  
{  
    map<string, string> m;  
   
    // uses pair's move constructor  
    m.emplace(make_pair(string("a"), string("a")));  
   
    // uses pair's converting move constructor  
    m.emplace(make_pair("b", "abcd"));  
   
    // uses pair's template constructor  
    m.emplace("d", "ddd");  
   
    // uses pair's piecewise constructor  
    m.emplace(piecewise_construct,  
              forward_as_tuple("c"),  
              forward_as_tuple(10, 'c'));  
   
    for (const auto &p : m) {  
        cout << p.first << " => " << p.second << '\n';  
    }  
}  
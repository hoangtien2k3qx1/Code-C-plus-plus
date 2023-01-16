
/*
    C++ map find() function

    iterator find (const key_type& k);             // until C++ 11  
    onst_iterator find (const key_type& k) const;    //since C++ 11  

*/

#include <iostream>  
#include <map>  
using namespace std;  

int main(void) {  
    map<char, int> m = {{'a', 100}, {'b', 200}, {'c', 300}, {'d', 400}, {'e', 500}};  
    
    auto it = m.find('c');  // tìm ra pair<char, int> ('c', 300)
    
    cout << "Iterator points to " << it->first << " = " << it->second << endl;  
    
    return 0;  
}  
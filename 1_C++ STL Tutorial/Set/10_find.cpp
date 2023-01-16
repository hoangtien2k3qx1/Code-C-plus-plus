
/*  C++ set find():

    C++ set find() function is used to find an element with the given value val. 
    If it finds the element then it returns an iterator pointing to the element otherwise, 
    it returns an iterator pointing to the end of the set i.e. set::end().


*/

#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main(void) {  
    set<int> m = {100,200,300,400};  
    
    auto it = m.find(300);  

    cout << "Iterator points to " << *it << endl;  
    
    string s = "tien";
    if (s.find("e") != -1) {
        s.erase(s.find("e"), 1);
    }

    cout << s << endl;


    return 0;  
}  
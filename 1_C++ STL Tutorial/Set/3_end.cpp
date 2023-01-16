
/*
    Syntax:
            iterator end();                            //until C++ 11  
            iterator end() const;                //until C++ 11  
            iterator end() noexcept;              //since C++ 11  
            iterator end() const noexcept;  //since C++ 11  


*/

#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main ()  
{  
    set<string> myset = {"Java", "C++", "SQL"};  
    
    // show content:  
    for (set<string>::iterator it=myset.begin(); it!=myset.end(); ++it)  
        cout << *it<< '\n';  
    
    return 0;  
}  



//! //////////////
#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main()  
{  
    set<int> c;  
    c.insert(5);  
    c.insert(2);  
    c.insert(4);  
    c.insert(1);  
    c.insert(0);  
    c.insert(0);  
    c.insert(9);  
    
    set<int>::iterator i = c.begin();  
    while (i != c.end())  
        cout << *i++ << " ";  
    cout << endl;  
}  
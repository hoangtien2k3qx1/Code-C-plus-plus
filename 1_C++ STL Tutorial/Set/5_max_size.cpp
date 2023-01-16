
/*  C++ set max_size():


    Syntax:
            size_type max_size() const;               // until C++ 11  
            size_type max_size() const noexcept;    //since C++ 11  


*/

#include <iostream>  
#include <set>  
  
using namespace std;  
   
int main()  
{  
    set<char, char> s;  
    cout << "Maximum size of a 'set' is " << s.max_size() << "\n";  
    return 0;  
}  



//! 
#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main ()  
{  
    int i;  
    set<int> myset;  
    
    if (myset.max_size()>1000)  
    {  
        for (i=0; i<1000; i++) myset.insert(0);  
        cout << "The set contains 1000 elements.\n";  
    }  
    else cout << "The set could not hold 1000 elements.\n";  
    
    return 0;  
}  
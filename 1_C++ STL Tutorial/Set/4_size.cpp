
/*
    Syntax:

            size_type size() const;               // until C++ 11  
            size_type size() const noexcept;    //since C++ 11  


*/

#include <set>  
#include <iostream>  
using namespace std;  
   
int main()  
{   
    set<char> num {'a', 'b', 'c', 'd'};   
    cout << "num set contains " << num.size() << " elements.\n";  
    return 0;  
}  
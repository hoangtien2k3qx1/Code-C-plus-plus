
/*
    C++ map size() Function


        size_type size() const; // until C++ 11  
        size_type size() const noexcept; //since C++ 11  

*/

#include <map>  
#include <iostream>  
using namespace std;  
   
int main()  
{   
    map<int,char> num {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};   
    cout << "num map contains " << num.size() << " elements.\n";  
}  

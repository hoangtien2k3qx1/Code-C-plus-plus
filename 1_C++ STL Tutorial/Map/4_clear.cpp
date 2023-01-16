
/*
    C++ map clear() function

    void clear(); //until C++ 11  
    void clear() noexcept; //since C++ 11  

*/

#include <iostream>  
#include <map>  
  
using namespace std;  
  
int main() {  
  
   map<char, int> mymap = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}};  
  
   cout << "Initial size of map before clear operation = " << mymap.size() << endl;  
  
   mymap.clear();  // xóa tất cả phần tử trong map
  
   cout << "Size of map after clear opearation = " << mymap.size() << endl;  
  
   return 0;  
}  
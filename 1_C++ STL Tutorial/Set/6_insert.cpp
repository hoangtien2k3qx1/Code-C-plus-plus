
/*  C++ set insert():   C++ set insert() is used for inserting new element in the set.

    set khi chèn các phần tử vào nó sẽ tự động sắp xếp từ nhỏ tới lớn


*/

#include <iostream>  
#include <set>  
  
using namespace std;  
int main()  
{  
    set<int> s;  
   
    // Function to insert elements  
    // in the set container  
    s.insert(1);  
    s.insert(4);  
    s.insert(2);  
    s.insert(5);  
    s.insert(3);  
   
    cout << "The elements in set are: ";  
    for (auto it = s.begin(); it != s.end(); it++)  
        cout << *it << " ";  
   
    return 0;  
}  
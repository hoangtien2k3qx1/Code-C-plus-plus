
/*
    C++ map insert() function


    map<char, int> m = {{'a', 1}, {'b', 2}, {'c', 3}};

    ! 1. inserting new element  
    m.insert(pair<char, int>('d', 4));  
    m.insert(pair<char, int>('e', 5)); 


    ! 2. inserting element with the given position  
    m.insert(m.begin(), pair<char, int>('f', 1));    
    m.insert(m.end(), pair<char, int>('g', 5)); 


    ! 3. inserting the elements of m1 to m2 from begin to end 
    map<char, int> m2;  // creating new map m2  
    m2.insert(m.begin(), m.end());  // insert theo kiểu copy tất cả từ m sang m2


*/

#include <iostream>  
#include <map>  
  
using namespace std;  
  
int main() {  
    map<char, int> m = {{'a', 1}, {'b', 2}, {'c', 3}};  
    
    //! inserting new element  
    m.insert(pair<char, int>('d', 4));  
    m.insert(pair<char, int>('e', 5));  

    for (auto it = m.begin(); it != m.end(); ++it)  
        cout << it->first << " = " << it->second << endl; 



    //! inserting element with the given position  
    m.insert(m.begin(), pair<char, int>('f', 1));    
    m.insert(m.end(), pair<char, int>('g', 5)); 

    cout << endl << endl;
    for (auto it = m.begin(); it != m.end(); ++it)  
        cout << it->first << " = " << it->second << endl; 



    //! inserting the elements of m1 to m2 from begin to end 
    map<char, int> m2;  // creating new map m2  
    m2.insert(m.begin(), m.end());  // insert theo kiểu copy tất cả từ m sang m2

    cout << endl << endl;
    for (auto it = m2.begin(); it != m2.end(); ++it)  
        cout << it->first << " = " << it->second << endl;  



    
    return 0;  
}  
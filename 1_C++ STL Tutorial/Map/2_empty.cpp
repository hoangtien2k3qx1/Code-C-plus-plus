
/*
    bool empty() const; // until C++ 11  
    bool empty const noexcept; //since C++ 11  

*/

#include <map>  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    map<int,int> numbers;  
    cout << " Initially, numbers.empty(): " << numbers.empty() << "\n";  
    numbers[1] = 100;  
    numbers[2] = 200;  
    numbers[3] = 300;  
    cout << "\n After adding elements, numbers.empty(): " << numbers.empty() << "\n";  
}  

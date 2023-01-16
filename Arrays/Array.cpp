/*
    There are 2 types of arrays in C++ programming:
    1. simple dimensional array (mảng đơn chiều)
    2. multidimension array (mảng đa chiều)

*/
/*
    - Advantage of Array in C++:
    + Code oftimization(less code) : tối ưu hóa code hơn
    + Random access: truy cập ngẫu nhiêu từng phần tử của mảng
    + easy to traverse data
    + easy manipulate data
    + easy to sort data ect

    - Disadvantage of Array C++:
    + Fixed size: kích thước cố định
    
*/


// tìm hiểu về vòng foreach trong c++11


#include <iostream>  
using namespace std;  
int main()  
{  
 int arr[5]={10, 0, 20, 0, 30}; //creating and initializing array    
        //traversing array    
    for (int i: arr) {    // foreach loop
        cout<<i<<"\n";    
    }    
}  
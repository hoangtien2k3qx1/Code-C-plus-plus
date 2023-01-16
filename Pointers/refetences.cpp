
// Reference C++: tham chiếu

/*
    C++ provides two types of references:
    + References to non-const values: tham chiếu không có giá trị 
    + References as aliases : tham chiếu dưới dạng bí danh

    int a = 10;
    int &value = a; // value reference to a: value tham chiếu đến a

*/

#include<iostream>
#include<cmath>
#include<string.h>
#include<stdlib.h>

void Swap_a_b(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}


int main() {
    // int a = 10;
    // int b = 5;
    // Swap_a_b(a, b);
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;


    int a = 10;
    int &value = a; // value reference to a: value tham chiếu đến a
    value = 20; // khi thay đổi giá trị

    std::cout << a << std::endl;
    std::cout << value << std::endl;

}



/////////////////////////////////////////////
//////////

#include <iostream>  
using namespace std;  
struct profile  
{  
    int id;  
};  
struct employee  
{  
    profile p;  
};  
int main()  
{  
    employee e;  
    int &ref=e.p.id;  
    ref=34;  
    std::cout << e.p.id << std::endl;  
}  
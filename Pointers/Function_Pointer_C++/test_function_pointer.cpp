

#include<iostream>
#include<cmath>
#include<string>

int Sum_add (int a, int b) {
    return a + b;
}

int main() {
    int a = 5, b= 7;
    int (*fptr) (int, int) = Sum_add; //! c1
    // int (*fptr) (int, int) = &Sum_add; //! C2

    std::cout << (*fptr)(a, b) << std::endl; //! C1
    std::cout << fptr(a, b) << std::endl; //! C2
    
    std::cout << Sum_add(a, b) << std::endl; 
}
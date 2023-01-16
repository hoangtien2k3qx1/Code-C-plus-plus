

/*
1. Kiểu casting
    + Trong C ++, có 5 loại casts khác nhau: C-style casts, static casts, const casts, 
    dynamic cast và reinterpretation. Bốn cái sau đôi khi được gọi là casts được đặt tên.

*/
#include<iostream>
#include<typeinfo>

// casts kiểu C
int main() {
    // int i1 = 10;
    // int i2 = 4;

    int i1 { 10 }; // int i1 = {10} // int i1 = 10;
    int i2 { 4 };
    float f { float(i1) / i2 };
    std::cout << f;
}


// static_cast : syntax: static_cast<type *> (name);
int main() {
    int i1 = 10;
    int i2 = 4;
    float f = static_cast<float> (i1) / (i2);
    std::cout << f;
}




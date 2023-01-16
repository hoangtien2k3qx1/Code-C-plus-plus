
/*
    Nhap vao 3 số a, b, c và sắp xếp theo thứ tự tăng dần và chỉ được sử dụng 1 biến phụ

*/

#include<iostream>
#include<cmath>
#include<string>

int main() {
    int a, b, c, temp;
    std::cout << "Nhap vao a, b, c: "; std::cin >> a >> b >> c;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a < c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b < c) {
        temp = b;
        b = c;
        c= temp;
    }
    std::cout << "Tang dan: " << c << " " << b << " " << a << std::endl;
    return 0;
}

//! Để khởi tạo các đối tượng thành viên không có hàm tạo mặc định

/*
    Trong ví dụ sau, một đối tượng “a” của lớp “A” là thành viên dữ liệu của 
    lớp “B” và “A” không có hàm tạo mặc định. 
    Danh sách khởi tạo phải được sử dụng để khởi tạo “a”.

*/

#include <iostream>
using namespace std;
 
class A {
    int i;
public:
    A(int );
};
 
A::A(int arg) {
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}
 
// Lớp B. chứa đối tượng thuộc lớp A
class B {
    A a;
public:
    B(int );
};
 
B::B(int x) : a(x) {  // Phải dùng danh sách khởi tạo
    cout << "B's Constructor called";
}
 
int main() {
    B obj = B(10);

    return 0;
}
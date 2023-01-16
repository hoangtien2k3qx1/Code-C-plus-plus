
//! Để khởi tạo các thành viên lớp cơ sở

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
 
// Lớp B thừa kế từ A
class B : A {
public:
    B(int );
};
 
B::B(int x) : A(x) { //! Phải dùng danh sách khởi tạo
    cout << "B's Constructor called";
}
 
int main() {
    B obj(10);
    
    return 0;
}

//! Khi tên tham số của hàm tạo giống với thành viên dữ liệu

/*
    Nếu tên tham số của hàm tạo giống với tên thành viên dữ liệu thì thành viên dữ liệu
    phải được khởi tạo bằng cách sử dụng con trỏ thí hoặc Danh sách khởi tạo.

*/

#include <iostream>
using namespace std;
 
class A {
    int i;
public:
    A(int );
    int getI() const { 
        return i; 
    }
};
 
A::A(int i) : i(i) { }  // Phải dùng con trỏ this hoặc danh sách khởi tạo
/* Hàm tạo trên có thể viết lại như sau:
A::A(int i) {
    this->i = i;
}
*/
 
int main() {
    A a(10);
    cout << a.getI();

    return 0;
}
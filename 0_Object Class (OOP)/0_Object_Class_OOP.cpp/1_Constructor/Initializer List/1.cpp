
//! Để khởi tạo các thành viên dữ liệu hằng không tĩnh (non-static const):

/*
    Các thành viên dữ liệu const phải được khởi tạo bằng Danh sách khởi tạo.
    Lý do khởi tạo thành viên dữ liệu const trong danh sách khởi tạo là vì 
    không có bộ nhớ nào được cấp phát riêng cho thành viên dữ liệu const

*/

#include<iostream>
using namespace std;
 
class Test {
    const int t; // const
public:
    Test(int t) : t(t) {}  // Phải dùng danh sách khởi tạo
    int getT() { 
        return t; 
    }
};
 
int main() {
    system("cls");
    Test t1 = Test(10);
    cout << t1.getT();

    cin.get();
    return 0;
}
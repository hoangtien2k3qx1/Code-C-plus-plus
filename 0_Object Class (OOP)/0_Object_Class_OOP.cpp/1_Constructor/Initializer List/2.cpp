
//! Để khởi tạo các thành viên tham chiếu

/*
    Các thành viên tham chiếu phải được khởi tạo bằng Danh sách khởi tạo. 
    Trong ví dụ sau, “t” là một thành viên tham chiếu của lớp Test và được khởi tạo bằng Danh sách khởi tạo

*/

#include<iostream>
using namespace std;
 
class Test {
    int &t;
public:
    Test(int &t) : t(t) {}  //! Phải dùng danh sách khởi tạo
    int getT() { 
        return t; 
    }
};
 
int main() {
    int x = 20;
    Test t1(x);
    cout << t1.getT() << endl;

    x = 30;
    cout<< t1.getT() << endl;

    return 0;
}

//! initializer list : Danh sách khởi tạo được sử dụng để khởi tạo các thành viên dữ liệu của một lớp.
//! Danh sách khởi tạo contructor

#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int i = 0, int j = 0) : x(i), y(j) {}
    /*  Danh sách khởi tạo trên là tuỳ chọn vì
        vì hàm tạo cũng có thể viết như sau:
        Point(int i = 0, int j = 0) {
            x = i;
            y = j;
        }
    */

    int getX() const { return x; }
    int getY() const { return y; }
};

int main()
{
    Point t1(10, 15);
    cout << "x = " << t1.getX() << ", ";
    cout << "y = " << t1.getY();
    return 0;
}
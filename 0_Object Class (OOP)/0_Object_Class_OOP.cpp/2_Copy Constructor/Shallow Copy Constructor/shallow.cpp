
/*
    ! Trong C++ có hai loại copy được tạo bởi hàm xây dựng đó là:s
            + Shallow copy
            + Deep copy


    * Shallow Copy:
        - hàm xây dựng sao chép mặc định.
        - Shallow copy sẽ sao chép tất cả các thành viên.

*/

#include <iostream>

using namespace std;

class TestShallowCopy
{
    int a;
    int b;
    int *p;

public:
    TestShallowCopy()
    {
        p = new int;
    }
    void TaoDuLieu(int x, int y, int z)
    {
        a = x;
        b = y;
        *p = z;
    }
    void HienThi()
    {
        cout << "   Gia tri cua a la: " << a << std::endl;
        cout << "   Gia tri cua b la: " << b << std::endl;
        cout << "   Gia tri cua *p la: " << *p << std::endl;
    }
};
int main()
{
    TestShallowCopy t1;
    t1.TaoDuLieu(2, 6, 8);

    TestShallowCopy t2 = t1;
    //! nếu gán thế này thì con trỏ p của cả 2 đối tượng cùng trỏ vào 1 vùng nhớ.
    //! Nếu ta giải phóng vùng nhớ thì cả 2 trường đều bị giải phóng.
    //! Nên ta có Deep copy để giải quyết vấn đề trên.


    cout << "Du lieu cua doi tuong t1: " << endl;
    t1.HienThi();
    cout << "Du lieu cua doi tuong t2: " << endl;
    t2.HienThi();

    return 0;
}
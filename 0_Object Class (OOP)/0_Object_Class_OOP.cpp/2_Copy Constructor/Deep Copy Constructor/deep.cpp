
/*
    ! Trong C++ có hai loại copy được tạo bởi hàm xây dựng đó là:s
            + Shallow copy
            + Deep copy


    * Deep copy:
        - Deep copy tự động cấp phát bộ nhớ cho bản sao và sau đó sao chép giá
          trị thực cho bản sao, cả nguồn và bản sao có vị trí bộ nhớ khác nhau.

        - Deep copy yêu cầu chúng ta viết hàm xây dựng do người dùng định nghĩa.

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

    TestShallowCopy(const TestShallowCopy &test)
    {
        a = test.a;
        b = test.b;
        p = new int;
        *p = *(test.p);
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
    system("cls");

    TestShallowCopy t1;
    t1.TaoDuLieu(2, 6, 8);

    TestShallowCopy t2 = t1;

    cout << "Du lieu cua doi tuong t1: " << endl;
    t1.HienThi();
    cout << "Du lieu cua doi tuong t2: " << endl;
    t2.HienThi();


    cin.get();
    return 0;
}

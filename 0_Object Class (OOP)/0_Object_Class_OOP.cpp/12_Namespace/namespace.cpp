
/*
    ! Namespace trong C++ 

    + Một namespace trong C++ giúp bạn giải quyết tình huống này và được sử dụng như 
    là thông tin bổ sung để phân biệt các hàm, lớp, biến… cùng tên có sẵn trong các 
    thư viện khác nhau.


    * syntax:
            namespace ten_cua_namespace {
                ! phần khai báo code
            }

            => name::code;  // code có thể là một biến hoặc hàm.

*/


#include <bits/stdc++.h>

namespace HOANGTIEN
{
    namespace hoangtien
    {
        void print()
        {
            std::cout << "Hoang Anh Tien - Thanh Hoa" << std::endl;
        }
    }
}

namespace hoangtien2k3 {
    class SoHoc {
    private:
        int a;
        int b;

    public:
        SoHoc(int a, int b) : a(a), b(b) {}
        virtual ~SoHoc() {}

        void print() {
            std::cout << a << " - " << b << std::endl;
        }
    };
}

int main()
{
    HOANGTIEN::hoangtien::print();

    hoangtien2k3::SoHoc sh = hoangtien2k3::SoHoc(4, 5);
    sh.print();

    return 0;
}
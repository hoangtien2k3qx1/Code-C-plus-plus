
/*
    ! C++ Polymorphism: TÍNH ĐA HÌNH C++

    !There are two types of Polymorphism in C++:
        - Compile time Polymorphism:
            + Function overloading
            + Operator overloading
        - Runtime Polymorphism:
            + Virtual function.

    / Đa hình (polymorphism) nghĩa là có nhiều hình thái khác nhau. Tiêu biểu là,
    đa hình xuất hiện khi có một cấu trúc cấp bậc của các lớp và chúng liên quan
    với nhau bởi tính kế thừa. /


    ! 1. Compile time Polymorphism: TÍNH ĐA HÌNH TRONG THỜI GIAN BIÊN DỊCH CHƯƠNG TRÌNH
        - Tính đa hình này được sử dụng bằng cách nạp chồng hàm hoặc nạp chồng toán tử.

            + Nạp chồng hàm (Function Overloading) cho phép sử dụng cùng một tên gọi
            cho các hàm “giống nhau” (có cùng mục đích). Nhưng khác nhau về kiểu dữ liệu tham số
            hoặc số lượng tham số.


    ! 2. Runtime Polymorphism: TÍNH ĐA HÌNH TRONG THỜI GIAN CHẠY CHƯƠNG TRÌNH
        - Virtual Polymorphism:

*/

// ! 1. Compile time Polymorphism: TÍNH ĐA HÌNH TRONG THỜI GIAN BIÊN DỊCH.
// ! Nạp Chồng Hàm Trong C++
#include <iostream>
using namespace std;

class inDuLieu
{
public:
    void hamIn(int i)
    {
        cout << "In so nguyen: " << i << endl;
    }

    void hamIn(double f)
    {
        cout << "In so thuc: " << f << endl;
    }

    void hamIn(string s)
    {
        cout << "In chuoi: " << s << endl;
    }
};

int main(void)
{
    inDuLieu idl;

    idl.hamIn(1235);
    idl.hamIn(67.02);
    idl.hamIn("Codelearn.io");

    return 0;
}



// ! Nạp chồng Toán Tử trong C++
#include <iostream>
using namespace std;

class Box
{
private:
    double chieudai;  // chieu dai cua mot box
    double chieurong; // Chieu rong cua mot box
    double chieucao;  // Chieu cao cua mot box
public:
    double tinhTheTich(void)
    {
        return chieudai * chieurong * chieucao;
    }
    void setChieuDai(double chieudai)
    {
        this->chieudai = chieudai;
    }
    void setChieuRong(double chieurong)
    {
        this->chieurong = chieurong;
    }
    void setChieuCao(double chieucao)
    {
        this->chieucao = chieucao;
    }
    // Nap chong toa tu + de cong hai doi tuong Box.
    Box operator+(const Box &b)
    {
        Box box;
        box.chieudai = this->chieudai + b.chieudai;
        box.chieurong = this->chieurong + b.chieurong;
        box.chieucao = this->chieucao + b.chieucao;
        return box;
    }
};

int main()
{
    Box Box1;             // Khai bao Box1 la cua kieu Box
    Box Box2;             // Khai bao Box2 la cua kieu Box
    Box Box3;             // Khai bao Box3 la cua kieu Box
    double thetich = 0.0; // Luu giu the tich cua mot box tai day

    // thong tin chi tiet cua box 1
    Box1.setChieuDai(5);
    Box1.setChieuRong(2);
    Box1.setChieuCao(4);

    // thong tin chi tiet cua box 2
    Box2.setChieuDai(7);
    Box2.setChieuRong(6);
    Box2.setChieuCao(9);

    // the tich cua box 1
    thetich = Box1.tinhTheTich();
    cout << "The tich cua Box1 la: " << thetich << endl;

    // the tich cua box 2
    thetich = Box2.tinhTheTich();
    cout << "The tich cua Box2 la: " << thetich << endl;

    // cong hai doi tuong nhu sau:
    Box3 = Box1 + Box2;

    // the tich cua box 3
    thetich = Box3.tinhTheTich();
    cout << "The tich cua Box3 la: " << thetich << endl;

    return 0;
}



//  ! 2. Runtime Polymorphism: TÍNH ĐA HÌNH TRONG THỜI GIAN CHẠY CHƯƠNG TRÌNH
// ! Runtime Polymorphism:
#include <iostream>
using namespace std;
class Mayvitinh
{
public:
    virtual void show()
    {
        cout << "mayvitinh" << endl;
    }
};
class mayAcer : public Mayvitinh
{
public:
    void show()
    {
        cout << "mayAcer" << endl;
    }
};
int main()
{
    mayAcer may1;

    Mayvitinh *tenmay = &may1;
    tenmay->show();

    return 0;
}



#include <iostream>
using namespace std;
class Mayvitinh
{
public:
    void show()
    {
        cout << "mayvitinh" << endl;
    }
};
class mayAcer : public Mayvitinh
{
public:
    void show()
    {
        cout << "mayAcer" << endl;
    }
};

int main()
{
    mayAcer may1;

    Mayvitinh *tenmay = &may1;
    tenmay->show();

    return 0;
}

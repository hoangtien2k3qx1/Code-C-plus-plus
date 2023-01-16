
/*
    Câu 4: 
        3.	Viết chương trình thực hiện các yêu cầu sau:
            1.	Khai báo lớp time với các thuộc tính: giờ, phút, giây.
            Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng time.
            2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng time.
            3.	Định nghĩa toán từ ++,-- để tăng, giảm một giây. Thực hiện tăng, 
            giảm một giây và in kết quả ra màn hình (kết quả phải được chuẩn hóa 
            dưới định dạng 24 tiếng hh:mm:ss).
            
*/

#include <iostream>
using namespace std;

class ThoiGian
{
public:
    int hour;       
    int minute;
public:
    ThoiGian() : hour(0), minute(0) {}  //hàm tạo mạc định
    ThoiGian(int h, int m) : hour(h) , minute(m) {} // hàm tạo 2 tham số
    ThoiGian operator++ () // hàm nạp chồng toán tử ++ tiền tố
    {
        ++minute;        
        if (minute >= 60)
        {
            ++hour;
            minute -= 60;
        }
        return ThoiGian(hour, minute);
    }
    ThoiGian operator++(int) //hàm nạp chồng toán tử ++ hậu tố
    {
        ThoiGian T(hour, minute);
        ++minute;         
        if (minute >= 60)
        {
            ++hour;
            minute -= 60;
        }
        return T;
    }
    ThoiGian operator +(ThoiGian& Ts) //hàm nạp chồng toán tử + một ngôi
    {
        ThoiGian T;
        T.hour = this->hour + Ts.hour;
        T.minute = this->minute + Ts.minute;
        if (T.minute >= 60)
        {
            ++T.hour;
            T.minute -= 60;
        }
        return T;
    }
// nạp chồng toán tử - hai ngôi
    friend ThoiGian operator - (ThoiGian& T1, ThoiGian& T2) 
    {
        ThoiGian T;
        T.hour = T1.hour - T2.hour;
        T.minute = T1.minute - T2.minute;
        return T;
    }
    friend istream& operator >> (istream& is, ThoiGian& T) //nạp chồng toán tử nhập
    {
        cout << "hour = ";
        is >> T.hour;
        cout << "minute = ";
        is >> T.minute;
        return is;
    }
    friend ostream& operator << (ostream& os, ThoiGian& T) // nạp chồng toán tử xuất
    {
        os << T.hour << "h:" << T.minute << "p" << endl;
        return os;
    }
    friend bool operator < (ThoiGian& T1, ThoiGian& T2)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute < T2.minute)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(T1.hour < T2.hour)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    ThoiGian T1(8, 59), T2(6, 24);
    ThoiGian T3;
    T3 = T1 + T2;  //test nạp chồng toán tử +
    cout << "Thoi gian hien tai cua T3 la: ";
    cout << T3; //test toán tử xuất <<
    if (T3++.minute == 24) //test nạp chồng toán tử ++ hậu tố
    {
        cout << "Hau to false" << endl;
        cout << T3;
    }
    else
    {
        cout << "Hau to true" << endl;
    }
    cout << "Thoi gian sau khi thuc hien phep toan ++ hau to la: ";
    cout << T3;
    cout << "Thoi gian hien tai cua T3 la: ";
    cout << T3;
    if (++T3.minute == 25) //test nạp chồng toán tử ++ tiền tố
    {
        cout << "Tien to true" << endl;
    }
    else
    {
        cout << "Tien to false" << endl;
        cout << T3;
    }
    cout << "Thoi gian sau khi thuc hien phep toan ++ tien to la: ";
    cout << T3;
    ThoiGian T4; 
    T4 = T1 - T2; // test nạp chồng toán tử - hai ngôi
    cout << "Thong tin T4 ";
    cout << T4;
    ThoiGian T5;
    cout << "Nhap thong tin T5" << endl;
    cin >> T5; // test nạp chồng toán tử nhập >>
    cout << "Thong tin vua nhap la: ";
    cout << T5;
    if (T5 < T4)
    {
        cout << "T5 < T4" << endl;
    }
    else
    {
        cout << "T5 > T4" << endl;
    }
    return 0;
}
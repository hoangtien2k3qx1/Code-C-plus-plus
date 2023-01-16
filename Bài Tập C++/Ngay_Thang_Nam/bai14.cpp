
/*
    Câu 3: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp date với các thuộc tính: ngày, tháng, năm.
        Xây dựng hàm tạo không đối, hàm tạo có đối, hàm hủy một đối tượng date.
        2.	Xây dựng các phương thức: nhập, xuất, chuẩn hóa một đối tượng date.

        Định nghĩa toán từ ++,-- để tăng, giảm một ngày. Thực hiện tăng, giảm một ngày 
        và in kết quả ra màn hình (kết quả phải được chuẩn hóa dưới dạng dd-mm-yyyy).

*/

#include<bits/stdc++.h>
using namespace std;

class Lop {
    private:
        int day, month, year;
    public:
        Lop() {};
        Lop(int day, int month, int year) : day(day), month(month), year(year) {};
        ~Lop() {};
        void Nhap();
        void XuatNgayTruocDo();
        void XuatNgaySauDo();
};

void Lop::Nhap() {
    cout << "Nhap vao ngay: "; cin >> day;
    cout << "Nhap vao thang: "; cin >> month;
    cout << "Nhap vao nam: "; cin >> year;
}

int KiemTraNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int TimSoNgayTrongThang(int thang, int nam)
{
    int NgayTrongThang;
    switch(thang) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: NgayTrongThang = 31; break;
    case 4: case 6: case 9 : case 11: NgayTrongThang = 30; break;
    default:
        return (KiemTraNamNhuan(nam)) ? (NgayTrongThang = 29) : (NgayTrongThang = 28); break;
    }
    return NgayTrongThang;
}

void Lop::XuatNgayTruocDo() {
    int newDay = day, newMonth = month, newYear = year;
    if (newYear > 0 && (newMonth > 0 && newMonth < 13) && (newDay > 0 && newDay <= (TimSoNgayTrongThang(newMonth, newYear))) ) {
        if (newDay < TimSoNgayTrongThang(newMonth, newYear)) {
            newDay++;
        } else if (newMonth < 12) {
            newDay = 1;
            newMonth++;
        } else {
            newDay= newMonth = 1;
            newYear++;
        }
    }
    cout << "\nNgay Truoc Do: " << newDay << "-" << newMonth << "-" << newYear << endl;
}


//! Cách 1:
// void Lop::XuatNgaySauDo() {
//     int newDay = day, newMonth = month, newYear = year;
//     if (year > 0 && (month > 0 && month < 13) && (day > 0 && day <= (TimSoNgayTrongThang(month, year))) ) {
//         if (day == 1 && month != 1) { // day = 1 va month != 1
//             if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) { // vì khi lùi lại thì tháng đó sẽ có 31 ngày
//                 newDay = 31;
//                 newMonth--;
//             } else if (month == 5 || month == 7 || month == 10 || month == 12) {
//                 newDay = 30;
//                 newMonth--;
//             } else if (month == 3){    
//                 if (KiemTraNamNhuan(year)) {
//                     newDay = 29;
//                     newMonth--;
//                 } else {
//                     newDay = 28;
//                     newMonth--;
//                 }
//             }   
//         } else if (day == 1 && month == 1) {
//             newDay = 31;
//             newMonth = 12;
//             newYear--;
//         } else {
//             newDay--;
//         }
//     }    
//     cout << "Ngay Sau Do: " << newDay << "-" << newMonth << "-" << newYear << endl;
// }


//! Cách 2:
void Lop::XuatNgaySauDo() {
    int newYear = year, newMonth = month, newDay = day;
    if (newYear > 0 && (newMonth > 0 && newMonth < 13) && (newDay > 0 && newDay <= (TimSoNgayTrongThang(newMonth, newYear))) ) {
        if (newDay == 1 && newMonth == 1) {
            newDay = 31;
            newMonth = 12;
            newYear--;
        } else if (newDay <= TimSoNgayTrongThang(newMonth, newYear)) {
            if (newDay == 1) {
                newMonth--;
                newDay = TimSoNgayTrongThang(newMonth, newYear) + 1;
            }
            newDay--;
        }
    }
    cout << "Ngay Sau Do: " << newDay << "-" << newMonth << "-" << newYear << endl;
}


int main() {
    Lop l;
    l.Nhap();
    l.XuatNgayTruocDo();
    l.XuatNgaySauDo();
    return 0;
}


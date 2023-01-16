
/*
    viết một chương trình nhập vào ngày, tháng, năm . Kiểm tra xem ngày, tháng nhập có hợp lệ hay không
    và Tính thứ trong tuần của ngày đó.


    ĐỂ TÍNH ĐƯỢC THỨ TRONG TUẦN CỦA NGÀY ĐÓ: 
        * ta phải dùng đến CÔNG THỨC ZELLER là một giải thuật được sáng tạo bởi ZELLER để tính đươc thứ 
        trong bất kỳ ngày nào của năm theo lịch

    Năm nhuận (Leap Year) tính theo lịch Gregorian (từ năm 1582): năm phải chia hết cho 4 và không chia hết cho 100, hoặc năm phải chia hết cho 400.
    Thứ trong tuần được tính theo công thức Zeller:
    =>  DayOfWeek = (d+y+y/4-y/100+y/400+(31*m)/12)%7. 
    Trong đó:
        + a = (14 – month)/12
        + y = year – a
        + m = month + 12*a -2
    DayOfWeek: 0 (Chủ nhật), 1 (Thứ hai), 2 (Thứ ba), …

*/

#include<bits/stdc++.h>

int Check_Nam_Nhuan (int month, int year) {
    int ngaytrongthang;
    switch(month) {
        case 4: case 6: case 9: case 11: ngaytrongthang = 30; break;
        case 2: ngaytrongthang = 28 + ((year%4==0 && year%100!=0)||(year%400==0)); break;
        default: ngaytrongthang = 31; break; 
    }
    return ngaytrongthang;
}

int ZELLER (int day, int month, int year) {
    int dayofweek;
    year = year - (14 - month) / 12;
    month = month +  12 * ((14 - month) / 12) - 2;
    dayofweek = (day + year + year/4 - year/100 + year/400 + (31 * month)/12) % 7;
    return dayofweek;
}

int main() {
    int day, month, year, ngaycuathang;
    do {
        std::cout << "\nNhap vao day: "; std::cin >> day;
        std::cout << "Nhap vao month: "; std::cin >> month;
        std::cout << "Nhap vao year: "; std::cin >> year;
        ngaycuathang = Check_Nam_Nhuan(month, year);
        if ( day > ngaycuathang || day < 1) {
            std::cout << "Ngay khong hop le!: ";
        }
    } while ((day<1 || day>ngaycuathang || month<0 || month>12 || year<1582) && std::cout << "Error:Nhap lai: ");
    
    int Dayofweek = ZELLER(day, month, year);
    if ( !Dayofweek ) { //! Dayofweek == 0
        std::cout << "\nChu nhat!" << std::endl;
    } else {
        std::cout << "\nThu " << Dayofweek + 1 << std::endl;
    }
    
    return 0;
}
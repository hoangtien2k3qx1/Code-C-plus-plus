
/*
    viết một chương trình nhập vào ngày, tháng, năm . Kiểm tra xem ngày, tháng nhập có hợp lệ hay không
    và Tính thứ trong tuần của ngày đó.


    ĐỂ TÍNH ĐƯỢC THỨ TRONG TUẦN CỦA NGÀY ĐÓ: 
        * ta phải dùng đến CÔNG THỨC ZELLER là một giải thuật được sáng tạo bởi ZELLER để tính đươc thứ 
        trong bất kỳ ngày nào của năm theo lịch

*/

#include<bits/stdc++.h>

int Check_Nam_Nhuan (int month, int year) {
    int ngaytrongthang;
    switch(month) {
        case 4: case 6: case 9: case 11: 
            ngaytrongthang = 30; 
            break;
        case 2: 
            ngaytrongthang = 28 + ((year%4==0 && year%100!=0)||(year%400==0)); 
            break;
        default: 
            ngaytrongthang = 31; 
            break; 
    }
    return ngaytrongthang;
}

int ZELLER (int day, int month, int year) {
    int dayofweek;
    year -= (14 - month) / 12;
    month += 12 * ((14 - month) / 12) - 2;
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
    if ( !Dayofweek ) {
        std::cout << "\nChu nhat!" << std::endl;
    } else {
        std::cout << "\nThu " << Dayofweek + 1 << std::endl;
    }
    return 0;
}
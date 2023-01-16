
// lesson 16: 300 code thiếu nhi
/*      
    Viết chương trình nhập vào một năm (> 1582), in lịch của năm đó. Tính thứ
    cho ngày đầu năm bằng công thức Zeller 
    * Công thức Zeller, tính thứ cho ngày đầu năm (ngày 1/1) 

    Lưu ý: Giải thuật Zeller
    Năm nhuận (Leap Year) tính theo lịch Gregorian (từ năm 1582): năm phải chia hết cho 4 và không chia hết cho 100, hoặc năm phải chia hết cho 400.
    Thứ trong tuần được tính theo công thức Zeller:
    =>  DayOfWeek = (d + y + y/4 - y/100 + y/400 + (31*m)/12) % 7. 
    Trong đó:
        + a = (14 – month)/12
        + y = year – a
        + m = month + 12*a -2
    DayOfWeek: 0 (Chủ nhật), 1 (Thứ hai), 2 (Thứ ba), …

*/

#include<iostream>
#include<cmath>
#include<conio.h>

int Check_Nam_Nhuan (int month, int year) {
    int ngaytrongthang;
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: ngaytrongthang = 31; break;
        case 2: ngaytrongthang = 28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0); break;
        default: ngaytrongthang = 31; break;
    }
    return ngaytrongthang;
}

int main() {
    int year;
    std::cout << "Nhap vao year: "; std::cin >> year;
    
    int month = 1;
    int y = year - ((14 - month)/12);
    int m = month + 12*((14 - month)/12) - 2;
    int dayofweek = (1 + y + (y/4 - y/100 + y/400) + (31*m)/12) % 7;


    for (int i = 0; i <= 12; i++) {
        std::cout << "Thang " << i << std::endl;
        int ngaytrongthang = Check_Nam_Nhuan (i, year);

        std::cout << "S   M   T   W   T   F   S" << std::endl;
        for (int j=0; j<dayofweek; j++) {
            std::cout << "  ";
        }
        for (int j=0; j<ngaytrongthang; j++) {
            std::cout << j;
            if ((dayofweek + j) % 7 == 0) {
                putchar("\n");
            }
        }
        dayofweek = (dayofweek + ngaytrongthang) % 7;
        if (dayofweek) {
            putchar("\n");
        }
    }
    return 0;
}

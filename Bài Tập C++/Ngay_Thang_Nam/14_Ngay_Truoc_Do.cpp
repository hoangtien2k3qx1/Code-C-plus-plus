
/*
    Viết một chương trình nhập và ngày, tháng, năm và kiểm tra xem có hợp lệ hay không.
    Tìm ngày, tháng, năm của ngày tiếp theo và Tìm ngày, tháng, năm của ngày ngay trước đó        

    VD: input 01/01/2001
        => ngày mai: 02/01/2001
        => ngày hôm qua: 31/12/2000

*/
#include<iostream>
#include<cmath>
#include<string>

int Check_month (int month, int year) {
    int dayofmonth;
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: dayofmonth = 31; break;
        case 2: dayofmonth = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28; break;
        default: dayofmonth = 30; break;
    }
    return dayofmonth;
}

// Ngày trước đó 
void Before_Day_Month_Year (int day, int month, int year) { // ngày trước đó
    if (day < Check_month(month, year)) {
        day++;
    } else if (month < 12) {
        day = 1;
        month++;
    } else { // ngày = 30/31 , tháng = 12
        day = month = 1;
        year++;
    }
    std::cout << "\nDay - Month - Year Continue: " << day << "/"<< month << "/"<< year << std::endl;
}

// Ngày sau đó
void After_Day_Month_Year (int day, int month, int year) {
    if (day == 1 && month == 1) {
        day = 31;
        month = 12;
        year--;
    } else if (day <= Check_month(month, year)) {
        if (day == 1) {
            month--;
            day = Check_month(month, year) + 1;
        }
        day--;
    }
    std::cout << "\nDay - Month - Year After: " << day << "/" << month << "/" << year << std::endl;
}

int main() {
    int day, month, year, dayofmonth;
    do {
        std::cout << "\nInput day: "; std::cin >> day;
        std::cout << "Input month: "; std::cin >> month;
        std::cout << "Input year: "; std::cin >> year;
        dayofmonth = Check_month(month, year);
        if (day < 1 || day > dayofmonth) {
            std::cout << "\nError, Invalid day: ";
        }
    } while (day < 1 || day > dayofmonth || month < 0 || month > 31 || year < 1582 && std::cout << "Error, Input again: ");
    
    Before_Day_Month_Year(day, month, year);
    After_Day_Month_Year(day, month, year);

    return 0;
}
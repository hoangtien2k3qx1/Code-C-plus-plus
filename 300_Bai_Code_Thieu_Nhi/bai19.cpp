

/*
    Nhập vào thời điểm 1 và thời điểm 2. Tìm thời gian trải qua giữa hai thời
    điểm này tính bằng giờ, phút, giây.

    VD: Nhap gio, phut, giay [1]: 3 28 47 
        Nhap gio, phut, giay [2]: 5 40 12 
        Hieu thoi gian: 2 gio 11 phut, 25 giay
*/

#include<iostream>
#include<cmath>

int main() {
    int gio, phut, giay, time, time1, time2;
    std::cout << "Nhap vao gio - phut - giay [1]: "; std::cin >> gio >> phut >> giay;
    time1 = gio*3600 + phut*60 + giay;

    std::cout << "Nhap vao gio - phut - giay [2]: "; std::cin >> gio >> phut >> giay;
    time2 = gio*3600 + phut*60 + giay;

    if (time1 > time2) {
        time = time1 - time2;
    } else {
        time = time2 - time1;
    }

    std::cout << "Thoi gian chenh lech: " << time/3600 << "_gio + " << (time % 3600) / 60 << "_phut + " << (time % 3600) % 60 << "_giay";


    return 0;
}
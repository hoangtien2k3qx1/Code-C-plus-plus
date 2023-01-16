
/*
    Viết chương trình nhập vào số giờ, xuất ra số tương đương tính theo tuần,
    theo ngày và theo giờ

    VD: Nhap so gio: 1000 
        5 tuan, 6 ngay, 16 giờ
*/

#include<iostream>
#include<cmath>
#include<string>

int main() {    
    long long sogio;
    std::cout << "Nhap vao sogio: "; std::cin >> sogio;

    int so_tuan = sogio / (24*7);
    int so_ngay = (sogio % (24*7)) / 24;
    int so_gio = (sogio % (24*7)) % 24;
    std::cout << so_tuan << "_Tuan + " << so_ngay << "_Ngay + " << so_gio << "_Gio"<< std::endl;    


    return 0;
}



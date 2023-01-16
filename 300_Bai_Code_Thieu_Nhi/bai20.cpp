

/*
    Viết một chương trình nhập số KW điện tiêu thụ. Tính tiền điện phải trả
    biết rằng: khung giá tiền điện như sau:
    0kW         100kW       250kW       350kW
    500đ/kW     800đ/kW     1000đ/kW    1500đ/kW    

*/

#include<iostream>
#include<cmath>

int main() {
    int sodien, thanhtien;
    std::cout << "Nhap vao so dien tieu thu: ";
    std::cin >> sodien;

    if (sodien <= 100) {
        thanhtien = sodien * 500;
    } else if (sodien <= 250) {
        thanhtien = sodien * 800;
    } else if (sodien <= 350) {
        thanhtien = sodien * 1000;
    } else {
        thanhtien = sodien * 1500;
    }

    std::cout << "\nSo tien phai tra: " << thanhtien << std::endl;

    return 0;
}
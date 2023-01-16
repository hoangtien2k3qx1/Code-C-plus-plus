
/*
    Trong một kỳ tuyển sinh, một thí sinh sẽ trung tuyển nếu có điểm tổng kết lớn hơn hoặc bằng điển chuẩn
    và không có môn nào điểm 0
    + điểm tổng kết là tổng điểm của 3 môn thi và điểm ưu tiên
    + điểm ưu tiên bao gồm: điểm ưu tiên theo khu vực và điểm ưu tiên theo đối tượng
  
    Khu vực                         Đối tượng
    A       B       C               1       2       3
    2       1       0.5             2.5     1.5     1

*/

#include<iostream>
#include<cmath>

struct DiemChuan {
    float diemchuan; 
    float diemtoan, diemly, diemhoa;
    char KV;
    int doituong;
};

int main() {
    struct DiemChuan p1;
    do {
        std::cout << "\nNhap vao diem chuan: ";
        std::cin >> p1.diemchuan;    
        std::cout << "Nhap vao diem 3 mon(Toan - Ly - Hoa): ";
        std::cin >> p1.diemtoan >> p1.diemly >> p1.diemhoa;
        if (p1.diemchuan > 30 || p1.diemtoan > 10 || p1.diemly > 10 || p1.diemhoa > 10) {
            std::cout << "\nNhap Loi, Nhap lai: ";
        }
        
    } while (p1.diemchuan > 30 || p1.diemtoan > 10 || p1.diemly > 10 || p1.diemhoa > 10);

    std::cout << "Nhap vao khu vuc(A - B - C - X): ";
    std::cin >> p1.KV;
    std::cout << "Nhap vao doi tuong(1 - 2 - 3 - 0): ";
    std::cin >> p1.doituong;

    float DiemTong;

    if (p1.diemtoan * p1.diemly * p1.diemhoa) {
        DiemTong = p1.diemtoan + p1.diemly + p1.diemhoa;
        switch(p1.KV) {
            case 'A': DiemTong += 2; break;
            case 'B': DiemTong += 1; break;
            case 'C': DiemTong += 0.5; break;
            case 'X': DiemTong += 0; break;
            default: DiemTong += 0; break;
        }
        switch(p1.doituong) {
            case 1: DiemTong += p1.diemtoan + p1.diemly + p1.diemhoa + 2.5; break;
            case 2: DiemTong += p1.diemtoan + p1.diemly + p1.diemhoa + 1.5; break;
            case 3: DiemTong += p1.diemtoan + p1.diemly + p1.diemhoa + 1; break;
            default:  DiemTong += p1.diemtoan + p1.diemly + p1.diemhoa; break;
        }
    }

    if (DiemTong < p1.diemchuan) {
        std::cout << "\nRot - " << DiemTong << std::endl;
    } else {
        std::cout << "\nDau - " << DiemTong << std::endl;
    }

    return 0;
}


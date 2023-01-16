
/*
    Bài 5: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp thí sinh với các thuộc tính: mã thí sinh, họ tên, điểm toán, điểm lý, điểm hóa.
        2.	Tạo Các contrustor (có đối số, không đối số), getter, setter
        3.	Xây dựng các phương thức: nhập, xuất, tính tổng điểm một đối tượng thí sinh.
        4.	Nhập vào n thí sinh. In ra màn hình thông tin của thí sinh có tổng điểm cao nhất
        5.	Sắp xếp danh sách thí sinh tăng dần theo họ tên

*/


#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;
#include<string>
#include<string.h>


class SinhVien {
private:
    string masv;
    string hoten;
    float diemtoan, diemly, diemhoa;

public:
    SinhVien() {
        this->masv = "";
        this->hoten = "";
        this->diemtoan = this->diemly = this->diemhoa = 0;
    }

    SinhVien(string, string, float, float, float) {
        this->masv = masv;
        this->hoten = hoten;
        this->diemtoan = diemtoan;
        this->diemly = diemly;
        this->diemhoa = diemhoa;
    }

    string getHoten() {
        return this->hoten;
    }

    string getTen() {
        string str = this->hoten;
        string s = "";
        while(str[str.length() - 1] != ' ') {
            s.insert(s.begin() + 0, str[str.length() - 1]);
            str.pop_back();
        }
        str.pop_back();
        return s;
    }

    float getDiemtoan() {
        return this->diemtoan;
    }

    float getDiemly() {
        return this->diemly;
    }

    float getDiemhoa() {
        return this->diemhoa;
    }

    void NhapThongTin(SinhVien&);
    void NhapThongTinSinhVien(SinhVien* , int); // Function Prototype (nguyên hàm mẫu)
    void XuatThongTin(SinhVien);
    void XuatThongTinSinhVien(SinhVien*, int); // Function Prototype (nguyên hàm mẫu)

    float TongDiem(SinhVien);
    void SinhVienTongDiemCaoNhat(SinhVien*, int);
    void SapXepTheoTen(SinhVien*, int);
    void TimSinhVienTheoHoVaTen(SinhVien*, int, string);

};

void SinhVien::NhapThongTin(SinhVien &sv) {
    cout << "Nhap masv: "; getline(cin, sv.masv);
    cout << "Nhap hoten: "; getline(cin, sv.hoten);
    cout << "Nhap diemtoan: "; cin >> sv.diemtoan;
    cout << "Nhap diemly: "; cin >> sv.diemly;
    cout << "Nhap diemhoa: "; cin >> sv.diemhoa;
}

void SinhVien::NhapThongTinSinhVien(SinhVien *arr, int n) {
    cout << "\n_____________________________________________________\n";
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNHAP VAO THONG TIN SINH VIEN THU " << i + 1 << ": " << endl;
        arr->NhapThongTin(arr[i]);
    }
    cout << "\n_____________________________________________________\n";
}

float SinhVien::TongDiem(SinhVien sv) {
    return sv.diemtoan + sv.diemly + sv.diemhoa;
}

void SinhVien::XuatThongTin(SinhVien sv) {
    cout << "Masv: " << sv.masv << endl;\
    cout << "Hoten: " << sv.hoten << endl;
    cout << "Diemtoan: " << sv.diemtoan << endl;
    cout << "Diemly: " << sv.diemly << endl;
    cout << "Diemhoa: " << sv.diemhoa << endl;
    cout << "Tong Diem: " << sv.TongDiem(sv);
}


void SinhVien::XuatThongTinSinhVien(SinhVien *arr, int n) {
    cout << "\n_____________________________________________________\n";
    cout << "\t======> DANH SACH SINH VIEN <======: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "\n\nTHONG TIN SINH VIEN THU " << i + 1 << ": " << endl;
        arr->XuatThongTin(arr[i]);
    }
    cout << "\n_____________________________________________________\n";
}


void SinhVien::SinhVienTongDiemCaoNhat(SinhVien *arr, int n) {
    cout << "\n_____________________________________________________\n";
    cout << "\t=====> THONG TIN SINH VIEN CO TONG DIEM CAO NHAT <=====" << endl;
    float max = arr->TongDiem(arr[0]);

    int count = 0;
    for(int i = 0; i < n; i++) {
        if (max < arr->TongDiem(arr[i])) {
            max = arr->TongDiem(arr[i]);
            count = i;
        }
    }
    
    arr->XuatThongTin(arr[count]);
    cout << "\n_____________________________________________________\n";
}

void SinhVien::SapXepTheoTen(SinhVien *arr, int n) {
    char tenSV1[20];
    char tenSV2[20];

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i].getTen() > arr[j].getTen()) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "\t=====> DA DUOC SAP XEP THEO TEN <=====" << endl;
    arr->XuatThongTinSinhVien(arr, n);

}


void SinhVien::TimSinhVienTheoHoVaTen(SinhVien *arr, int n, string str) {
    for(int i = 0; i < n; i++) {
        if (str == arr[i].getHoten()) {
            arr->XuatThongTin(arr[i]);
        }
    }
}


int main() {
    SinhVien sv;

    int n; cout << "NHAP VAO N SINH VIEN: "; cin >> n;
    SinhVien *arr = new SinhVien[n];

    sv.NhapThongTinSinhVien(arr, n);
    sv.XuatThongTinSinhVien(arr, n);
    sv.SinhVienTongDiemCaoNhat(arr, n);

    sv.SapXepTheoTen(arr, n);

    cin.ignore();
    string str; cout << "\n\t===> NHAP VAO HO VA TEN SINH VIEN CAN TIM KIEM: "; 
    getline(cin, str);
    cout << "\n\t-------> THONG TIN VE SINH VIEN: " << str << endl;
    sv.TimSinhVienTheoHoVaTen(arr, n, str);

    delete arr;
    return 0;
}

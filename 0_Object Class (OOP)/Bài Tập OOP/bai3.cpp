
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

class SinhVien {
    private:
        string hoten, masv, ngaysinh;
        double gpa;
    public:
        SinhVien() {
            masv = hoten = ngaysinh = " ";
            gpa = 0;
        }
        SinhVien(string hoten, string ngaysinh, double gpa) {
            this->hoten = hoten;
            this->ngaysinh = ngaysinh;
            this->gpa = gpa;
        }
        friend void nhap(SinhVien&);
        friend void in(SinhVien);
};


void nhap(SinhVien &a) {
    a.masv = "DCHT20041";
    cout << "Nhap vao hoten: ";
    getline(cin, a.hoten);
    cout << " Nhap vao ngaysinh: ";
    cin >> a.ngaysinh;
    cout << "Nhap vao gpa: ";
    cin >> a.gpa;
    if (a.ngaysinh[2] != '/') a.ngaysinh.insert(0, "0");
    if (a.ngaysinh[5] != '/') a.ngaysinh.insert(3, "0"); 
}

void in(SinhVien a) {
    cout << "---THONG TIN VE TIEN---" << endl;
    cout << a.masv << " - " << a.hoten << " - " << a.ngaysinh << " - " << fixed << setprecision(2) << a.gpa << endl;
}

int main() {
    SinhVien a;
    nhap(a);
    in(a);
    return 0;
}















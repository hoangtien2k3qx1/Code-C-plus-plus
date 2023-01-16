
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
        friend istream& operator >> (istream&, SinhVien&);
        friend ostream& operator << (ostream&, SinhVien);
};


istream& operator >> (istream& in, SinhVien &a) {
    a.masv = "72DCHT20041";
    cout << "Nhap vao hoten: ";
    getline(cin, a.hoten);
    cout << "Nhap vao ngaysinh: ";
    in >> a.ngaysinh;
    cout << "Nhap vao gpa: ";
    in >> a.gpa;
    if (a.ngaysinh[2] != '/') a.ngaysinh.insert(2, "0");
    if (a.ngaysinh[5] != '/') a.ngaysinh.insert(5, "0");
    return in;
}

ostream& operator << (ostream& out, SinhVien a) {
    out << a.masv << " - " << a.hoten << " - " << a.ngaysinh << " - " << fixed << setprecision(2) << a.gpa << endl; 
    return out;
}

int main() {
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}















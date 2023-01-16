
/*
    Lớp phân số
    Thuộc tính: Tử số, mẫu số,
    Phương thức:
    •	Khởi tạo không đối số
    •	Khởi tạo có đối số
    •	Nhập tử số, mẫu số
    •	Tối giản phân số
    •	Cộng phân số
    •	Trừ phân số
    •	Nhân phân số
    •	Chia phân số
    •	In kết qua.

*/

#include<bits/stdc++.h>
using namespace std;


class PhanSo {
private:
    int tuso, mauso;

public:
    PhanSo() : tuso(0), mauso(1) {}
    PhanSo(int, int);

    friend istream& operator >> (istream& , PhanSo& );
    friend ostream& operator << (ostream& , PhanSo ); 

    void rutgon();

    friend PhanSo operator + (PhanSo, PhanSo);
    friend PhanSo operator - (PhanSo, PhanSo);
    friend PhanSo operator * (PhanSo, PhanSo);
    friend PhanSo operator / (PhanSo, PhanSo);

};

PhanSo::PhanSo(int tuso, int mauso) {
    this->tuso = tuso;
    this->mauso = mauso;
}

istream& operator >> (istream& input, PhanSo &ps) {
    cout << "Nhap tuso: "; input >> ps.tuso;
    cout << "Nhap mauso: "; input >> ps.mauso;
    return input;
}

ostream& operator << (ostream& output, PhanSo ps) {
    cout << ps.tuso << "/" << ps.mauso << endl;
    return output;
}

int gcd(int a, int b) {
    if (b == 0) 
        return a;
    return gcd(b, a % b);
}

void PhanSo::rutgon() {
    PhanSo ps;
    int g = gcd(ps.tuso, ps.mauso);

    ps.tuso /= g;
    ps.mauso /= g;

}


PhanSo operator + (PhanSo ps1, PhanSo ps2) {
    PhanSo tong(1, 1);

    tong.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
    tong.mauso = ps1.mauso * ps2.mauso;

    int g = gcd(tong.tuso, tong.mauso);

    tong.tuso /= g;
    tong.mauso /= g;

    return tong;
}


PhanSo operator - (PhanSo ps1, PhanSo ps2) {
    PhanSo hieu(1, 1);

    hieu.tuso = ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso;
    hieu.mauso = ps1.mauso * ps2.mauso;

    int g = gcd(hieu.tuso, hieu.mauso);
    hieu.tuso /= g;
    hieu.mauso /= g;

    return hieu;
}


PhanSo operator * (PhanSo ps1, PhanSo ps2) {
    PhanSo tich(1, 1);

    tich.tuso = ps1.tuso * ps2.tuso;
    tich.mauso = ps1.mauso * ps2.mauso;

    int g = gcd(tich.tuso, tich.mauso);
    tich.tuso /= g;
    tich.mauso /= g;

    return tich;
}


PhanSo operator / (PhanSo ps1, PhanSo ps2) {
    PhanSo thuong(1, 1);

    thuong.tuso = ps1.tuso * ps2.mauso;
    thuong.mauso = ps1.mauso * ps2.tuso;

    int g = gcd(thuong.tuso, thuong.mauso);
    thuong.tuso /= g;
    thuong.mauso /= g;

    return thuong;
}



int main() {
    PhanSo ps1(1, 1), ps2(1, 1);

    cout << "Nhap phan so 1: " << endl; cin >> ps1;
    cout << "Nhap phan so 2: " << endl; cin >> ps2;

    ps1.rutgon();
    ps2.rutgon();

    cout << endl; 
    cout << "Tong 2 phan so: " << ps1 + ps2 << endl;
    cout << "Hieu 2 phan so: " << ps1 - ps2 << endl;
    cout << "Tich 2 phan to: " << ps1 * ps2 << endl;
    cout << "Thuong 2 phan so: " << ps1 / ps2 << endl;

    return 0;
}


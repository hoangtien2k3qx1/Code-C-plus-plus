
/*
    Bài 3: Xây dựng chương trình nhập tam giác, tính chu vi, diện tích và in ra màn 
    hình đó là loại tam giác nào: cân, vuông, vuông cân, đều hay thường.
        -	Lớp tam giác gồm:
        o	Attributes: 3 cạnh tam giác 
        o	Method: constructor, set, get 
        o	Phương thức nhập thông tin
        o	Phương thức hiện thông tin
        o	Phương thức kiểm tra loại tam giác
        o	Phương thức tính chu vi tam giác
        o	Phương thức tính diên tích tam giác

*/

#include<bits/stdc++.h>
using namespace std;

class TamGiac {
private:
    int a, b, c;

public:

    TamGiac() {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    int getA() {
        return this->a;
    }

    int getB() {
        return this->b;
    }

    int getC() {
        return this->c;
    }

    void NhapTamGiac();
    void XuatThongTin();

    void KiemTraTamGiac();
    int ChuVi();
    int DienTichTamGiac();

};


void TamGiac::NhapTamGiac() {
    cout << "Nhap vao a: "; cin >> a;
    cout << "Nhap vao b: "; cin >> b;
    cout << "Nhap vao c: "; cin >> c;
}


void TamGiac::KiemTraTamGiac() {
    if (a + b > c && a + c > b && b + c > a) {
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
            cout << "Day la tam giac vuong!" << endl;
        } else if (a == b || b == c) {
            cout << "Day la tam gia deu!" << endl;
        } else if (a == b || a == c || b == c) {
            cout << "Day la tam giac can!" << endl;
        } else if (a*a > b*b + c*c || b*b > a*a + c*c || c*c > a*a + b*b) {
            cout << "Day la tam giac tu!" << endl;
        } else {
            cout << "Day la tam giac nhon!" << endl;
        }
    } else {
        cout << "Ba canh tren khong tao thanh tam giac!!!" << endl;
    }
}

int TamGiac::ChuVi() {
    return a + b + c;
}

int TamGiac::DienTichTamGiac() {
    int P = (a + b + c)/2;
    int result = P * (P - a) * (P - b) * (P - c);
    return sqrt(result);
}


void TamGiac::XuatThongTin() {
    cout << "Kiem tra tam giac vua nhap: ";
    TamGiac::KiemTraTamGiac();
    
    cout << "Tinh chu vi tam giac: " << ChuVi() << endl;

    cout << "Tinh dien tich tam gia: " << DienTichTamGiac() << endl;
}

int main() {
    TamGiac tg;

    tg.NhapTamGiac();
    tg.XuatThongTin();

    return 0;
}


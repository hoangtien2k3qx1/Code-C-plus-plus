
// sắp xếp học sinh theo lớp
// thằng VS Code nó không nhập hết được luồng vào.

#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>

using namespace std;

class SinhVien {
    private:
        string masv, ten, lop, email;
    public:
        SinhVien() {
            masv = ten = lop = email = " ";
        }
        friend istream& operator >> (istream& in, SinhVien&);
        friend ostream& operator << (ostream& out, SinhVien);
        bool operator < (SinhVien another) {
            return this-> masv <  another.masv;
        }
};

istream& operator >> (istream& in, SinhVien &a) {
    in >> a.masv;
    cin.ignore();
    getline(cin, a.ten);
    in >> a.lop >> a.email;
    return in;
}

ostream& operator << (ostream& out, SinhVien a) {
    out << a.masv << " " << a.ten << " " << a.lop << " " << a.email << endl;
    return out;
}

int main() {
    vector<SinhVien> sv;
    SinhVien tmp;
    while(cin >> tmp) {
        sv.push_back(tmp);
    }
    sort(sv.begin(), sv.end());
    for(SinhVien x : sv) {
        cout << x;
        
    }

    return 0;
}




// 4
// B16DCCN011
// Nguyen Trong Duc Anh
// D16CNPM1
// sv1@stu.ptit.edu.vn
// B15DCCN215
// To Ngoc Hieu
// D15CNPM3
// sv2@stu.ptit.edu.vn
// B15DCKT150
// Nguyen Ngoc Son
// D15CQKT02-B
// sv3@stu.ptit.edu.vn
// B15DCKT199
// Nguyen Trong Tung
// D15CQKT03-B
// sv4@stu.ptit.edu.vn
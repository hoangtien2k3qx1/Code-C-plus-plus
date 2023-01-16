
// sắp xếp học sinh theo lớp

#include<iostream>
#include<bits/stdc++.h>
#include<cmath>

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
        string getlop() {
            return this->lop;
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

bool cmp(SinhVien a, SinhVien b) {
    return a.getlop() < b.getlop();
}


int main() {
    int n; cin >> n;
    SinhVien a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);

    for(SinhVien x : a) {
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
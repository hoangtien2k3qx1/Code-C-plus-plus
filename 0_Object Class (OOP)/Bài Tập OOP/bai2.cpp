
// Tính tổng 2 đối tượng phân số.

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class PhanSo {
    private:
        ll tu, mau;
    public:
        PhanSo(ll tu, ll mau);
        friend istream& operator >> (istream&, PhanSo&);
        friend ostream& operator << (ostream&, PhanSo);
        void rutgon();
        friend PhanSo operator+ (PhanSo, PhanSo);
};

PhanSo::PhanSo(ll tu, ll mau) {
    this->tu = tu;
    this->mau = mau;
}

istream& operator >> (istream& in, PhanSo &a) {
    in >> a.tu >> a.mau;
    return in;
}

ostream& operator << (ostream& out, PhanSo a) {
    out << a.tu << "/" << a.mau << endl;
    return out;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

void PhanSo::rutgon() {
    ll g = gcd(tu, mau);
    tu /= g;
    mau /= g;
}

PhanSo operator+ (PhanSo a, PhanSo b) {
    PhanSo tong(1, 1);
    tong.tu = a.tu * b.mau + a.mau * b.tu;
    tong.mau = a.mau * b.mau;
    ll g = gcd(tong.tu, tong.mau);
    tong.tu /= g;
    tong.mau /= g;
    return tong;
}

int main() {
    PhanSo p(1, 1), q(1, 1);
    cin >> p >> q;
    p.rutgon();
    cout << p + q;
    return 0;
}



#include <iostream>
#include <cmath>

using namespace std;

class DIEM3D {
private:
    int x, y, z; // T?a d? x, y, z c?a di?m
public:
    // Hàm kh?i t?o không d?i s?
    DIEM3D() {
        x = y = z = 0;
    }

    // Hàm kh?i t?o có d?i s?
    DIEM3D(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    // Quá t?i toán t? nh?p
    friend istream& operator>>(istream& is, DIEM3D& diem) {
        cout << "Nhap toa do diem (x, y, z): ";
        is >> diem.x >> diem.y >> diem.z;
        return is;
    }

    // Quá t?i toán t? xu?t
    friend ostream& operator<<(ostream& os, const DIEM3D& diem) {
        os << "(" << diem.x << ", " << diem.y << ", " << diem.z << ")";
        return os;
    }

    // Quá t?i toán t? c?ng 2 di?m
    DIEM3D operator+(const DIEM3D& diem) {
        DIEM3D sum;
        sum.x = x + diem.x;
        sum.y = y + diem.y;
        sum.z = z + diem.z;
        return sum;
    }

    // Quá t?i toán t? tr? 2 di?m
    DIEM3D operator-(const DIEM3D& diem) {
        DIEM3D diff;
        diff.x = x - diem.x;
        diff.y = y - diem.y;
        diff.z = z - diem.z;
        return diff;
    }

    // Phuong th?c tính kho?ng cách gi?a 2 di?m
    double khoangCach(const DIEM3D& diem) {
        int dx = x - diem.x;
        int dy = y - diem.y;
        int dz = z - diem.z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }
};

int main() {
    DIEM3D diemA, diemB;
    char phepToan;
    
    // Nh?p t?a d? di?m A
    cin >> diemA;

    // Nh?p t?a d? di?m B
    cin >> diemB;

    
    cout << "Nhap ky tu phep toan (+ hoac -): ";
    cin >> phepToan;

    // Tính kho?ng cách t? di?m A t?i tâm O
    double khoangCachOA = diemA.khoangCach(DIEM3D());

    // Tính kho?ng cách t? di?m A t?i di?m B
    double khoangCachAB = diemA.khoangCach(diemB);

    // Th?c hi?n phép toán (+ ho?c -) trên 2 di?m
    DIEM3D ketQua;
    if (phepToan == '+') {
        ketQua = diemA + diemB;
    } else {
		ketQua = diemA - diemB;
	}
	// Xu?t k?t qu?
	cout << "Toa do diem A: " << diemA << endl;
	cout << "Toa do diem B: " << diemB << endl;
	cout << "Khoang cach tu diem A den tam O: " << khoangCachOA << endl;
	cout << "Khoang cach tu diem A den diem B: " << khoangCachAB << endl;
	if (phepToan == '+') {
	    cout << "Tong 2 diem: " << ketQua << endl;
	} else {
	    cout << "Hieu 2 diem: " << ketQua << endl;
	}
	
	return 0;
}

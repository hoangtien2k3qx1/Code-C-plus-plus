/*
    Đề Bài: Code C++ 
        R1. Nhap vao k. tìm các ước số của k. Tìm các ước số chẵn của K
        R2. Nhap thông tin của sua đóng hộp: Nhãn, Trong lƯỢNG, giá bán. 
            Xuất Thông Tin từng Sũa Đón Hộp
        R3. Kết thúc.
*/

#include<bits/stdc++.h>
using namespace std;

void TimUocSo(int k) {
    int count = 0;
    cout << "Cac Uoc Cua K: ";
    for(int i = 1; i <= k; i++) {
        if (k % i == 0) {
            cout << i << " ";
            if (i % 2 == 0) {
                count++;
            }
        }
    }
    cout << "\nSo Uoc Chan Cua K: " << count << endl;
}

class SuaDongHop {
public:
    string nhan;
    float trongLuong;
    float giaBan;

public:
    SuaDongHop() {};
    void NhapThongTinSuaDongHop(SuaDongHop *, int);
    void XuatThongTinSuaDongHop(SuaDongHop *, int);
};

void SuaDongHop::NhapThongTinSuaDongHop(SuaDongHop *arr, int n) {
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "Nhap vao Thong Tin Sua Dong Hop " << i + 1 << " : " << endl;
        cout << "Nhap vao Nhan: "; getline(cin, arr[i].nhan);
        cout << "Nhap vao Trong Luong: "; cin >> arr[i].trongLuong;
        cout << "Nhap vao Gia Ban: "; cin >> arr[i].giaBan;
    }
}

void SuaDongHop::XuatThongTinSuaDongHop(SuaDongHop *arr, int n) {
    cout << "\nThong Tin Cua Sua Dong Hop: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "\nThong Tin Cua Sua Dong Hop " << i + 1 << ": " << endl;
        cout << "Nhan: " << arr[i].nhan << endl;
        cout << "Trong Luong: " << arr[i].trongLuong << endl;
        cout << "Gia: " << arr[i].giaBan << endl;
    }
}

int main() {
    system("cls");

    while(true) {
        cout << "\n\n******************* MENU ******************" << endl;
        cout << "*** \t1. R1 Tim Uoc So Cua K           **" << endl;
        cout << "*** \t2. R2 Thong Tin Cua Sua Dong Hop **" << endl;
        cout << "*** \t3. R3 Ket Thuc Chuong Trinh      **" << endl;
        cout << "*******************************************" << endl;

        int n; cout << "\nNhap vao Lua Chon: "; cin >> n;
        if (n == 1) {
            int k;
            cout << "Nhap vao so nguyen K: "; cin >> k;
            TimUocSo(k);
        } else if (n == 2) {
            int a; cout << "Nhap So Luong Sua Dong Hop: "; cin >> a;
            SuaDongHop *arr = new SuaDongHop[a];
            arr->NhapThongTinSuaDongHop(arr, a);
            arr->XuatThongTinSuaDongHop(arr, a);

        } else {
            cout << "\nKET THUC CHUONG TRINH - THOAT CHUONG TRINH!!!\n\n" << endl;
            return 0;
        }
    }
    cin.get();
    return 0;
}

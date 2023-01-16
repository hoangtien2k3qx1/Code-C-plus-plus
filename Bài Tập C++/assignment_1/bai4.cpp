
//* Nhóm 11

// Dùng con trỏ cấp phát mảng động để nhập
/*
    Thông tin sinh viên gồm: hoten, tuoi. hãy nhập vào n sinh viên
    Xuất ra n sinh vien vừa nhập

*/

#include<bits/stdc++.h>
using namespace std;

class SinhVien {
    public:
        string hoten;
        int tuoi;

    public:
        // SinhVien(string hoten, int tuoi) {
        //     this->hoten = hoten;
        //     this->tuoi = tuoi;
        // }

        string getHoten() {
            return this->hoten;
        }

        int getTuoi() {
            return this->tuoi;
        }

        void display() {
            cout << "\nHo Ten: " << this->hoten << endl;
            cout << "Tuoi: " << this->tuoi << endl;
        }

};


int main() {
    int n; cout << "Nhap vao n sinh vien: "; cin >> n;

    SinhVien *sv = new SinhVien[n];

    cout << "--- NHAP VAO DANH SACH SINH VIEN ---";
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNhap vao hoten: "; getline(cin, sv[i].hoten);
        cout << "Nhap vao tuoi: "; cin >> sv[i].tuoi;
    }

    cout << "\n---> DANH SACH SINH VIEN VUA NHAP VAO <---";
    for(int i = 0; i < n; i++) {
        sv[i].display();
    }

    return 0;
}


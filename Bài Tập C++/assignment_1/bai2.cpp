
//* Nhóm 11

/*
    Xây dựng cấu trúc sinh viên gồm thông tin sau: họ tên, năm sinh, điểm trung bình
        a. Nhập vào danh sách n sinh viên
        b. in ra màn hình danh sách sinh viên xếp loại khá trở lên (7 <= diemtb < 8)


*/

#include<bits/stdc++.h>
using namespace std;

class SinhVien {
    private:
        string hoten;
        int namsinh;
        float diemtb;
    
    public:
        SinhVien(string hoten, int namsinh, float diemtb) {
            this->hoten = hoten;
            this->namsinh = namsinh;
            this->diemtb = diemtb;
        }

        void display() {
            cout << "\nHo Ten: " << this->hoten << endl;
            cout << "Nam Sinh: " << this->namsinh << endl;
            cout << "Diem TB: " << this->diemtb << endl;
        }

        float getDiemtb() {
            return this->diemtb;
        }

        static void checkDiemTB(vector<SinhVien> &sv) {
            for(int i = 0; i < sv.size(); i++) {
                if (sv[i].getDiemtb() >= 7 && sv[i].getDiemtb() < 8) {
                    sv[i].display();
                }
            }
        }
};


int main() {
    vector<SinhVien> sv;
    int n; cout << "Nhap vao so luong sinh vien: "; cin >> n;

    for(int i = 0; i < n; i++) {
        cin.ignore();
        string hoten; cout << "\nNhap vao Ho Ten: "; getline(cin, hoten);
        int namsinh; cout << "Nhap vao Nam Sinh: "; cin >> namsinh;
        float diemtb; cout << "Nhap vao Diem TB: "; cin >> diemtb;
        sv.push_back(SinhVien(hoten, namsinh, diemtb));
    }

    cout << "\nSINH VIEN CO DIEM KHA TRO LEN (7 <= diemtb < 8): ";
    SinhVien::checkDiemTB(sv);

    return 0;
}


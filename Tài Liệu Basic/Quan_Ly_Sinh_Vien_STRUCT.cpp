
/*  STRUCT SINH VIEN C++:   HOANG ANH TIEN

    Đề bài: chương trình quản lý sinh viên
        1. Khai báo kiểu dữ liệu SinhVien có các trường họ tên, giới tính, tuổi, điểm toán – lý – hóa và điểm trung bình.
        2. Nhập vào danh sách N sinh viên
        3. Xuất danh sách N sinh viên
        4. Tính điểm trung bình cho N sinh viên
        5. Sắp xếp N sinh viên theo thứ tự tăng dần của điểm trung bình
        6. Xếp loại N sinh viên
        7. Xuất danh sách N sinh viên ra file
        8. Viết chương trình dạng menu cho phép sử dụng các tính năng trên

*/

#include<bits/stdc++.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
 
struct SinhVien{
    string ten;
    string gioitinh;
    int tuoi;
    float diemtoan;
    float diemly;
    float diemhoa;
    float diemTB;
};

void print_Line(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void Tinh_diemTB(SinhVien &sv) {
    sv.diemTB = (sv.diemtoan + sv.diemly + sv.diemhoa) / 3;
}

void Nhap_Sinh_Vien(SinhVien &sv) {
    cout << "Nhap Ho va Ten: "; cin.ignore();
    getline(cin, sv.ten);
    cout << "Nhap GioiTinh: ";
    getline(cin, sv.gioitinh);
    cout << "Nhap Tuoi: "; 
    cin >> sv.tuoi;
    cout << "Nhap Diem Toan: ";
    cin >> sv.diemtoan;
    cout << "Nhap Diem Ly: ";
    cin >> sv.diemly;
    cout << "Nhap Diem Hoa: ";
    cin >> sv.diemhoa;
    Tinh_diemTB(sv); 
}

void Nhap_Sinh_Vien_N(SinhVien arr[], int n) {
    print_Line(100);
    for(int i=0; i<n; i++) {
        cout << "\nNHAP THONG TIN SINH VIEN " << i + 1 << ": \n";
        Nhap_Sinh_Vien(arr[i]);
    }
    print_Line(100);
    cout << endl;
}

void Xuat_Danh_Sach(SinhVien arr[], int n) {
    print_Line(120);
    cout << "\nSTT\tHo va Ten \t\tGioi Tinh\tTuoi\t\tDiemToan\tDiemLy\t\tDiemHoa\t\tDiemTB";
    for(int i=0; i<n; i++) {
        cout << "\n" << i + 1;
        cout << "\t" << arr[i].ten;
        cout << "\t\t" << arr[i].gioitinh;
        cout << "\t\t" << arr[i].tuoi;
        cout << "\t\t" << arr[i].diemtoan << "\t\t" << arr[i].diemly << "\t\t" << arr[i].diemhoa;
        cout << "\t\t" << arr[i].diemTB;
    }
    print_Line(120);
}

void xap_xep(SinhVien arr[], int n) {
    SinhVien temp;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i].diemTB > arr[j].diemTB) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void xep_loai(SinhVien sv) { 
    if (sv.diemTB >= 8) cout << "Gioi";
    else if (sv.diemTB >= 6.5) cout << "Kha";
    else if (sv.diemTB >= 5) cout << "Trung Binh";
    else cout << "Yeu";
}

void Xep_Loai(SinhVien arr[], int n) { // true
    print_Line(100);
    for(int i=0; i<n; ++i) {
        cout << "Xep loai sinh vien " << i + 1 << ": ";
        xep_loai(arr[i]);
        cout << endl;
    }
    print_Line(100);
}

 
int main() {
    int key;

    int n;
    bool danhap = false;
    do {
        cout << "Nhap so luong SV: "; 
        cin >> n;
    } while (n <= 0);

    SinhVien arr[n];

    while (true) {
        cout << endl;
        cout << "CHUONG TRINH QUAN LY SINH VIEN C++\n";
        cout << "********************** MENU - SINH VIEN *********************\n";
        cout << "*****         CHUONG TRINH QUAN LY SINH VIEN C++        *****\n";
        cout << "*****              1. Nhap du lieu                      *****\n";
        cout << "*****              2. In danh sach sinh vien            *****\n";
        cout << "*****              3. Sap xep sinh vien theo diemTB     *****\n";
        cout << "*****              4. Sap xep sinh vien                 *****\n";
        cout << "*****              5. Xuat danh sach sinh vien          *****\n";
        cout << "*****              0. Thoat chuong trinh                *****\n";
        cout << "*************************************************************\n";
        cout << endl;
        cout << "                   * NHAP LUA CHON CUA BAN *                 \n";

        cout << "\nLUA CHON KEY: ";
        cin >> key;
        switch(key) {
            case 1:
                cout << "BAN CHON NHAP DU LIEU SINH VIEN!!!";
                Nhap_Sinh_Vien_N(arr, n);
                cout << "NHAP THANH CONG OKE!!!\n";
                danhap = true;
                cout << "BAM ENTER DE TIEP TUC!!!" << endl;
                getch();
                break;
            case 2:
                if (danhap == true) {
                    cout << "\nBan chon: in danh sach sinh vien: ";
                    Xuat_Danh_Sach(arr, n);
                } else {
                    cout << "Ban chua nhap thong tin danh Sinh Vien!!!";
                }
                cout << "BAM ENTER DE TIEP TUC!!!" << endl;
                getch();
                break;
            case 3:
                if (danhap == true) {
                    cout << "\nBan da chon sap xep theo STB!!";
                    xap_xep(arr, n);
                    Xuat_Danh_Sach(arr, n);
                } else {
                    cout << "Ban chua nhap thong tin danh Sinh Vien!!!";
                }
                cout << "BAM ENTER DE TIEP TUC!!!" << endl;
                getch();
                break;
            case 4:
                if (danhap == true) {
                    cout << "\nBan da chon xep loai sinh vien!!!";
                    Xep_Loai(arr, n);
                } else {
                    cout << "Ban chua nhap thong tin danh Sinh Vien!!!";
                }
                cout << "BAM ENTER DE TIEP TUC!!!" << endl;
                getch();
                break;
            case 5: 
                if (danhap == true) {
                    cout << "\nBan da chon Xuat danh sach sinh vien: ";
                    Xuat_Danh_Sach(arr, n);
                } else{
                    cout << "Ban chua nhap thong tin danh Sinh Vien!!!";
                }
                cout << "\n";
                cout << "BAM ENTER DE TIEP TUC!!!" << endl;
                getch();
                break;
            case 0:
                cout << "\nBan chon thoat chuong trinh!";
                getch();
                return 0;
            default: 
                cout << "\nKhong co chuc nang nay!!!";
                cout << "BAM ENTER DE TIEP TUC!!!" << endl;
                getch();
                break;
        }
    }

    return 0;
}
 




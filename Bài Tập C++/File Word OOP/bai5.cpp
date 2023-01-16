
/*
    Câu 5: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp người với các thuộc tính: họ tên, năm sinh.
        Khai báo lớp sinh viên kế thừa từ lớp người và thêm các 
        thuộc tính: mã sinh viên, điểm trung bình.
        2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng người, sinh viên.
        3.	Nhập vào n sinh viên. Sắp xếp lại và in ra màn hình danh sách sinh viên 
        theo thứ tự giảm dần của điểm trung bình.

*/

#include<bits/stdc++.h>
using namespace std;

class BassClass {
    protected:
        string hoten;
        int namsinh;
    public:
        BassClass() {};
        BassClass(string hoten, int namsinh) : hoten(hoten), namsinh(namsinh) {};
        ~BassClass() {};

        string getHoten() {
            return this->hoten;
        }

        int getNamsinh() {
            return this->namsinh;
        }

};

class DriverClass : public BassClass {
    private:
        string masv;
        float DTB;
    public:
        DriverClass() {};
        DriverClass(string hoten, int namsinh, string masv, float DTB) : 
        BassClass(hoten, namsinh), masv(masv), DTB(DTB) {};
        ~DriverClass() {};

        void NhapThongTin(DriverClass&);
        void NhapThongTinSinhVien(DriverClass*, int);
        void XuatThongTin(DriverClass);
        void XuatThongTinSinhVien(DriverClass*, int);
        void SapXepTheoDTB(DriverClass*, int);

};
 

void DriverClass::NhapThongTin(DriverClass &sv) {
    cout << "Nhap vao hoten: "; getline(cin, sv.hoten);
    cout << "Nhap vao masv: "; getline(cin, sv.masv);
    cout << "Nhap vao namsinh: "; cin >> sv.namsinh;
    cout << "Nhap vao DTB: "; cin >> sv.DTB;
}

void DriverClass::NhapThongTinSinhVien(DriverClass *arr, int n) {
    cout << "\n_____________________________________________________\n";
    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNHAP VAO THONG TIN SINH VIEN THU " << i + 1 << ": " << endl;
        arr->NhapThongTin(arr[i]);
    }
    cout << "\n_____________________________________________________\n";
}


void DriverClass::XuatThongTin(DriverClass sv) {
    cout << "Hoten: " << sv.hoten << endl;
    cout << "NamSinh: " << sv.namsinh << endl;
    cout << "Masv: " << sv.masv << endl;
    cout << "DTB: " << sv.DTB << endl;
}

void DriverClass::XuatThongTinSinhVien(DriverClass *arr, int n) {
    cout << "\t===> DANH SACH SINH VIEN <===" << endl;
    for(int i = 0; i < n; i++) {
        cout << "\n\n\tTHONG TIN SINH VIEN THU " << i + 1 << ": " << endl;
        arr->XuatThongTin(arr[i]);
    }
    cout << "\n_____________________________________________________\n";
}


void DriverClass::SapXepTheoDTB(DriverClass *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr[i].DTB < arr[j].DTB) {
                DriverClass temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "\t=====> DA DUOC SAP XEP THEO DTB TANG ĐAN <=====" << endl;
    arr->XuatThongTinSinhVien(arr, n);
}

int main() {
    DriverClass sv;
    int n; cout << "Nhap vao n Sinh Vien: "; cin >> n;

    DriverClass *arr = new DriverClass[n];

    sv.NhapThongTinSinhVien(arr, n);
    sv.XuatThongTinSinhVien(arr, n);
    sv.SapXepTheoDTB(arr, n);

    return 0;
}


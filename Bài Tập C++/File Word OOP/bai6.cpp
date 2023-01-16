
/*
    Câu 6: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp người với các thuộc tính: họ tên, năm sinh.
        Khai báo lớp sinh viên kế thừa từ lớp người và thêm các thuộc tính: mã sinh viên, điểm trung bình.
        2.	Xây dựng các phương thức: constructor, nhập, xuất cho các đối tượng người, sinh viên.
        3.	Nhập vào n sinh viên. Nhập thông tin tìm kiếm là mã sinh viên hoặc họ tên. In ra màn hình thông tin sinh viên tìm thấy hoặc thông báo là không tìm thấy.

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

        string getHoten() {
            return this->hoten;
        }

        int getNamsinh() {
            return this->namsinh;
        }

        string getMasv() {
            return this->masv;
        }

        void NhapThongTin(DriverClass&);
        void NhapThongTinSinhVien(DriverClass*, int);
        void XuatThongTin(DriverClass);
        void XuatThongTinSinhVien(DriverClass*, int);
        void TimKiemSinhVien(DriverClass*, int, string); 

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
    cout << "\nHoten: " << sv.hoten << endl;
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


void DriverClass::TimKiemSinhVien(DriverClass *arr, int n, string s) {
    for(int i=0; i<n; i++) {
        if (s == arr->getHoten()) {
            cout << "\n\t===> DA TIM THAY SINH VIEN THEO TEN <=== \n";
            arr->XuatThongTin(arr[i]); return;
        }
        if (s == arr->getMasv()) {
            cout << "\n\t===> DA TIM THAY SINH VIEN THEO MASV <===";
            arr->XuatThongTin(arr[i]); return;
        } 
    }
    cout << "\n\t===> KHONG TIM THAY SINH VIEN <===\n";
}


int main() {
    DriverClass sv;
    int n; cout << "Nhap vao n Sinh Vien: "; cin >> n;

    DriverClass *arr = new DriverClass[n];
    sv.NhapThongTinSinhVien(arr, n);
    sv.XuatThongTinSinhVien(arr, n);

    cin.ignore(1);
    string str; cout << "\nNHAP VAO MASV/ HOTEN CAN TIM KIEM: "; getline(cin, str);
    sv.TimKiemSinhVien(arr, n, str);


    delete arr;
    return 0;
}


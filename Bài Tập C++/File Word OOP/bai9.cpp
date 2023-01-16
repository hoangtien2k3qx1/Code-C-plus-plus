
/*
    Câu 9: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp nhân viên với các thuộc tính: họ tên, chức vụ, giới tính, năm sinh, quê quán, năm vào làm.
    2.	Xây dựng các toán tử >>, << để nhập, xuất một đối tượng nhân viên.
    3.	Nhập vào n nhân viên. In ra màn hình danh sách các nhân viên làm việc trên 20 năm 
    (số năm làm việc bằng năm hiện tại trừ năm vào làm).


*/

#include<bits/stdc++.h>
using namespace std;


class NhanVien {
    private:
        string hoten, chucvu, gioitinh, quequan;
        int namvaolam, namsinh;
    public:

        friend istream& operator >> (istream&, NhanVien&);
        friend ostream& operator << (ostream&, NhanVien);
        bool SoNamLamViec(NhanVien, int);

};

istream& operator >> (istream& input, NhanVien &nv) {
    cout << "\nNhap vao ho ten: "; getline(input, nv.hoten);
    cout << "Nhap vao chuc vu: "; getline(input, nv.chucvu);
    cout << "Nhap vao gioi tinh: "; getline(input, nv.gioitinh);
    cout << "Nhap vao que quan: "; getline(input, nv.quequan);
    cout << "Nhap vap nam vao lam: "; input >> nv.namvaolam;
    cout << "Nhap vao nam sinh: "; input >> nv.namsinh;
    return input;
}

ostream& operator << (ostream& output, NhanVien nv) {
    output << "\nHo ten: " << nv.hoten << endl;
    output << "Chuc vu: " << nv.chucvu << endl;
    output << "Gioi tinh: " << nv.gioitinh << endl;
    output << "Que quan: " << nv.quequan << endl;
    output << "Nam vao lam: " << nv.namvaolam << endl;
    output << "Nam sinh: " << nv.namsinh << endl;
    return output;
}


bool NhanVien::SoNamLamViec(NhanVien nv, int n) {
    return (2022 - nv.namvaolam > 20) ? true : false;
}


int main() {
    int n; cout << "NHAP VAO N NHAN VIEN: "; cin >> n;
    NhanVien *arr = new NhanVien[n];

    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNHAP VAO NHAN VIEN THU " << i + 1  << ": " << endl;
        cin >> arr[i];
    }

    cout << "\n===> DANH SACH NHAN VIEN LAM VIEC TREN 20 NAM <===";
    for(int i = 0; i < n; i++) {
        if (arr->SoNamLamViec(arr[i], n)) {
            cout << arr[i] << endl;
        }
    }

    delete arr;
    return 0;
}
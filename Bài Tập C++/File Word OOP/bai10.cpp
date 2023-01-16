
/*
    Câu 10: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp nhân sự với các thuộc tính: mã nhân viên, họ tên, năm sinh.
    Khai báo lớp cán bộ kế thừa từ lớp nhân sự và thêm các thuộc tính: lương cơ bản, hệ số lương.
    2.	Xây dựng các phương thức: nhập, xuất cho các đối tượng nhân sự, cán bộ.
    3.	Nhập vào n cán bộ. Thực hiện tính lương cho các cán bộ. In ra màn hình danh 
    sách cán bộ theo thứ tự giảm dần của tiền lương.

*/

#include<bits/stdc++.h>
using namespace std;

class NhanSu {
    protected:
        string manv, hoten;
        int namsinh;
    public:
        NhanSu() {};
        NhanSu(string manv, string hoten, int namsinh) : manv(manv), hoten(hoten), namsinh(namsinh) {};
        ~NhanSu() {};

};

class CanBo : public NhanSu {
    private:
        float luongcoban, hesoluong;
    public:
        CanBo() {};
        CanBo(string manv, string hoten, int namsinh, float luongcoban, float hesoluong) 
        : NhanSu(manv, hoten, namsinh), luongcoban(luongcoban), hesoluong(hesoluong) {};

        float TienLuong(CanBo cb) {
            return cb.luongcoban * cb.hesoluong;
        }

        friend istream& operator >> (istream&, CanBo&);
        friend ostream& operator << (ostream&, CanBo);
        CanBo * SapXepTheoLuongGiamDan(CanBo*, int);

};


istream& operator >> (istream& input, CanBo &cb) {
    cout << "\nNhap vao manv: "; getline(input, cb.manv);
    cout << "Nhap vao hoten: "; getline(input, cb.hoten);
    cout << "Nhap vao namsinh: "; input >> cb.namsinh;
    cout << "Nhap vao luongcoban: "; input >> cb.luongcoban;
    cout << "Nhap vao hesoluong: "; input >> cb.hesoluong;
    return input;
}


ostream& operator << (ostream& output, CanBo cb) {
    output << "\nManv: " << cb.manv << endl;
    output << "Hoten: " << cb.hoten << endl;
    output << "Namsinh: " << cb.namsinh << endl;
    output << "Luongcoban: " << cb.luongcoban << endl;
    output << "Hesoluong: " << cb.hesoluong << endl;
    return output;
}


CanBo * CanBo::SapXepTheoLuongGiamDan(CanBo *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (arr->TienLuong(arr[i]) < arr->TienLuong(arr[j])) {
                CanBo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}


int main() {
    int n; cout << "Nhap Vao N Can Bo: "; cin >> n;
    CanBo *arr = new CanBo[n];

    for(int i = 0; i < n; i++) {
        cin.ignore();
        cout << "\nNhap Vao Can Bo Thu " << i + 1 << endl;
        cin >> arr[i];
    }

    arr->SapXepTheoLuongGiamDan(arr, n);
    cout << "\n\t===> DANH SACH CAN BO CO LUONG GIAM DAN <===";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    delete arr;
    return 0;
}


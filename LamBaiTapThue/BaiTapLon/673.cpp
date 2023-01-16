/*
    Viết chương trình thực hiện yêu cầu sau:
        a. Nhập mảng một chiều các nhân viê(NHAN VIEN). Biết rằng một mã nhân vieen gồm những 
        thành phần sau:
            - Mã nhân viên: chuỗi tối da 5 ký tự.
            - Tên nhân viên: chuỗi gồm 30 ký tự.
            - Lương nhân viên: kiểu số thực.
        b. Xuất mảng.
        c. Tìm nhân viên có lương cao nhất trong mảng.
        d. Tính tổng lương các nhân viên.
        e. Sắp xếp mảng tăng dần theo lương nhân viên.

*/

#include<bits/stdc++.h>
using namespace std;

template<typename S, typename V, typename I>
class THONGTIN {
protected:
    S maNhanVien;
    S tenNhanVien;

public:
    THONGTIN<S, V, I>() {
        this->maNhanVien = "";
        this->tenNhanVien = "";
    }
    THONGTIN<S, V, I>(S maNhanVien, S tenNhanVien) {
        this->maNhanVien = maNhanVien;
        this->tenNhanVien = tenNhanVien;
    }

    virtual ~THONGTIN<S, V, I>() {}
    virtual V print(I) = 0;
    virtual V print_line(I) = 0;
};

template<typename S, typename D, typename I, typename V>
class NHANVIEN : public THONGTIN<S, V, I> {
private:
    D luongNhanVien;

public:
    NHANVIEN<S, D, I, V>() {
        this->luongNhanVien = 0.0;
    }
    NHANVIEN<S, D, I, V> (S maNhanVien, S tenNhanVien, D luongNhanVien) 
    : THONGTIN<S, V, I>(maNhanVien, tenNhanVien) {}
    virtual ~NHANVIEN<S, D, I, V> () {}

    V nhapThongTinNhanVien(NHANVIEN<S, D, I, V> *&, I);
    V xuatThongTinNhanVien(NHANVIEN<S, D, I, V> *, I);

    // Overloading input. : nạp chồng toán tử nhập
    template<typename A, typename B, typename C, typename E> friend istream& operator >> (istream&, NHANVIEN<A, B, C, E> &);
    // Overloading output. : nạp chồng toán tử xuất
    template<typename A, typename B, typename C, typename E> friend ostream& operator << (ostream&, NHANVIEN<A, B, C, E> );

    V print(I);
    V print_line(I);

    I nhanVienCoLuongCaoNhat(NHANVIEN<S, D, I, V> *, I);
    D tongLuongCacNhanVien(NHANVIEN<S, D, I, V> *, I);
    NHANVIEN<S, D, I, V> * sapXepLuongNhanVienTangDan(NHANVIEN<S, D, I, V> *, I);

};


template<typename S, typename D, typename I, typename V>
V NHANVIEN<S, D, I, V>::print(I n) {
    for(I i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename S, typename D, typename I, typename V>
V NHANVIEN<S, D, I, V>::print_line(I n) {
    for(I i = 0; i < n; i++) 
        cout << "_";
    cout << " KET QUA ";
    for(I i = 0; i < n; i++) 
        cout << "_";
    cout << endl;
}

template<typename S, typename D, typename I, typename V>
istream& operator >> (istream& input, NHANVIEN<S, D, I, V> &nv) {
    cout << "\t\t\t+ Nhap Ma Nhan Vien: "; getline(input, nv.maNhanVien);
    cout << "\t\t\t+ Nhap Ten Nhan Vien: "; getline(input, nv.tenNhanVien);
    cout << "\t\t\t+ Nhap Luong Nhan Vien: "; input >> nv.luongNhanVien;
    return input;
}

template<typename S, typename D, typename I, typename V>
ostream& operator << (ostream& output, NHANVIEN<S, D, I, V> nv) {
    output << "\t\t\t+ Ma Nhan Vien: " << nv.maNhanVien << endl;
    output << "\t\t\t+ Ten Nhan Vien: " << nv.tenNhanVien << endl;
    output << "\t\t\t+ Luong Nhan Vien: " << nv.luongNhanVien << endl; 
    return output;
}

template<typename S, typename D, typename I, typename V>
V NHANVIEN<S, D, I, V>::nhapThongTinNhanVien(NHANVIEN<S, D, I, V> *&arr, I n) {
    cout << endl << endl;
    cout << "\t\t"; arr->print(50);
    for(I i = 0; i < n; i++) {
        cin.ignore();
        cout << "\n\t\t* NHAP VAO THONG TIN NHAN VIEN THU " << i + 1 << ": " << endl;
        cin >> arr[i];  // nạp chồng toán tử nhập.
    }
    cout << "\t\t"; arr->print(50);
    cout << endl;
}

template<typename S, typename D, typename I, typename V>
V NHANVIEN<S, D, I, V>::xuatThongTinNhanVien(NHANVIEN<S, D, I, V> *arr, I n) {
    cout << endl << endl;
    cout << "\t\t"; arr->print_line(21); // ket qua.
    cout << "\n\t\t<=> XUAT RA THONG TIN CUA CAC NHAN VIEN <=> " << endl;
    for(I i = 0; i < n; i++) {
        cout << "\n\t\t\t*THONG TIN CUA NHAN VIEN THU " << i + 1 << ": " << endl;
        cout << arr[i]; // nạp chồng toán tử xuất.
    }
    cout << "\t\t"; arr->print(50);
    cout << endl;
}

template<typename S, typename D, typename I, typename V>
I NHANVIEN<S, D, I, V>::nhanVienCoLuongCaoNhat(NHANVIEN<S, D, I, V> *arr, I n) {
    D ans = arr[0].luongNhanVien;
    I result = 0;
    I i = 0;
    while(i < n) {
        if (arr[i].luongNhanVien > ans) {
            ans = arr[i].luongNhanVien;
            result = i;
        }
        i++;
    }
    return result;
}

template<typename S, typename D, typename I, typename V>
D NHANVIEN<S, D, I, V>::tongLuongCacNhanVien(NHANVIEN<S, D, I, V> *arr, I n) {
    D result = 0.0;
    for(I i = 0; i < n; i++) {
        result += arr[i].luongNhanVien;
    }
    return result;
}

template<typename S, typename D, typename I, typename V>
NHANVIEN<S, D, I, V> * NHANVIEN<S, D, I, V>::sapXepLuongNhanVienTangDan(NHANVIEN<S, D, I, V> *arr, I n) {
    for(I i = 0; i < n - 1; i++) {
        for(I j = i + 1; j < n; j++) {
            if(arr[i].luongNhanVien > arr[j].luongNhanVien) {
                NHANVIEN<S, D, I, V> temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main() {
    system("cls");
    int n; cout << "\t\tNHAP VAO SO LUONG NHAN VIEN: "; cin >> n;
    NHANVIEN<string, double, int, void> *arr = new NHANVIEN<string, double, int, void>[n];

    while(true) {
        cout << endl << endl << endl;
        cout << "\t\t******************** MENU *********************" << endl;
        cout << "\t\t** 1. Nhap Vao Thong Tin Nhan Vien.          **" << endl;
        cout << "\t\t** 2. Xuat Thong Tin Nhan Vien.              **" << endl;
        cout << "\t\t** 3. Thong Tin Nhan Vien Co Luong Cao Nhat. **" << endl;
        cout << "\t\t** 4. Tong Luong Cac Nhan Vien.              **" << endl;
        cout << "\t\t** 5. Sap Xep Luong Nhan Vien Tang Dan.      **" << endl;
        cout << "\t\t** 0. Ket Thuc Chuong Trinh.                 **" << endl;
        cout << "\t\t***********************************************" << endl;

        cout << "\t\t"; arr->print(47);
        int lc; cout << "\t\t=> Nhap vao lua chon: "; cin >> lc;
        switch(lc) {
            case 1: {
                arr->nhapThongTinNhanVien(arr, n);
                break;
            }
            case 2: {
                arr->xuatThongTinNhanVien(arr, n);
                break;
            }
            case 3: {
                cout << endl << endl;
                cout << "\t\t"; arr->print_line(21); // ket qua.
                cout << "\n\t\t<=> THONG TIN NHAN VIEN CO LUONG CAO NHAT !!!" << endl;
                int ans = arr->nhanVienCoLuongCaoNhat(arr, n);
                cout << arr[ans];
                cout << "\t\t"; arr->print(50); cout << endl;
                break;
            }
            case 4: {
                cout << endl << endl;
                cout << "\t\t"; arr->print_line(21); // ket qua.
                cout << "\n\t\t\t*TONG LUONG CAC NHAN VIEN: " << arr->tongLuongCacNhanVien(arr, n) << endl;
                cout << "\t\t"; arr->print(50); cout << endl;
                break;
            }
            case 5:  {
                cout << endl << endl;
                cout << "\t\t"; arr->print_line(21); // ket qua.
                arr->sapXepLuongNhanVienTangDan(arr, n);
                cout << "\t\t\t+> Da Sap Xep Theo Luong Tang Dan" << endl;
                cout << "\t\t\t=> Lua Chon 2 De Xem Da Duoc Sap Xep" << endl;
                cout << "\t\t"; arr->print(50); cout << endl;
                break;
            }
            default:
                cout << "\n\t\t\t=> CHUONG TRINH DA KET THUC <=" << endl << endl;
                return 0;
        }

    }

    cin.get();
    return 0;
}

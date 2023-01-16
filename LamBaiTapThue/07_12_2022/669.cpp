/*
    Viết chương trình thực hiện những yêu cầu sau:
    a. Nhập mảng một chiều các vé xem phim (VE). Biết rằng một vé xem phim gồm những thành phần sau:
    - Tên phim: chuỗi tối đa 20 ký tự.
    - Giá tiền: kiểu số nguyên 4 byte.
    - Xuất chiều: kiểu thời gian (THOIGIAN).
    - Ngày xem: kiểu dữ liệu ngày (NGAY).
    b. Xuất mảng.
    c. Tính tổng giá tiền của tất cả các vé trong mảng.
    d. Sắp xếp các phần tử trong mảng tăng dần theo ngày xem và xuất chiếu.
*/

#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define max 100

template<typename Sh, typename T, typename V>   // Template
class ThongTin {                    // Interface OOP
private:                            // Encapsulation
    Sh tenPhim[20];
    T giaTien;
public:
    ThongTin<Sh, T, V>() : giaTien(0) {}
    ThongTin<Sh, T, V>(Sh tenPhim, T giaTien) : tenPhim(tenPhim), giaTien(giaTien) {}

    Sh& getTenPhim() { return this->tenPhim; }  // getter
    T& getGiaTien() { return this->giaTien; }   // getter

    V NhapThongTin_VeXemPhim(); 
    V XuatThongTin_VeXemPhim();

    virtual ~ThongTin<Sh, T, V>() {} // pure virtual 
    virtual V print(T) = 0;         // Polymophythms 
    virtual V print_line(T) = 0;    // Polymophythms 
};

template<typename Sh, typename T, typename V> V ThongTin<Sh, T, V>::NhapThongTin_VeXemPhim() {
    cout << "\t\t\t\t+ Nhap Ten Phim: "; cin.getline(tenPhim, 30);
    cout << "\t\t\t\t+ Nhap Gia Tien: "; cin >> giaTien;
}

template<typename Sh, typename T, typename V> V ThongTin<Sh, T, V>::XuatThongTin_VeXemPhim() {
    cout << "\t\t\t\t+ Ten Phim: " << tenPhim << endl;
    cout << "\t\t\t\t+ Gia Tien: " << giaTien << endl;
}

template<typename Sh, typename T, typename V>   // Template
class VeXemPhim : public ThongTin<Sh, T, V> {  // Inheritance
private:    
    T ngayChieu;
    T thangChieu;
    T namChieu;
    T ngayXem;
public:
    VeXemPhim<Sh, T, V>() {}
    VeXemPhim<Sh, T, V>(Sh tenPhim[20], T giaTien, T ngayChieu, T thangChieu, T namChieu, T ngayXem)
    : ThongTin<Sh, T, V>(tenPhim, giaTien), ngayChieu(ngayChieu), thangChieu(thangChieu), namChieu(namChieu), ngayXem(ngayXem) {} 
    virtual ~VeXemPhim<Sh, T, V>() { ngayChieu = thangChieu = namChieu = ngayXem = 0; }

    T& getNgayChieu() { return this->ngayChieu; }
    T& getThangChieu() { return this->thangChieu; }
    T& getNamChieu() { return this->namChieu; }
    T& getNgayXem() { return this->ngayXem; }

    //  operator input and operator output
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, VeXemPhim<A, B, C>&);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, VeXemPhim<A, B, C>);

    bool operator > (VeXemPhim<Sh, T, V> vxp) {         // Operator >
        return this->getNgayXem() > vxp.getNgayXem(); 
    }

    V NhapThongTin_VeXemPhim();     // @overriding
    V XuatThongTin_VeXemPhim();     // @overriding

    T Tong_Gia_Tien_Ve_Trong_Mang(VeXemPhim<Sh, T, V> *, T);
    VeXemPhim<Sh, T, V> * Sap_Xep_Tang_Dan(VeXemPhim<Sh, T, V> *, T);

    V print(T);                     // Implements abstract lass 
    V print_line(T);                // Implements abstract lass 
    static V Xu_Ly_Thong_Tin();
};

template<typename Sh, typename T, typename V> V VeXemPhim<Sh, T, V>::NhapThongTin_VeXemPhim() {
    ThongTin<Sh, T, V>::NhapThongTin_VeXemPhim();
    cout << "\t\t\t\t- Nhap Xuat Chieu: " << endl;
    cout << "\t\t\t\t  + Nhap Ngay Chieu: "; cin >> ngayChieu;
    cout << "\t\t\t\t  + Nhap Thang Chieu: "; cin >> thangChieu;
    cout << "\t\t\t\t  + Nhap Nam Chieu: "; cin >> namChieu;
    cout << "\t\t\t\t+ Nhap Ngay Xem: "; cin >> ngayXem;
}

template<typename Sh, typename T, typename V> V VeXemPhim<Sh, T, V>::XuatThongTin_VeXemPhim() {
    ThongTin<Sh, T, V>::XuatThongTin_VeXemPhim();
    cout << "\t\t\t\t+ Xuat Chieu: " << ngayChieu << "/";
    cout << thangChieu << "/" << namChieu << endl;
    cout << "\t\t\t\t+ Ngay Xem: " << ngayXem << endl;      
}

template<typename Sh, typename T, typename V>
V VeXemPhim<Sh, T, V>::print(T n) { for(T i = 0; i < n; i++)  cout << "_"; cout << endl; }

template<typename Sh, typename T, typename V>
V VeXemPhim<Sh, T, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename Sh, typename T, typename V>
istream& operator >> (istream& input, VeXemPhim<Sh, T, V> &vxp) {
    vxp.NhapThongTin_VeXemPhim();
    return input;
}

// Convert Integer to String in OOP
template<typename Sh, typename T, typename V>
ostream& operator << (ostream& output, VeXemPhim<Sh, T, V> vxp) {
    vxp.XuatThongTin_VeXemPhim();
    return output;
}

template<typename Sh, typename T, typename V>
T VeXemPhim<Sh, T, V>::Tong_Gia_Tien_Ve_Trong_Mang(VeXemPhim<Sh, T, V> * arr, T n) {
    T sum = 0;
    for(T i = 0; i < n; i++) {
        sum += arr[i].getGiaTien();
    }
    return sum;
}

template<typename Sh, typename T, typename V>
VeXemPhim<Sh, T, V> * VeXemPhim<Sh, T, V>::Sap_Xep_Tang_Dan(VeXemPhim<Sh, T, V> * arr, T n) {
    for(T i = 0; i < n - 1; i++) {
        for(T j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    return arr;
}

template<typename Sh, typename T, typename V>
V VeXemPhim<Sh, T, V>::Xu_Ly_Thong_Tin() {
    VeXemPhim<Sh, T, V> *arr = new VeXemPhim<Sh, T, V>[max];
    while(true) {
        cout << endl << endl << endl;
        cout << "\t\t****************************************************" << endl;
        cout << "\t\t**  __________________ MENU ____________________  **" << endl;
        cout << "\t\t**   1. Nhap Vao Thong Tin Cac Ve Xem Phim.       **" << endl;
        cout << "\t\t**   2. In Danh Sach Thong Tin Cac Ve Xem Phim.   **" << endl;
        cout << "\t\t**   3. Nam Co Nhieu Luan Van Nhat Danh Sach.     **" << endl;
        cout << "\t\t**   4. Liet Ke Luan Van Thuc Hien Gan Nhat.      **" << endl;
        cout << "\t\t**   0. Ket Thuc Chuong Trinh.                    **" << endl;
        cout << "\t\t**  ____________________________________________  **" << endl;
        cout << "\t\t****************************************************" << endl;

        cout << "\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;
        switch(lc) {
            case 1:
                cout << "\t\t"; arr->print(53);
                int n; cout << "\n\t\t\t<=> NHAP SO LUONG VE XEM PHIM: "; cin >> n;
                cout << "\t\t\t"; arr->print(35);
                for(T i = 0; i < n; i++) {
                    cin.ignore();
                    cout << "\n\t\t\t<=> Nhap Thong Tin Ve Xem Phim " << i + 1 << " <=>" << endl;
                    cin >> arr[i];
                    cout << "\t\t\t"; arr->print(39);
                }   
                cout << "\t\t"; arr->print(52); cout << endl;
                break;
            case 2:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(22); // ket qua.
                for(T i = 0; i < n; i++) {
                    cout << "\n\t\t<=> Thong Tin Ve Xem Phim Thu " << i + 1 << " Trong Danh Sach <=>" << endl;
                    cout << arr[i];
                    cout << "\t\t\t"; arr->print(35);
                }
                cout << "\t\t"; arr->print(52); cout << endl;
                break;
            case 3:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(22); // ket qua.
                cout << "\n\t\t<=> Tong Gia Tien Cac Ve Xem Phim : " << arr->Tong_Gia_Tien_Ve_Trong_Mang(arr, n) << endl;
                cout << "\t\t"; arr->print(52); cout << endl;
                break;
            case 4:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(22); // ket qua.
                cout << "\n\t\t<=> Sap Xep Theo Ngay Xem/ Xuat Xem Tang Dan <=>" << endl;
                cout << "\t\t<=> Nhan phim 2 de xem thong tin <=>" << endl;
                arr->Sap_Xep_Tang_Dan(arr, n);
                cout << "\t\t"; arr->print(52); cout << endl;
                break;
            default:
                cout << "\n\n\t\t\t!!! <KET THUC CHUONG TRINH> !!!" << endl;
                return;
        }
    }
    delete[] arr;
}

int main() {
    system("cls");
    VeXemPhim<char, int, void>::Xu_Ly_Thong_Tin();

    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\t\t\t*** Day-Month-Year: "<< ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    cout << "\t\t\t\t* Time: "<< 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << endl;
    cout << endl << endl << endl;

    cin.get();
    return 0;
};

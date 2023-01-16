/*
    Viết chương trình thực hiện các yêu cầu sau:
    a. Nhập mảng một chiều các lớp học (LOPHOC). Biết rằng một lớp học gồm những thành phần sau:
    - Tên lớp: chuỗi tối đa 30 ký tự.
    - Sĩ số: kiểu số nguyên 2 byte.
    - Danh sách các học sinh trong lớp (tối đa 50 học sinh).
    b. Xuất mảng.
    c. Tìm một lớp có chỉ số đông nhất.
    d. Tìm một học sinh có điểm trung bình lớn nhất.
*/

#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define max 100
#define size 50

template<typename Sh, typename T, typename V, typename F>   // Template
class HocSinh {                    // Interface OOP
private:                            // Encapsulation
    Sh hoTen[30];
	F diemTB;

public:
    HocSinh<Sh, T, V, F>() : diemTB(0.0) {}
    HocSinh<Sh, T, V, F>(Sh hoTen[30], F diemTB) : hoTen(hoTen), diemTB(diemTB) {}
    virtual ~HocSinh<Sh, T, V, F>() {}          // pure virtual 

    Sh& getHoTen() { return this->hoTen; }      // getter
    F& getDiemTB() { return this->diemTB; }     // getter

    V NhapThongTin_HocSinh(); 
    V XuatThongTin_HocSinh();

};

template<typename Sh, typename T, typename V, typename F> V HocSinh<Sh, T, V, F>::NhapThongTin_HocSinh() {
    cin.ignore();
    cout << "\t\t\t\t+ Nhap Ho Ten: "; cin.getline(hoTen, 30);
    cout << "\t\t\t\t+ Nhap Diem TB: "; cin >> diemTB;
}

template<typename Sh, typename T, typename V, typename F> V HocSinh<Sh, T, V, F>::XuatThongTin_HocSinh() {
    cout << "\t\t\t\t+ Ho Ten: " << hoTen << endl;
    cout << "\t\t\t\t+ Diem TB: " << diemTB << endl;
}

template<typename Sh, typename T, typename V, typename F>   // Template
class LopHoc : public HocSinh<Sh, T, V, F> {  // Inheritance
private:    
    Sh tenLop[30];
	T siSo;
	HocSinh<Sh, T, V, F> hs[size];

public:
    LopHoc<Sh, T, V, F>() {}
    LopHoc<Sh, T, V, F>(Sh hoTen[30], F diemTB, Sh tenLop[30], T siSo)
    : HocSinh<Sh, T, V, F>(hoTen, diemTB), tenLop(tenLop), siSo(siSo) {} 
    virtual ~LopHoc<Sh, T, V, F>() { siSo = 0; }

    Sh& getTenLop() { return this->tenLop; }
    T& getSiSo() { return this->siSo; }

    //  operator input and operator output
    template<typename A, typename B, typename C, typename D> friend istream& operator >> (istream&, LopHoc<A, B, C, D>&);
    template<typename A, typename B, typename C, typename D> friend ostream& operator << (ostream&, LopHoc<A, B, C, D>);

    V NhapThongTin_HocSinh();     // @overriding
    V XuatThongTin_HocSinh();     // @overriding

    bool operator > (LopHoc<Sh, T, V, F> lop) {
        return this->getSiSo() > lop.getSiSo();
    }

    bool operator == (LopHoc<Sh, T, V, F> lop) {
        return this->getSiSo() == lop.getSiSo();
    }


    V Lop_Co_Hoc_Sinh_Dong_Nhat(LopHoc<Sh, T, V, F> *, T);
    V Tim_1_HS_DiemTB_Lon_Nhat(LopHoc<Sh, T, V, F> *, T);

    V print(T);                     // Implements abstract lass 
    V print_line(T);                // Implements abstract lass 
    static V Xu_Ly_Thong_Tin();
};

template<typename Sh, typename T, typename V, typename F> V LopHoc<Sh, T, V, F>::NhapThongTin_HocSinh() {
    cout << "\t\t\t\t- Nhap Ten Lop: "; cin.getline(tenLop, 30);
    cout << "\t\t\t\t- Nhap Si So: "; cin >> siSo;
    for(T i = 0; i < siSo; i++) {
        cout << "\t\t\t   *Nhap Thong Tin Hoc Sinh Thu " << i + 1 << " *" << endl;
        hs[i].NhapThongTin_HocSinh(); 
    }
}   

template<typename Sh, typename T, typename V, typename F> V LopHoc<Sh, T, V, F>::XuatThongTin_HocSinh() {
    cout << "\t\t\t\t-> Ten Lop: " << tenLop << endl;
    cout << "\t\t\t\t-> Si So: " << siSo << endl ;
    for(T i = 0; i < siSo; i++) {
        cout << "\t\t\t   *Thong Tin Hoc Sinh Thu " << i + 1 << " *" << endl;
        hs[i].XuatThongTin_HocSinh();
    }
}

template<typename Sh, typename T, typename V, typename F>
V LopHoc<Sh, T, V, F>::print(T n) { for(T i = 0; i < n; i++)  cout << "_"; cout << endl; }

template<typename Sh, typename T, typename V, typename F>
V LopHoc<Sh, T, V, F>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename Sh, typename T, typename V, typename F>
istream& operator >> (istream& input, LopHoc<Sh, T, V, F> &vxp) {
    vxp.NhapThongTin_HocSinh();
    return input;
}

// Convert Integer to String in OOP
template<typename Sh, typename T, typename V, typename F>
ostream& operator << (ostream& output, LopHoc<Sh, T, V, F> vxp) {
    vxp.XuatThongTin_HocSinh();
    return output;
}

template<typename Sh, typename T, typename V, typename F>
V LopHoc<Sh, T, V, F>::Lop_Co_Hoc_Sinh_Dong_Nhat(LopHoc<Sh, T, V, F> * arr, T n) {
    T MaxIndex = 0, IndexOf[max], j = 0, count = 0;
    for(T i = 0; i < n; i++) 
        if (arr[i] > arr[i + 1]) 
            MaxIndex = i;
    for(T i = 0; i < n; i++) 
        if (arr[MaxIndex] == arr[i]) {
            IndexOf[j++] = i;
            ++count;
        }
    for(T i = 0; i < count; i++) {
        cout << arr[IndexOf[i]];
        cout << "\t\t\t"; arr->print(39);
    }
}

template<typename Sh, typename T, typename V, typename F>
V LopHoc<Sh, T, V, F>::Tim_1_HS_DiemTB_Lon_Nhat(LopHoc<Sh, T, V, F> * arr, T n) {
    T index2 = 0, index1 = 0;
    F MaxOf = arr[0].hs[0].getDiemTB();
    for(T i = 0; i < n; i++) {
        for(T j = 0; j < arr[i].getSiSo(); j++) {
            if (arr[i].hs[j].getDiemTB() > MaxOf) {
                index1 = i;
                index2 = j;
                MaxOf = arr[index1].hs[index2].getDiemTB();
            }
        }
    }
    arr[index1].hs[index2].XuatThongTin_HocSinh();
}

template<typename Sh, typename T, typename V, typename F>
V LopHoc<Sh, T, V, F>::Xu_Ly_Thong_Tin() {
    LopHoc<Sh, T, V, F> *arr = new LopHoc<Sh, T, V, F>[max];
    while(true) {
        cout << endl << endl << endl;
        cout << "\t\t****************************************************" << endl;
        cout << "\t\t**  __________________ MENU ____________________  **" << endl;
        cout << "\t\t**   1. Nhap Thong Tin Cac Hoc Sinh Trong Lop.    **" << endl;
        cout << "\t\t**   2. In Danh Sach Cac Hoc Sinh Trong Lop.      **" << endl;
        cout << "\t\t**   3. Thong Tin Cua Lop Si So Dong Nhat.        **" << endl;
        cout << "\t\t**   4. Thong Tin Hoc Sinh Co Diem TB Lon Nhat.   **" << endl;
        cout << "\t\t**   0. Ket Thuc Chuong Trinh.                    **" << endl;
        cout << "\t\t**  ____________________________________________  **" << endl;
        cout << "\t\t****************************************************" << endl;

        cout << "\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;
        switch(lc) {
            case 1:
                cout << "\t\t"; arr->print(53);
                int n; cout << "\n\t\t\t <=> NHAP VAO SO LUONG LOP HOC: "; cin >> n;
                cout << "\t\t\t"; arr->print(35);
                for(T i = 0; i < n; i++) {
                    cin.ignore();
                    cout << "\n\t\t\t <=> NHAP THONG TIN LOP HOC THU " << i + 1 << " <=>" << endl;
                    cin >> arr[i];
                    cout << "\t\t\t"; arr->print(39);
                }   
                cout << "\t\t"; arr->print(52); cout << endl;
                break;
            case 2:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(22);
                for(T i = 0; i < n; i++) {
                    cout << "\n\t\t <=> Thong Tin Ve Hoc Sinh " << i + 1 << " Trong Danh Sach <=>" << endl;
                    cout << arr[i];
                    cout << "\t\t\t"; arr->print(35);
                }
                cout << "\t\t"; arr->print(52); cout << endl;
                break;
            case 3:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(22);
                cout << "\t\t  <=> THONG TIN LOP HOC SO SI SO DONG NHAT <=>" << endl;
                arr->Lop_Co_Hoc_Sinh_Dong_Nhat(arr, n);
                cout << "\t\t"; arr->print(52); cout << endl;
                break;
            case 4:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(22);
                cout << "\t\t\t<=> THONG TIN HOC CO DIEM TB LON NHAT <=>" << endl;
                arr->Tim_1_HS_DiemTB_Lon_Nhat(arr, n);
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
    LopHoc<char, int, void, float>::Xu_Ly_Thong_Tin();

    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\t\t\t*** Day-Month-Year: "<< ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    cout << "\t\t\t\t* Time: "<< 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << endl;
    cout << endl << endl << endl;

    cin.get();
    return 0;
};

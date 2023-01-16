/*
    Viết chương trình thực hiện những yêu cầu sau:
    a. Nhập mảng một chiều các cầu thủ. Biết rằng một cầu thủ gồm những thành phần sau:
        - Mã cầu thủ: chuỗi tối đa 10 ký tự.
        - Tên cầu thủ: chuỗi tối đa 30 ký tự.
        - Ngày sinh: kiểu dữ liệu ngày, tháng, năm.
    b. Xuất mảng.
    c. Liệt kê danh sách các cầu thủ nhỏ tuổi nhất trong mảng.
    d. Sắp xếp các cầu thủ giảm dần theo tuổi.
    
*/

#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

// Interface OOP
template<typename S, typename T, typename V>
class ThongTin {
protected:
    S maCauThu;
    S tenCauThu;

public:
    // Constructor no parameter
    ThongTin<S, T, V>() {
        this->maCauThu = this->tenCauThu = "";
    }
    // Constructor parameter
    ThongTin<S, T, V>(S maCauThu, S tenCauThu) {
        this->maCauThu = maCauThu;
        this->tenCauThu = tenCauThu;
    }

    S& getMaCauThu() { return this->maCauThu; }
    S& getTenCauThu() { return this->tenCauThu; }

    virtual ~ThongTin<S, T, V>() {}
    virtual V print(T) = 0;         // Polymophythms
    virtual V print_line(T) = 0;    // Polymophythms

};


template<typename S, typename T, typename V>
class CauThu : public ThongTin<S, T, V> {
private:  
    T ngaySinh; 
    T thangSinh; 
    T namSinh;

public:
    CauThu<S, T, V>() {}
    // Initializer list OOP
    CauThu<S, T, V>(S maCauThu, S tenCauThu, T ngaySinh, T thangSinh, T namSinh) 
    : ThongTin<S, T, V>(maCauThu, tenCauThu), ngaySinh(ngaySinh), thangSinh(thangSinh), 
    namSinh(namSinh) {}

    virtual ~CauThu<S, T, V>() {
        this->ngaySinh = this->thangSinh = this->namSinh = 0;
    }

    T& getNgaySinh() { return this->ngaySinh; }
    T& getThangSinh() { return this->thangSinh; }
    T& getNamSinh() { return this->namSinh; }

    //  nạp chồng toán tử nhập.
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, CauThu<A, B, C>&);
    //  nạp chồng toán tử xuất.
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, CauThu<A, B, C>);
    
    V NhapThongTinCauThu(CauThu<S, T, V> *, T);
    V XuatThongTinCauThu(CauThu<S, T, V> *, T);
    V CauThuTuoiNhoNhat(CauThu<S, T, V> *, T);
    CauThu<S, T, V> * SapXepGiamDanTheoTuoi(CauThu<S, T, V> *, T);

    V print(T);         // Implements abstract lass ThongTin
    V print_line(T);    // Implements abstract lass ThongTin
    static V Xu_Ly_Thong_Tin();
};


template<typename S, typename T, typename V>
V CauThu<S, T, V>::print(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename S, typename T, typename V>
V CauThu<S, T, V>::print_line(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << " KET QUA ";
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << endl;
}

template<typename S, typename T, typename V>
istream& operator >> (istream& input, CauThu<S, T, V> &ct) {
    cout << "\t\t\t+ Nhap Ten Cau Thu: "; getline(input, ct.tenCauThu);
    cout << "\t\t\t+ Nhap Ma Cau Thu: "; getline(input, ct.maCauThu);
    cout << "\t\t\t+ Nhap Ngay Sinh: "; input >> ct.ngaySinh;
    cout << "\t\t\t+ Nhap Thang Sinh: "; input >> ct.thangSinh;
    cout << "\t\t\t+ Nhap Nam Sinh: "; input >> ct.namSinh;
    return input;
}

// Convert Integer to String in OOP
template<typename S, typename T, typename V>
ostream& operator << (ostream& output, CauThu<S, T, V> ct) {
    S newNgaySinh = to_string(ct.ngaySinh);
    S newThangSinh = to_string(ct.thangSinh);
    S newNamSinh = to_string(ct.namSinh);
    if (newNgaySinh.length() == 1) {
        newNgaySinh = "0" + newNgaySinh;
    }
    if (newThangSinh.length() == 1) {
        newThangSinh = "0" + newThangSinh;
    }
    cout << "\t\t\t+ Ten Cau Thu: " << ct.tenCauThu << endl;
    cout << "\t\t\t+ Ma Cau Thu: " << ct.maCauThu << endl;
    cout << "\t\t\t+ Nam Sinh: " << newNgaySinh << "/" << newThangSinh << "/" << newNamSinh << endl;
    return output;
}

template<typename S, typename T, typename V>
V CauThu<S, T, V>::NhapThongTinCauThu(CauThu<S, T, V> *arr, T n) {
    cout << endl << endl;
    cout << "\t\t"; arr->print_line(21); // ket qua.
    cout << "\n\t\t==> NHAP THONG TIN CAC CAU THU VAO DANH SACH <==" << endl;
    for(T i = 0; i < n; i++) {
        cin.ignore();
        cout << "\n\t\t<=> Nhap Vao Thong Tin Cau Thu " << i + 1 << " <=>" << endl;
        cin >> arr[i];
        cout << "\t"; arr->print(33);
    }
    cout << "\t\t"; arr->print(50);
    cout << endl;
}

template<typename S, typename T, typename V>
V CauThu<S, T, V>::XuatThongTinCauThu(CauThu<S, T, V> *arr, T n) {
    cout << endl << endl; cout << "\t\t";
    arr->print_line(21); // ket qua.
    cout << "\n\t\t==> THONG TIN CAC CAU THU VUA NHAP VAO DANH SACH <==" << endl;
    for(T i = 0; i < n; i++) {
        cout << "\n\t\t<=> Thong Tin Cua Cau Thu Thu " << i + 1 << " Trong Danh Sach <=>" << endl;
        cout << arr[i];
        cout << "\t\t\t"; arr->print(33);
    }
    cout << "\t\t"; arr->print(50);
    cout << endl;
}

template<typename S, typename T, typename V>
V CauThu<S, T, V>::CauThuTuoiNhoNhat(CauThu<S, T, V> *arr, T n) {
    cout << endl << endl;
    cout << "\t\t"; arr->print_line(21); // ket qua.
    cout << "\n\t\t <==> CAU THU CO TUOI NHO NHAT TRONG DANH SACH <==> " << endl;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if ((2022 - arr[i].getNamSinh()) > (2022 - arr[j].getNamSinh())) {
                CauThu<S, T, V> temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "\n\t\t<=> Thong Tin Cua Cau Thu Thu 1 Trong Danh Sach <=>" << endl;
    cout << arr[0] << endl;
    int index = 0;
    while(index < n) {
        if ((2022 - arr[index].getNamSinh()) == (2022 - arr[index + 1].getNamSinh())) {
            cout << "\n\t\t<=> Thong Tin Cua Cau Thu Thu " << index + 2 << " Trong Danh Sach <=>" << endl;
            cout << arr[index + 1] << endl;
        }
        index++;
    }

    cout << "\t\t"; arr->print(50);
    cout << endl;
}

template<typename S, typename T, typename V>
CauThu<S, T, V> * CauThu<S, T, V>::SapXepGiamDanTheoTuoi(CauThu<S, T, V> *arr, T n) {
    cout << "\n\t\t<==> DA SAP XEP CAU THU THEO TUOI DAM DAN <==> " << endl;
    cout << "\n\t\t\t==> Nhap Phim 2 De In Thong Tin <===" << endl;
    for(T i = 0; i < n - 1; i++) {
        for(T j = n - 1; j > i; j--) {
            if ((2022 - arr[j - 1].getNamSinh()) < (2022 - arr[j ].getNamSinh())) {
                CauThu temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

template<typename S, typename T, typename V>
V CauThu<S, T, V>::Xu_Ly_Thong_Tin() {
    int n; cout << "\n\t\tNhap Vao N Cau Thu: "; cin >> n;
    CauThu<S, T, V> *arr = new CauThu<S, T, V>[n];
    while(true) {
        cout << endl << endl << endl;
        cout << "\t\t****************************************************" << endl;
        cout << "\t\t**  __________________ MENU ____________________  **" << endl;
        cout << "\t\t**   1. Nhap Vao Thong Tin Cau Thu.               **" << endl;
        cout << "\t\t**   2. In Danh Sach Thong Tin Cac Cau Thu.       **" << endl;
        cout << "\t\t**   3. Thong Tin Cau Thu Tuoi Nho Nhat.          **" << endl;
        cout << "\t\t**   4. Sap Xep Theo Tuoi Giam Dan.               **" << endl;
        cout << "\t\t**   0. Ket Thuc Chuong Trinh.                    **" << endl;
        cout << "\t\t**  ____________________________________________  **" << endl;
        cout << "\t\t****************************************************" << endl;

        cout << "\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;
        switch(lc) {
            case 1:
                arr->NhapThongTinCauThu(arr, n);
                break;
            case 2:
                arr->XuatThongTinCauThu(arr, n);
                break;
            case 3:
                arr->CauThuTuoiNhoNhat(arr, n);
                break;
            case 4: 
                cout << endl << endl;
                cout << "\t\t"; arr->print_line(21); // ket qua.
                arr->SapXepGiamDanTheoTuoi(arr, n);
                cout << "\t\t"; arr->print(50);
                cout << endl;
                break;
            default:
                cout << "\n\t\t\tKET THUC CHUONG TRINH" << endl << endl << endl;
                return;
        }
    }
    delete[] arr;
}

int main() {
    system("cls");
    CauThu<string, int, void>::Xu_Ly_Thong_Tin();
    cin.get();
    return 0;
};



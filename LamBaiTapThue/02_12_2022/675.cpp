
/*
    Viết chương trình thực hiện các yêu cầu sau:
    a. Nhập mảng một chiều các luận văn(LUANVAN). Biết rằng một luận văn gồm những thành phần sau:
    - Mã luận văn: chuỗi tối đa 10 ký tự.
    - Tên luận văn: chuỗi tối đa 100 ký tự.
    - Họ tên sinh viên thực hiện: chuỗi tối đa 30 ký tự.
    - Họ tên giáo viên hướng dẫn: chuỗi tối đa 30 ký tự.
    - Năm thực hiện: kiểu số nguyên 2 byte.
    b. Xuất mảng.
    c. Tìm năm có nhiều luận văn nhất.
    d. Liệt kê các luận văn thực hiện gần nhất.

*/

#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define max 100

// Interface OOP
template<typename S, typename T, typename V>
class ThongTin {
protected:  // Encapsulation
    S maLV;
    S tenLV;
    S hoTenSV;
    S hoTenGV;
public:
    ThongTin<S, T, V>() {
        this->maLV = this->tenLV = this->hoTenSV = this->hoTenGV = ""; // Constructor no parameter
    }
    ThongTin<S, T, V>(S maLV, S tenLV, S hoTenSV, S hoTenGV) { // Constructor parameter
        this->maLV = maLV;
        this->tenLV = tenLV;
        this->hoTenSV = hoTenSV;
        this->hoTenGV = hoTenGV;
    }

    V NhapThonTin() {   // @overriding
        cout << "\t\t\t\t+ Nhap Ma Luan Van: "; getline(cin, maLV);
        cout << "\t\t\t\t+ Nhap Ten Luan Van: "; getline(cin, tenLV);
        cout << "\t\t\t\t+ Nhap Ho Ten SV: "; getline(cin, hoTenSV);
        cout << "\t\t\t\t+ Nhap Ho Ten GV: "; getline(cin, hoTenGV);
    }

    V XuatThongTin() {  // @overriding
        cout << "\t\t\t\t+ Ma Luan Van: " << maLV << endl;
        cout << "\t\t\t\t+ Ten Luan Van: " << tenLV << endl;
        cout << "\t\t\t\t+ Ho Ten SV: " << hoTenSV << endl;
        cout << "\t\t\t\t+ Ho Ten GV: " << hoTenGV << endl;
    }

    S& getMaLV() { return this->maCauThu; }
    S& getTenLV() { return this->tenCauThu; }
    S& getHoTenSV() { return this->hoTenSV; }
    S& getHoTenGV() { return this->hoTenGV; }

    virtual ~ThongTin<S, T, V>() {} // pure virtual 
    virtual V print(T) = 0;         // Polymophythms 
    virtual V print_line(T) = 0;    // Polymophythms 
};

template<typename S, typename T, typename V>
class LuanVan : public ThongTin<S, T, V> {  // inheritance
private:    // Encapsulation
    T namTH;
public:
    LuanVan<S, T, V>() {} // constructor no parameter
    LuanVan<S, T, V>(S maLV, S tenLV, S hoTenSV, S hoTenGV, T namTH)   // Initializer list OOP
    : ThongTin<S, T, V>(maLV, tenLV, hoTenSV, hoTenGV), namTH(namTH) {}
    virtual ~LuanVan<S, T, V>() { this->namTH = 0; }

    T& getNamTH() { return this->namTH; }

    bool operator > (LuanVan<S, T, V> * arr) { 
        return this->getNamTH() > arr->getNamTH();
    }

    // @overriding  // Polymorphims
    V NhapThonTin() {
        ThongTin<S, T, V>::NhapThonTin(); 
        cout << "\t\t\t\t+ Nhap Nam Thuc Hien: "; cin >> namTH;
    }

    // @overriding  // Polymorphims
    V XuatThongTin() {
        ThongTin<S, T, V>::XuatThongTin();
        cout << "\t\t\t\t+ Nam Thuc Hien: " << namTH << endl;
    }

    //  operator input //  operator output
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, LuanVan<A, B, C>&);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, LuanVan<A, B, C>);

    V Nam_Co_Nhieu_Luan_Van_Nhat(LuanVan<S, T, V> *, T);
    V Cac_Luan_Van_Thuc_Hien_Gan_Nhat(LuanVan<S, T, V> *, T);
    V print(T);         // Implements abstract lass ThongTin
    V print_line(T);    // Implements abstract lass ThongTin
};

template<typename S, typename T, typename V> V LuanVan<S, T, V>::print(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename S, typename T, typename V> V LuanVan<S, T, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename S, typename T, typename V> istream& operator >> (istream& input, LuanVan<S, T, V> &lv) {
    lv.NhapThonTin();
    return input;
}

// Convert Integer to String in OOP
template<typename S, typename T, typename V> ostream& operator << (ostream& output, LuanVan<S, T, V> lv) {
    lv.XuatThongTin();
    return output;
}

template<typename S, typename T, typename V> V LuanVan<S, T, V>::Nam_Co_Nhieu_Luan_Van_Nhat(LuanVan<S, T, V> *arr, T n) {
    cout << endl << endl;
    cout << "\t\t"; arr->print_line(21); // ket qua.
    cout << "\n\t\t <==> NAM CO NHIEU LUAN VAN NHAT TRONG DANH SACH <==> " << endl;
    for(T i = 0; i < n; i++) {
        for(T j = i + 1; j < n; j++) {
            if (arr[i].namTH > arr[j].namTH) {
                swap(arr[i], arr[j]);
            }
        }
    }
    T count = 0, index = 0;
    for(T i = 0; i < n; i++) {
        T check = 1;
        if (arr[i].namTH == arr[i + 1].namTH && check >= count) {
            count++;
            check = count;
            index = i;
        }   
    }
    cout << "\t\t\tNam Thuc Hien: " << arr[index].namTH << endl;
    cout << "\t\t"; arr->print(52);
    cout << endl;
}

template<typename S, typename T, typename V> V LuanVan<S, T, V>::Cac_Luan_Van_Thuc_Hien_Gan_Nhat(LuanVan<S, T, V> *arr, T n) {
    cout << endl << endl;
    cout << "\t\t"; arr->print_line(21); // ket qua.
    for(T i = 0; i < n; i++) {
        for(T j = i + 1; j < n; j++) {
            if (arr[i].namTH < arr[j].namTH) {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "\t\t\t<=> TAT CA THONG TIN LUAN VAN THU 1 <=> " << endl;
    cout << arr[0];
    T result = arr[0].namTH;
    T index = 2;
    for(T i = 0; i < n; i++) {
        if(result == arr[i + 1].namTH) {
            cout << "\n\t\t\t<=> THONG TIN TAT CA LUAN VAN THU " << index++ << " <=> " << endl;
            cout << arr[i + 1];
        }
    }
    cout << "\t\t"; arr->print(52);
    cout << endl;
}

int main() {
    system("cls");

    LuanVan<string, int, void> *arr = new LuanVan<string, int, void>[max];
    while(true) {
        cout << endl << endl << endl;
        cout << "\t\t _____^_^____________ MENU ________^_^_________ " << endl;
        cout << "\t\t|   1. Nhap Vao Thong Tin Cac Luan Van.        |" << endl;
        cout << "\t\t|   2. In Danh Sach Thong Tin Cac Luan Van.    |" << endl;
        cout << "\t\t|   3. Nam Co Nhieu Luan Van Nhat Danh Sach.   |" << endl;
        cout << "\t\t|   4. Liet Ke Luan Van Thuc Hien Gan Nhat.    |" << endl;
        cout << "\t\t|   0. Ket Thuc Chuong Trinh.                  |" << endl;
        cout << "\t\t|______________________________________________|" << endl;
        cout << "\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;
        switch(lc) {
            case 1:
                int n; cout << "\n\t\t\t<=> NHAP VAO N LUAN VAN: "; cin >> n;
                cout << endl << endl;
                cout << "\t\t"; arr->print(52);
                cout << "\n\t\t==> NHAP THONG TIN CAC LUAN VAN VAO DANH SACH <==" << endl;
                for(int i = 0; i < n; i++) {
                    cin.ignore();
                    cout << "\n\t\t\t<=> Nhap Vao Thong Tin Luan Van " << i + 1 << " <=>" << endl;
                    cin >> arr[i];
                    cout << "\t\t\t"; arr->print(39);
                }
                cout << "\t\t"; arr->print(52);
                cout << endl;
                break;
            case 2:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(21); // ket qua.
                cout << "\n\t\t==> THONG TIN CAC LUAN VAN VUA NHAP VAO DANH SACH <==" << endl;
                for(int i = 0; i < n; i++) {
                    cout << "\n\t\t<=> Thong Tin Cua Luan Van Thu " << i + 1 << " Trong Danh Sach <=>" << endl;
                    cout << arr[i];
                    cout << "\t\t\t"; arr->print(35);
                }
                cout << "\t\t"; arr->print(52);
                cout << endl;
                break;
            case 3:
                arr->Nam_Co_Nhieu_Luan_Van_Nhat(arr, n);
                break;
            case 4: 
                arr->Cac_Luan_Van_Thuc_Hien_Gan_Nhat(arr, n);
                break;
            default:
                cout << "\n\t\t\t!!! <KET THUC CHUONG TRINH> !!!" << endl;
                return 0;
        }
    }
    
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\t\t\t* Day-Month-Year: "<< ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    cout << "\t\t\t* Time: "<< 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << endl;
    cout << endl << endl << endl;

    delete[] arr;
    cin.get();
    return 0;
};



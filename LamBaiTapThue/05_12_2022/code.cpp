/*
    Tìm giá trị lớn nhất trên một dòng trong ma trận các số thực.
        
        - Tính đóng gói: private
        - Tính đa hình: (chồng toán tử nhập(istream) - xuất(ostream)), (ghi đè(Overriding))
            (nạp chồng toán tử so sánh (operator >))
        - Tính kế thừa: class MaTrix : public ThongTin<T, D, V>
        - Tính trừu tượng: virtual, interface  
    
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T, typename D, typename V> // template(genaric)
class ThongTin {    // abstract class 
private:            // tính khuôn hình(đóng gói)
    int m, n;       // khai báo m hàng và n cột
public:
    ThongTin<T, D, V>() {}      // constructor không tham số
    ThongTin<T, D, V>(T m, T n) : m(m), n(n) {} // constructor có tham số và kế thừa constructor ThongTin
    virtual ~ThongTin<T, D, V>() {  // hàm hủy constructor ảo
        this->m = this->n = 0;
    }

    T& getM() { return this->m; }       // lấy giá trị hàng
    T& getN() { return this->n; }       // lấy giá trị cột

    V NhapThonTin() {
        cout << "\t\t<=> Nhap Vao Kich Thuoc Mang <=>" << endl;
        cout << "\t\t\t- Nhap So Hang: "; cin >> getM();
        cout << "\t\t\t- Nhap So Cot: "; cin >> getN();
    }

    V XuatThongTin() {
        cout << "\t\t<=> Gia Tri Lon Nhat Tren Tuong Dong <=>" << endl;
    }

    // tính đa hình (interface)
    virtual V print(T) = 0;         // Implements abstract lass 
    virtual V print_line(T) = 0;    // Implements abstract lass 
};

template<typename T, typename D, typename V> 
class MaTrix : public ThongTin<T, D, V> { // Inheritance
private:                // Encapsulation
    D arr[100][100];    
public:
    MaTrix<T, D, V>() {}    // Constructor
    ~MaTrix<T, D, V>() {}   // Destructor

    // @overriding  // Polymorphims
    V NhapThonTin() {
        ThongTin<T, D, V>::NhapThonTin();
        cout << "\t\t"; MaTrix<T, D, V>::print(50);
        cout << "\t\t<=> Nhap Vao Cac Phan Tu Mang <=>" << endl;
        for(T i = 0; i < MaTrix<T, D, V>::getM(); i++) {
            for(T j = 0; j < MaTrix<T, D, V>::getN(); j++) {
                cout << "\t\t\t+ Array["<<i<<"]["<<j<<"] = ";
                cin >> MaTrix<T, D, V>::arr[i][j];
            }
        }
    }
    // @overriding  // Polymorphims
    V XuatThongTin() {
        ThongTin<T, D, V>::XuatThongTin();
        for(T i = 0; i < MaTrix<T, D, V>::getM(); i++) {
            cout << "\t\t\t";
            for(T j = 0; j < MaTrix<T, D, V>::getN(); j++) {
                cout << MaTrix<T, D, V>::arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // chồng toán tử nhập và toán tử xuất mảng
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, MaTrix<A, B, C> &);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, MaTrix<A, B, C> ); 
 
    V Gia_Tri_Lon_Nhat_Tren_1_Dong(MaTrix<T, D, V>);
    V print(T);                 // Implements interface
    V print_line(T);            // Implements interface

    bool operator > (const MaTrix<T, D, V> mt) { return this->arr > mt.arr; }
    bool operator < (const MaTrix &check) { return check.m < check.n; }
};

template<typename T, typename D, typename V> V MaTrix<T, D, V>::print(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename D, typename V> V MaTrix<T, D, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    MaTrix<T, D, V>::print(n);
}

template<typename T, typename D, typename V> istream& operator >> (istream& input, MaTrix<T, D, V> &mt) {
    cout << "\t\t"; mt.print(50);
    mt.NhapThonTin();
    cout << "\t\t"; mt.print(50); cout << endl;
    return input;
}

template<typename T, typename D, typename V> ostream& operator << (ostream& output, MaTrix<T, D, V> mt) {
    cout << "\n\n\t\t"; mt.print_line(21);
    mt.XuatThongTin();
    cout << "\t\t"; mt.print(50); cout << endl;
    return output;
}

template<typename T, typename D, typename V> V MaTrix<T, D, V>::Gia_Tri_Lon_Nhat_Tren_1_Dong(MaTrix<T, D, V> check) {
    cout << "\n\n\t\t"; check.print_line(21);
    T max = check.arr[0][0];
    for(T i = 0; i < check.getM(); i++) {
        for(T j = 0; j < check.getN(); j++) {
            if (check.arr[i][j] > max) {
                max = check.arr[i][j];
            }
        }
        cout << "\t\t\t*Dong " << i + 1 << "\t -> Max: " << max << endl;
        max = -INT32_MIN;
    }
    cout << "\t\t"; check.print(50); cout << endl;
}

int main() {
    system("cls");
    MaTrix<int, double, void> arr = MaTrix<int, double, void>();
    cin >> arr; cout << arr;
    arr.Gia_Tri_Lon_Nhat_Tren_1_Dong(arr);
    return 0;
}

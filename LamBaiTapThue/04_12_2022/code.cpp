/*
    Tìm giá trị xuất hiện nhiều nhất trong mảng 2 chiều.
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T, typename D, typename V>    // template(genaric)
class ThongTin {    // abstract class   
public:
    ThongTin<T, D, V>() {}      // constructor no parameter.
    ThongTin<T, D, V>(T m, T n) : m(m), n(n) {} // constructor có tham số và kế thừa constructor ThongTin
    virtual ~ThongTin<T, D, V>() { this->m = this->n = 0; }
    T& getM() { return this->m; }       // return value.
    T& getN() { return this->n; }       // return value.
    
    // @overriding 
    V NhapThonTin() {
        cout << "\t\t<=> Nhap Vao Kich Thuoc Mang <=>" << endl;
        cout << "\t\t\t- Nhap So Hang: "; cin >> getM();
        cout << "\t\t\t- Nhap So Cot: "; cin >> getN();
    }

    // @overriding  
    V XuatThongTin() {
        cout << "\t\t<=> MA TRAN 2 CHIEU VUA NHAP <=>" << endl;
    }
    virtual T Dem_So_Lan_Xuat_Hien_CuaX(T) = 0; // overriding (ghi đè )
    virtual V Tim_Gia_Tri_Xuat_Hien_Nhieu_Nhat() = 0; // overriding (ghi đè)
    virtual V print(T) = 0;         // Implements abstract lass 
    virtual V print_line(T) = 0;    // Implements abstract lass
private:            // Encapsulation
    int m, n;     
};

template<typename T, typename D, typename V> 
class MaTrix : public ThongTin<T, D, V> { // tính kế thừa
public:
    MaTrix<T, D, V>() {}    // hàm khởi tạo
    ~MaTrix<T, D, V>() {}   // hàm hủy

    // @overriding  // Polymorphims
    V NhapThonTin() {
        ThongTin<T, D, V>::NhapThonTin(); 
        cout << "\t\t"; MaTrix<T, D, V>::print(33);
        cout << "\t\t<=> Nhap Vao Cac Phan Tu Mang <=>" << endl;
        for(T i = 0; i < MaTrix<T, D, V>::getM(); i++) 
            for(T j = 0; j < MaTrix<T, D, V>::getN(); j++) {
                cout << "\t\t\t+ Array["<<i<<"]["<<j<<"] = ";
                cin >> MaTrix<T, D, V>::arr[i][j];
            }
    }
    // @overriding  // Polymorphims
    V XuatThongTin() {
        ThongTin<T, D, V>::XuatThongTin();
        for(T i = 0; i < MaTrix<T, D, V>::getM(); i++) {
            for(T j = 0; j < MaTrix<T, D, V>::getN(); j++) {
                cout << "\t\t" << MaTrix<T, D, V>::arr[i][j] << "  ";
            }
            cout << endl;
        }
    }

    // chồng toán tử nhập và toán tử xuất mảng
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, MaTrix<A, B, C> &);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, MaTrix<A, B, C> ); 
    T Dem_So_Lan_Xuat_Hien_CuaX(T);         // overriding (ghi đè phương thức để thực hiên)
    V Tim_Gia_Tri_Xuat_Hien_Nhieu_Nhat();   // overriding
    V print(T);                             // Implements interface
    V print_line(T);                        // Implements interface
    bool operator < (const MaTrix &check) { return check.m < check.n; }
private:                // Encapsulation
    D arr[100][100];    
};

template<typename T, typename D, typename V>
V MaTrix<T, D, V>::print(T n) { for(T i = 0; i < n; i++) cout << "_"; cout << endl; }

template<typename T, typename D, typename V> V MaTrix<T, D, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename D, typename V> istream& operator >> (istream& input, MaTrix<T, D, V> &mt) {
    cout << "\t\t"; mt.print(33);
    mt.NhapThonTin();
    cout << "\t\t"; mt.print(33); cout << endl;
    return input;
}

template<typename T, typename D, typename V> ostream& operator << (ostream& output, MaTrix<T, D, V> mt) {
    cout << "\n\n\t\t"; mt.print_line(12);
    mt.XuatThongTin();
    cout << "\t\t"; mt.print(33); cout << endl;
    return output;
}

template<typename T, typename D, typename V> T MaTrix<T, D, V>::Dem_So_Lan_Xuat_Hien_CuaX(T x) {
    T count = 0;
    for(T i = 0; i < this->getM(); i++) 
        for(T j = 0; j < this->getN(); j++) 
            if(this->arr[i][j] == x) {
                count++;
            }
    return count;
}

template<typename T, typename D, typename V>
V MaTrix<T, D, V>::Tim_Gia_Tri_Xuat_Hien_Nhieu_Nhat() {
    cout << "\n\n\t\t"; this->print_line(12);
    T temp1, temp = this->Dem_So_Lan_Xuat_Hien_CuaX(this->arr[0][0]), index1 = 0, index2 = 0;
    for(T i = 0; i < this->getM(); i++) 
        for(T j = 0; j < this->getN(); j++) {
            temp1 = this->Dem_So_Lan_Xuat_Hien_CuaX(this->arr[i][j]);
            if(temp < temp1) {
                temp = temp1;
                index1 = i;
                index2 = j;
            }
        }
    cout << "\n\t\t<=> GIA TRI XUAT HIEN NHIEU NHAT: " << this->arr[index1][index2] << endl;
    cout << "\t\t"; this->print(33); cout << endl;
}

int main() {
    system("cls");
    MaTrix<int, double, void> arr;
    cin >> arr; cout << arr;
    arr.Tim_Gia_Tri_Xuat_Hien_Nhieu_Nhat();
    cin.get();
    return 0;
}


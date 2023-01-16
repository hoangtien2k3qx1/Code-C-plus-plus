/*
    Đề Bài:
        Liệt kê các dòng có chứa giá trị lớn nhất của ma trận trong ma trận các số thực.

    - Tính đa Hình (chồng toán tử nhập, xuất - ghi đè phương thức - hàm ảo)
    - Tính đóng gói (private)
    - Tính trừu tượng
    - Tính kế thừa
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T, typename D, typename V> // template(genaric)
class ThongTin {    // abstract class 
private:            // Encapsulation
    int m, n;       
public:
    ThongTin<T, D, V>() {}      // constructor no parameter
    ThongTin<T, D, V>(T m, T n) : m(m), n(n) {} // intializerlist
    virtual ~ThongTin<T, D, V>() { this->m = this->n = 0; }
    T& getM() { return this->m; }       // getter
    T& getN() { return this->n; }      

    V NhapThonTin() {
        cout << "\t\t<=> Nhap Vao Kich Thuoc Mang <=>" << endl;
        cout << "\t\t\t- Nhap So Hang: "; cin >> getM();
        cout << "\t\t\t- Nhap So Cot: "; cin >> getN();
    }

    V XuatThongTin() {
        cout << "\t\t<=> Mang Cac Gia Tri Vua Nhap Vao <=> " << endl;
    }

    // (interface)
    virtual V print(T) = 0;         // Implements abstract lass 
    virtual V print_line(T) = 0;    // Implements abstract lass 
};

template<typename T, typename D, typename V> 
class MaTrix : public ThongTin<T, D, V> {   // Inheritance
private:                                    // Encapsulation
    T arr[100][100];    

public:
    MaTrix<T, D, V>() {}    // constructor
    ~MaTrix<T, D, V>() {}   // Destructor

    // @overriding 
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

    // @overriding 
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

    // Operator input and output
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, MaTrix<A, B, C> &);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, MaTrix<A, B, C> ); 
 
    D timMax();        // implement
    V Gia_Tri_Lon_Nhat_Tren_1_Dong(MaTrix<T, D, V>);

    V print(T);         // Implements interface
    V print_line(T);    // Implements interface
    bool operator < (const MaTrix &check) { return check.m < check.n; }
};

template<typename T, typename D, typename V>
V MaTrix<T, D, V>::print(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename T, typename D, typename V>
V MaTrix<T, D, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_";
    cout << " KET QUA ";
    MaTrix<T, D, V>::print(n);
}

template<typename T, typename D, typename V>
istream& operator >> (istream& input, MaTrix<T, D, V> &mt) {
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

template<typename T, typename D, typename V> D MaTrix<T, D, V>::timMax() {
    D result = MaTrix<T, D, V>::arr[0][0];
    for(T i = 0; i < MaTrix<T, D, V>::getM(); i++) {
        for(T j = 0; j < MaTrix<T, D, V>::getN(); j++) 
            if (result < arr[i][j]) {
                result = arr[i][j];
            }
    }
    return result;
}

template<typename T, typename D, typename V> V MaTrix<T, D, V>::Gia_Tri_Lon_Nhat_Tren_1_Dong(MaTrix<T, D, V> check) {
    cout << "\n\n\t\t"; check.print_line(21);
    cout << "\n\t\t\t<=> LET KE DONG CHUA GT LON NHAT <=>" << endl;
    T count = 0, brr[100];
    D result = MaTrix<T, D, V>::timMax(); 
    T index = 0;
    for(T i = 0; i < MaTrix<T, D, V>::getM(); i++) {
        bool check = false;
        for(T j = 0; j < MaTrix<T, D, V>::getN(); j++) 
            if (result == MaTrix<T, D, V>::arr[i][j] && check == false) {
                count++;
                brr[index++] = i;
                check = true;
            }
    }
    int res = 0;
    for(T i = 0; i < count; i++) {
        cout << "\t";
        for(T j = 0; j < MaTrix<T, D, V>::getN(); j++) {
            cout << "\t\t" << MaTrix<T, D, V>::arr[brr[res]][j];
        }
        res++;
        cout << endl;
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

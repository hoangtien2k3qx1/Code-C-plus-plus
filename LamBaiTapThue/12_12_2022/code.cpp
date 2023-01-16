/*
    Đề bài:
        Hãy liệt kê các vị trí mà giá trị tại các vị trí đó bằng giá trị dương nhỏ nhất 
        trong mảng 1 chiều các số thực.
    Code C++ Hướng đối tượng (OOP).
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T, typename V>
class DuKien_ {
private:
    T n;
public:
    DuKien_<T, V>() {}
    DuKien_<T, V>(T n) : n(n) {}
    ~DuKien_<T, V>() { n = 0; }
    T& getN() {return this->n; }

    V NhapThongTin() {
        cout << "\t<=> NHAP VAO N PHAN TU CUA MANG:  "; cin >> n;
    }
    V XuatThongTin() {
        cout << "\n\t<=> MANG CAC PHAN TU VUA NHAP VAO <=> " << endl;
    }
    virtual V print(T) = 0;         // Polymophythms 
    virtual V print_line(T) = 0;    // Polymophythms 
};

template<typename T, typename D, typename V>
class Mang : public DuKien_<T, V> {
private:    
    D arr[100];
public:
    Mang<T, D, V>(int n) : DuKien_<T, V>(n) {}
    Mang<T, D, V>() {}
    // @overrding
    V NhapThongTin() {  
        DuKien_<T, V>::NhapThongTin();
        for(T i = 0; i < Mang<T, D, V>::getN(); i++) {
            cout << "\t\tarr["<<i<<"] = "; cin >> Mang<T, D, V>::arr[i];
        }
    }
    // @overrding
    V XuatThongTin() {
        DuKien_<T, V>::XuatThongTin();
        cout << "\t\tArray = {";
        for(T i = 0; i < Mang<T, D, V>::getN(); i++) 
            cout << Mang<T, D, V>::arr[i] << "  "; 
        cout << "}";
    }
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, Mang<A, B, C> &);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, Mang<A, B, C>);
    D Min(Mang<T, D, V> m);
    V Xu_Ly_Du_Lieu(Mang<T, D, V> m);
    V print(T);         // Polymophythms 
    V print_line(T);    // Polymophythms 
};

template<typename T, typename D, typename V> V Mang<T, D, V>::print(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename D, typename V> V Mang<T, D, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename D, typename V> istream& operator >> (istream& input, Mang<T, D, V> &m) {
    m.NhapThongTin();
    return input;
}

template<typename T, typename D, typename V> ostream& operator << (ostream& output, Mang<T, D, V> m) {
    cout << "\n\n\t"; m.print_line(18);
    m.XuatThongTin();
    cout << "\n\t"; m.print(45); cout << endl << endl;
    return output;
}

template<typename T, typename D, typename V> D Mang<T, D, V>::Min(Mang<T, D, V> m) {
    D min = m.arr[0];
    for (T i = 0; i < m.getN(); i++)
        if (m.arr[i] < m.arr[i + 1] && m.arr[i] > 0) 
            min = m.arr[i];
    return min;
}

template<typename T, typename D, typename V> V Mang<T, D, V>::Xu_Ly_Du_Lieu(Mang<T, D, V> m) {
    cout << "\n\n\t"; m.print_line(18);
    D min = Mang<T, D, V>::Min(m);
    cout << "\t# Gia Tri Duong Nho Nhat:  " << min << endl;
    for(T i = 0; i < m.getN(); i++) {
        if(m.arr[i] == min) {
            cout << "\t\t+ Vi Tri: " << i << endl;
        }
    }
    cout << "\n\t"; m.print(45); cout << endl << endl;
}

int main() {
    system("cls");
    Mang<int, double, void> arr;
    cin >> arr; cout << arr;
    arr.Xu_Ly_Du_Lieu(arr);

    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\t\t\t*** Day-Month-Year: "<< ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    cout << endl << endl << endl;

    return 0;
}

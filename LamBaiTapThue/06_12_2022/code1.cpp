/*
    155. Hãy tìm giá trị trong một mảng các số thực "xa giá trị x nhất" (xanhat).
        Ví dụ:
            24      45      23      13      43      -12
        Giá trị x = 15;
        Khoảng cách từ x = 15 tới các phần tử khác trong mảng là:
            9       30      8       2       28      27
        Giá trị trong mảng xa giá trị x nhất là: 45
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T, typename V, typename F>
class ThongTin {
private:                                        // encapsulation (đóng gói)
    T n;
    F x;

public:
    ThongTin<T, V, F>() {}                      // Constructor
    ThongTin<T, V, F>(T n) : n(n) {}            // Constructor have parameter
    ~ThongTin<T, V, F>() { n = 0; x = 0; }      // Descontructor
    V print(T);                                 // Polymophythms 
    V print_line(T);                            // Polymophythms 

    T& getN() { return this->n; }               // getter
    F& getX() { return this->x; }               // getter

    V NhapThongTin() {
        cout << "\t\t<=> NHAP VAO N PHAN TU CUA MANG:  "; cin >> getN();
    }

    V XuatThongTin() {
        cout << "\n\t\t<=> MANG CAC PHAN TU VUA NHAP VAO <=> " << endl;
        cout << "\t\tArray[ ";
    }

};

template<typename T, typename V, typename F>
class Mang : public ThongTin<T, V, F> {         // Inheritance (kế thừa)
private:                                        // encapsulation
    F arr[100];

public:
    Mang<T, V, F>(int n) : ThongTin<T, V, F>(n) {} // (initializer list)
    Mang<T, V, F>() {}
    virtual ~Mang<T, V, F>() {                  // Desconstructor
        for(T i = 0; i < Mang<T, V, F>::getN(); i++) arr[i] = 0;
    }

    V NhapThongTin() {                          // Overriding from BassClass (ghi đè)
        ThongTin<T, V, F>::NhapThongTin();
        for(T i = 0; i < Mang<T, V, F>::getN(); i++) {
            cout << "\t\t\tArray["<<i<<"] = "; 
            cin >> Mang<T, V, F>::arr[i];
        }
        cout << "\t\t<=> NHAP VAO GIA TRI X: "; cin >> ThongTin<T, V, F>::getX();
    }

    V XuatThongTin() {                          // Overriding from BassClass (Polymorphims)
        ThongTin<T, V, F>::XuatThongTin();
        for(T i = 0; i < Mang<T, V, F>::getN(); i++) 
            cout << Mang<T, V, F>::arr[i] << "    "; 
        cout << "]";
    }

    // Operator input and output elements Array
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, Mang<A, B, C> &);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, Mang<A, B, C>);
    
    V Xu_Ly_Mang(Mang<T, V, F> m); // 

    V print(T);         // Function Prototype
    V print_line(T);    // Function Prototype

};

template<typename T, typename V, typename F> V Mang<T, V, F>::print(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename V, typename F> V Mang<T, V, F>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename V, typename F> istream& operator >> (istream& input, Mang<T, V, F> &m) {
    m.NhapThongTin();
    return input;
}

template<typename T, typename V, typename F> ostream& operator << (ostream& output, Mang<T, V, F> m) {
    cout << "\n\n\t"; m.print_line(21);
    m.XuatThongTin(); cout << endl;
    for(T i = 0; i < m.getN(); i++) {
        cout << "\n\t\t* Array["<<i<<"] - X = " << m.arr[i] << " - " << m.getX() << " = " << m.arr[i] - m.getX();
    }
    cout << "\n\t"; m.print(50); cout << endl << endl;
    return output;
}

template<typename T, typename V, typename F>
V Mang<T, V, F>::Xu_Ly_Mang(Mang<T, V, F> m) {
    cout << "\n\t"; m.print_line(21);
    T result = 0, min = m.arr[0] - m.getX();
    T count = 0;
    for(T i = 0; i < m.getN(); i++) {
        if ((m.arr[i] - m.getX()) > min) {
            min = m.arr[i] - m.getX();
            result = m.arr[i];
            count = i;
        }
    }
    cout << "\t\t<=> GIA TRI XA GIA TRI X NHAT <=>";
    cout << "\n\t\t\t* Array["<<count<<"] = " << result;
    cout << "\n\t"; m.print(50); cout << endl << endl;
}

int main() {
    system("cls");
    Mang<int, void, double> arr;
    cin >> arr; cout << arr;
    arr.Xu_Ly_Mang(arr);
    return 0;
}

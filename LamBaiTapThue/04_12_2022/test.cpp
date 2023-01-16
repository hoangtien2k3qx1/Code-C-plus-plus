/*
    Hãy liệt kê các vị trí trong mảng 1 chiều các số thực mà 
    giá trị tại đó bằng giá trị âm đầu tiên trong mảng.

    Yêu cầu: C++ OOP(hướng đối tượng).
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T, typename V>
class ThongTin {
protected:
    T n;
public:
    ThongTin<T, V>() {}     // hàm khởi tạo mặc định
    ThongTin<T, V>(T n) : n(n) {}   // hàm khởi tạo có tham số truyền vào.
    ~ThongTin<T, V>() { n = 0; }    // hàm hủy thông tin
    V print(T);         // Polymophythms 
    V print_line(T);    // Polymophythms 
};

template<typename T, typename V, typename F>
class Mang : public ThongTin<T, V> {
private:    
    F arr[100];
public:
    Mang<T, V, F>(int n) : ThongTin<T, V>(n) {} // hàm khởi tạo kế thừa(initializer list)
    Mang<T, V, F>() {}

    // overloading, nạp chồng toán tử nhập và xuất
    template<typename A, typename B, typename C> friend istream& operator >> (istream&, Mang<A, B, C> &);
    template<typename A, typename B, typename C> friend ostream& operator << (ostream&, Mang<A, B, C>);
    
    V Xu_Ly_Thong_Tin(Mang<T, V, F> m); // hàm xử lý thông tin cần giải quyết
    V print(T);         // Polymophythms 
    V print_line(T);    // Polymophythms 
};

template<typename T, typename V, typename F> V Mang<T, V, F>::print(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename V, typename F> V Mang<T, V, F>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename V, typename F> istream& operator >> (istream& input, Mang<T, V, F> &m) {
    cout << "\t<=> NHAP VAO N PHAN TU CUA MANG:  "; cin >> m.n;
    for(T i = 0; i < m.n; i++) {
        cout << "\t\tarr["<<i<<"] = "; cin >> m.arr[i];
    }
}

template<typename T, typename V, typename F> ostream& operator << (ostream& output, Mang<T, V, F> m) {
    cout << "\n\n\t"; m.print_line(14);
    cout << "\n\t<=> MANG CAC PHAN TU VUA NHAP VAO <=> " << endl;
    cout << "\t\tArray[ ";
    for(T i = 0; i < m.n; i++) cout << m.arr[i] << ", "; cout << "]";
    cout << "\n\t"; m.print(37); cout << endl << endl;
}

template<typename T, typename V, typename F>
V Mang<T, V, F>::Xu_Ly_Thong_Tin(Mang<T, V, F> m) {
    cout << "\n\t"; m.print_line(14);

    T count = 0;
    cout << "\t\tResult[ ";
	for(int i = 0; i < m.n; i++) {
		if(m.arr[0] < 0 && m.arr[i] == m.arr[0]) {
			cout << i << "  ";
        } else {
            ++count;
        }
	}
    if (count == m.n) 
        cout << "Khong Co Vi Tri Nao !";
    cout << "]"; cout << "\n\t"; m.print(37); cout << endl << endl;
}

int main() {
    system("cls");
    Mang<int, void, double> * arr = new Mang<int, void, double>[1];
    cin >> arr[0]; 
    cout << arr[0];
    arr->Xu_Ly_Thong_Tin(arr[0]);
    return 0;
}
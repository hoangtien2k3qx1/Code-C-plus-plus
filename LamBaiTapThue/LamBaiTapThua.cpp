/*
    Bài 197:  Hãy liệt kê các giá trị trong mảng các số nguyên có chữ số đầu tiên là chữ số lẻ.
    
    Yêu cầu:+ có đa hình 
            + có kế thừa
            + có khuôn hình
            + có chồng toán tử
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

template<typename T> // Generic - Trừu tượng hóa dữ liệu trong Clá
class Mang {        // Tính khuôn hình
protected:      // phạm vi truy xuất (hay tính đóng gói của đối tượng)
    T n;        // khai báo n phần tử của mảng  
    T *arr;     // khai báo mảng động

public:
    Mang<T>() {}; // constructor(hàm khởi tạo không tham số)
    Mang<T>(T n) {  // constructor(hàm khởi tạo có tham số truyền vào)
        this->n = n;
        arr = new T[n];  // cấp phát mảng động có n phần tử
    }
    virtual ~Mang<T>() {}; // virtual là tính chất của " Đa Hình " Trong C++ OOP

    bool kiem_Tra_So_Le_Dau_Tien(T);

};

template<typename T>
class MangSoNguyen : public Mang<T> {  // Tính kế thừa // Tính khuôn hình
public:
    MangSoNguyen<T>(T n) : Mang<T>(n) {}; // constructor kế thừa
    ~MangSoNguyen<T>() {
        delete[] this->arr;
    };

    template<typename U> 
    friend istream& operator >> (istream&, MangSoNguyen<U> &); // Nạp chồng toán tử nhập
    template<typename V>  
    friend ostream& operator << (ostream&, MangSoNguyen<V>); // Nạp chồng toán tử xuất

    bool kiem_Tra_So_Le_Dau_Tien(T); // Tính Đa Hình (Overriding - Ghi Đè)

};

template<typename T>
istream& operator >> (istream& input, MangSoNguyen<T> &msn) {
    cout << "\n*Nhap Vao Cac Phan Tu Cua Mang: " << endl;
    for(T i = 0; i < msn.n; i++) {
        cout << "\tarr["<<i<<"] = ";
        input >> msn.arr[i];
    }
    return input;
}

template<typename T>
bool MangSoNguyen<T>::kiem_Tra_So_Le_Dau_Tien(T number) {
    int temp = 0;
    while (number > 0) {
        temp = number % 10;
        number /= 10;
    }
    if (temp % 2 == 1) // kiểm tra xem chữ số đầu có phải số lẻ không
        return true; // số lẻ trả về true
    return false;  // số chẵn trả về false
}

template<typename T>
ostream& operator << (ostream& output, MangSoNguyen<T> msn) {
    cout << "\n______________________________________________\n";
    cout << "\n*Phan Tu Co Chu So Le Dau Tien: " << endl;
    cout << "\tPhan Tu:  ";
    for(T i = 0; i < msn.n; i++) {
        if(msn.kiem_Tra_So_Le_Dau_Tien(msn.arr[i])) {
            output << msn.arr[i] << "  ";
        }
    }
    cout << "\n______________________________________________\n";
    return output;
}

int main() {
    system("cls"); 

    int n; cout << "*Nhap Vao N Phan Tu Cua Mang: "; cin >> n;
    MangSoNguyen<int> msn = MangSoNguyen<int>(n);   // Khai báo đối tượng (Object)
    cin >> msn; // nhập vào mảng
    cout << msn; // xuất kết quả

    cin.get(); 
    return 0;
}


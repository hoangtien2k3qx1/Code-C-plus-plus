/*
    Để bài: 403. yêu cầu xoay ma trận 180 độ
        yêu cầu: có lớp, kế thừa, đa hình, chồng toán tử.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

template<typename T>            // dùng template trong C++ OOP (dùng để tổng quát hóa cho Class)
class MaTran {                  // đây là lớp MaTran
public:                         // đây là tính đóng gói(khuôn hình) hay phạm vi truy xuất của đối tượng.
    T row, col;                 // đây là thuộc tính chiều số hàng và số cột
    T **arr;                    // đây là con trỏ cấp 2
    
public:
    MaTran() {}
    MaTran(T row, T col) {      // đây là Constructor(hay hàm khởi tạo)
        this->row = row;
        this->col = col;
        arr = new int*[row];
        for(T i = 0; i < row; i++) {
            arr[i] = new T[col];
        }
    }
    virtual ~MaTran() {         // Hàm ảo (Virtual) cũng là 1 Tính chất của Đa Hình.
        for(T i = 0; i < row; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

template<typename T>
class MaTran2 : public MaTran<T> { // đây là tính kế thừa ( lớp MaTran2 kế thừa từ lớp MaTran)
public:
    T **brr;

public:
    MaTran2(T row, T col) : MaTran<T>(row, col){
        brr = new int*[this->row];
        for(T i = 0; i < this->row; i++) {
            brr[i] = new T[this->col];
        }
    }
    ~MaTran2() {
        for(T i = 0; i < this->row; i++) {
            delete[] brr[i];
        }
        delete[] brr;
    } 

    template<typename U>
    friend istream& operator >> (istream&, MaTran2<U>&); // đây là nạp chồng toán tử nhập; // đây cũng gọi là Function Prototype (Khuôn mẫu hàm)
    template<typename V>
    friend ostream& operator << (ostream&, MaTran2<V>); // đây là nạp chồng toán tử xuất(in);  // đây cũng gọi là Function Prototype (Khuôn mẫu hàm)
   
    void Xoay_Ma_Tran_180(MaTran2&);                    // Tính Đa Hình (Overriding - Ghi Đè).

};

template<typename T> istream& operator >> (istream& input, MaTran2<T>& mt) {
    cout << "\n*Nhap Vao Cac Phan Tu Ma Tran: " << endl;
    for(T i = 0; i < mt.row; i++) {
        for(T j = 0; j < mt.col; j++) {
            cout << "\tarr["<<i<<"]["<<j<<"] = ";
            input >> mt.arr[i][j];
        }
    }
    return input;
}

template<typename T> void MaTran2<T>::Xoay_Ma_Tran_180(MaTran2<T> &mt) {
    for(T i = mt.row - 1; i >= 0; i--) {
        for(T j = mt.col - 1; j >= 0; j--) {
            mt.brr[mt.row - 1 - i][mt.col - 1 - j] = mt.arr[i][j]; 
        } 
    }  
}

template<typename T> ostream& operator << (ostream& output, MaTran2<T> mt) {
    cout << "\n_____________________________________________\n";
    cout << "\n*Ma Tran Da Duoc Xoay 180: " << endl;
    for(T i = 0; i < mt.row; i++) {
        for(T j = 0; j < mt.col; j++) {
            cout << "\t" << mt.brr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "_____________________________________________\n\n\n";
    return output;
}

int main() {
    system("cls");
    int row, col;
    cout << "Nhap Vao So Hang: "; cin >> row;
    cout << "Nhap Vao So Cot: "; cin >> col;

    MaTran2<int> mt = MaTran2<int>(row, col);
    cin >> mt;                  // nạp chồng toán tử nhập
    mt.Xoay_Ma_Tran_180(mt);
    cout << mt;                 // nạp chồng toán tử xuất 

    cin.get();
    return 0;
}



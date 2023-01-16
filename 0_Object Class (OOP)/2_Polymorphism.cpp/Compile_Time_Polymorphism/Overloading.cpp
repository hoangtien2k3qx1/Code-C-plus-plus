
/*
    ! Overloading:(one thing in many form) NẠP CHỒNG (nạp chồng phương thức)
        - Overloading là một kĩ thuật cho phép trong cùng một class có thể có nhiều phương thức "CÙNG TÊN" nhưng khác nhau 
        về số lượng tham số hoặc kiểu dữ liệu tham số. 


    ! Operators Overloading in C++:
        syntax: 
                name_class operator+(const name_class& ...); // nạp chồng toán tử một ngôi

                name_class operator+(const name_class& ..., const name_class& ...); // nạp chồng toán tử 2 ngôi.



*/
// VD1:
// ! Overloading : Nạp Chồng
#include <iostream>
using namespace std;

class printData {
    public:
        void print(int i) {
            cout << "Printing int: " << i << endl;
        }
        void print(double f) {
            cout << "Printing float: " << f << endl;
        }
        void print(char* c) {
            cout << "Printing character: " << c << endl;
        }
};

int main(void) {
    printData pd;     
    
    pd.print(5);     // Call print to print integer
    pd.print(500.263);    // Call print to print float
    pd.print("Hello C++");  // Call print to print character

    return 0;
}



//VD2:
#include<iostream>
using namespace std;

class Math {
private:
    int a, b, c;
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int max(int a, int b, int c) {
        return max(max(a, b), c);
    }
};

int main() {
    Math math;
    cout << math.max(3, 5) << endl;
    cout << math.max(3, 5, 7) << endl;
    return 0;
}






//  ! ! Operators Overloading in C++: NẠP CHỒNG TOÁN TỬ.
#include<iostream> // ! nạp chồng toán tử một ngôi.
using namespace std;
#include<cmath>

class PhanSo {
    public:
        int tu;
        int mau;
    public:
        void input() {
            cout << "Nhap vao tu: ";
            cin >> this->tu;
            cout << "Nhap vao mau: ";
            cin >> this->mau;
        }
        void display() {
            cout << this->tu << "/" << this->mau << endl;
        }
        PhanSo operator +(const PhanSo& b) {
            PhanSo c;
            c.tu = this->tu * b.mau + this->mau * b.tu;
            c.mau = this->mau * b.mau;
            return c;
        }
};

int main() {
    PhanSo a, b, c;

    a.input();
    b.input();

    c = a + b;
    c.display();

    return 0;
}







//  ! Operators Overloading in C++: NẠP CHỒNG TOÁN TỬ.

#include <bits/stdc++.h> // ! nạp chồng toán tử 2 ngôi.
using namespace std;
 
class phanso 
{
private:
    int tu, mau;
 
public:
    void input() {
        cout << "Input tu: "; 
        cin >> this->tu;
        cout << "Input mau: ";
        cin >> this->mau;
    }
    void output()
    {
        cout << this->tu << "/" << this->mau << endl;
    }
    friend phanso operator +(const phanso &a, const phanso &b) // * cần có từ khóa "friend" , hàm nạp chồng được coi là hàm bạn. 
    {
        phanso c;
        c.tu = a.tu * b.mau + a.mau * b.tu;
        c.mau = a.mau * b.mau;
        return c;
    }    
};

int main() {
    phanso a, b, c;
    a.input();
    b.input();

    c = a + b;  
    c.output();

    return 0;
}



















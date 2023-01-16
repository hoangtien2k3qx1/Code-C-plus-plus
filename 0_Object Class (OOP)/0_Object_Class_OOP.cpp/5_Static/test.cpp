
// hàm static C++ OOP

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  
    Ưu điểm lớn nhất của hàm static đó chính là chúng ta có thể sử dụng trực tiếp nó mà 
    không cần phải tạo ra đối tượng (instance) từ class
    
*/

class Math {
public:
    static double pi;   // biến static

    static double getpi() { //hàm static thì chỉ có thể truy xuất được các thành viên kiểu static.
        return pi;
    }

    static void Swap(vector<int> &vt) { // hàm static nhưng thành viên truyền vào từ bên ngoài class nên có thể truy xuất được
        int temp = vt[0];
        vt[0] = vt[1];
        vt[1] = temp;
    }

};

double Math::pi = 3.14; // cập nhập giá trị cho biến static

int main() {
    system("cls");

    vector<int> vt;
    int a = 5, b = 10;
    vt.push_back(a);
    vt.push_back(b);


    cout << Math::getpi() << endl << endl;

    Math::Swap(vt);
    cout << a << " - " << b << endl;
    cout << vt[0] << " - " << vt[1] << endl;




    cin.get();
    return 0;
}
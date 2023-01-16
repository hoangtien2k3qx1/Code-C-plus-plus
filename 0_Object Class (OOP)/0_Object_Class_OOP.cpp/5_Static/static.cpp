
/*  
    !  C++ Static: giống như biến toàn cục (global), có thể sử dụng chung cho tất cả các đối tượng của lớp.
        * + Static trong c++ là dữ liệu của lớp không phải là dữ liệu của đối tượng. 
        * + Dữ liệu static xuất hiện trước khi bạn khởi tạo đối tượng của lớp, 
        và nó chỉ tồn tại duy nhất.
        * + Vùng nhớ của biến static chỉ được cấp pháp 1 lần và giá trị của biến trong những lần gọi 
        trước đó được lưu lại và thực hiện trong những lần gọi tiếp theo.



    ! THUỘC TÍNH CÓ TÍNH STATIC:
        * thuộc tính static là thuộc tính chung, nên tất cả các đối tượng có thể dùng chung.
        

    ! PHƯƠNG THỨC CÓ TÍNH STATIC:
        * Phương thức có tính static là phương thức không của riêng bất kỳ đối tượng nào,
        nên không thể gọi đến phương thức này bằng một đối tượng cụ thể. 

        * Không thể dung con trỏ this, vì con trỏ this không có giá trị, nên sẽ lỗi

        * Phương thức static không thể gọi trực tiếp các phương thức non-static
        (vì phương thức non-static đang kết hợp với 1 đối tượng cụ thể.)

        * Phương thức static chỉ có thể:
            + Truy xuất các thuộc tính có tính static.
            + Gọi các phương thức có tính static khác.



    ! LƯU Ý: các biến static không được coi như là thuộc tính của một lớp.

    Đối với class, static dùng để khai báo thành viên dữ liệu dùng chung cho mọi thể hiện của lớp:

        + Một bản duy nhất tồn tại trong suốt quá trình chạy của chương trình.
        + Dùng chung cho tất cả các thể hiện của lớp.
        + Bất kể lớp đó có bao nhiêu thể hiện.

*/

#include <iostream>  
#include<bits/stdc++.h>
using namespace std;  

class Account {  
    public:  
        int accno;    
        string name;

    public:
        static float rateOfInterest;   // biến static

        Account(int accno, string name): accno(accno), name(name) {}; 

        void display() {    
            cout << accno << " - " << name << " - " << rateOfInterest << endl;  
        }     

        static float getRateOfInterest() { 
            return rateOfInterest; // hàm static chỉ có thể truy xuất các thanh viên bên trong class kiểu static mà thôi.
        }


        static void swap(int &a, int &b) { // hàm static nhưng cập nhật giá trị từ bên ngoài class nên có thể truy xuất được.
            int temp = a;
            a = b;
            b = temp; 
        }

};  


float Account::rateOfInterest = 6.5; // biến static trong class thì phải định nghĩa ở bên ngoài


int main(void) {  
    system("cls"); // xóa màn hình

    static Account a1 = Account(2003, "HOANG ANH TIEN");

    cout << endl << Account::getRateOfInterest() << endl << endl;

    cout << "_____________________________" << endl;

    a1.display();   

    cout << "_____________________________" << endl;

    static int a = 5, b = 10;
    cout << endl << a << " - " << b << endl;
    Account::swap(a, b); // không cần khai báo instance để truy xuất, vì static không thuộc một đối tượng nào cả.
    cout << endl << a << " - " << b << endl;
    
    cout << "_____________________________" << endl;

    int c = 12, d = 19;
    cout << endl << c << " - " << d << endl;
    Account::swap(c, d);
    cout << endl << c << " - " << d << endl;


    cin.get(); // lệnh dừng màn hình
    return 0;  
}  


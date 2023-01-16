
/*  
    ! C++ string substr() : It creates a new string object of n characters.

    + Hàm substr là một hàm thành viên trong class std:string, có tác dụng cắt chuỗi con ra 
    từ chuỗi string ban đầu bằng cách chỉ định vị trí và độ dài chuỗi cần cắt. 
    + Phép cắt string bằng hàm substr trong C++ không làm thay đổi chuỗi ban đầu mà sẽ lưu kết
    quả cắt vào một string mới.

    substr() : hàm này dùng để cắt chuỗi


    Syntax: string s1
    *            s1.substr(vị trí bắt đầu); // cắt từ vị trí chỉ định tới cuối chuỗi

    *            s1.substr(vị trí bắt đầu, số phần tử cần lấy);


*/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "Hello World!";

    string substr = str.substr(1, 3); // bắt đầu từ 1 và độ dài là 3 => ell
    cout << substr << endl;

    string b = str.substr(2, 5); // bắt đầu từ 2 và độ dài là 3 => llo W =>bắt đầu từ index 2 và lấy ra 5 ký tự
    cout << b << endl;

    return 0;
}
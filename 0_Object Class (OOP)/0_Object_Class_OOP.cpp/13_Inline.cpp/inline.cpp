/*
Định nghĩa:
    Inline function là một chức năng trong ngôn ngữ lập trình C++. 
    Hàm inline là hàm được định nghĩa bằng từ khóa inline. 
    Hàm inline được sử dụng để yêu cầu trình biên dịch (compiler) 
    thay thế lời gọi hàm bằng toàn bộ mã code của hàm nhằm mục đích 
    giảm thời gian chạy chương trình.


    Không được sử dụng hàm inline:
        + các hàm với độ phức tạp cao
        + hàm khởi tạo và hàm hủy

*/


#include<bits/stdc++.h>
using namespace std;

class Inline {
public:
    string name;
    int age;
public:
    Inline(string name, int age) {
        this->name = name;
        this->age = age;
    }
    ~Inline() {}

    string getName();
    int getAge();

};

inline string Inline::getName() {
    return this->name;
}

inline int Inline::getAge() {
    return this->age;
}


int main() {
    system("cls");

    Inline inl = Inline("Hoang Anh Tien", 19);

    cout << inl.getName() << endl;
    cout << inl.getAge() << endl;



    return 0;
}
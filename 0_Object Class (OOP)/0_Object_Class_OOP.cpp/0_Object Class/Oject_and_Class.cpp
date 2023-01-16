
/*
    C++ Oject and Class: 
*/
//!
- Oject(đối tượng): là một thực thể trong thế giới thực
    VD: ghế, xe đạp, bút, điện thoại
        + nói cách khác, đối tượng là một thực thể có trạng thái và hành vi, ở đây trạng thái có nghĩa là dữ liệu và hành vi có nghĩa là chức năng

        + đối tượng là một thể hiện của một lớp. Tất cả các thanh viên của một lớp có thể được truy cập thông qua các đối tượng

VD: Tạo một đối tượng sinh viên     
    Student s1; // tạo đối tượng sinh viên



//!
- Class(lớp): là một nhóm các đối tượng tương tự. nó là một khuôn mẫu mà từ đó các đối tượng được tạo ra. 
                nó có thể có các trường, phương thức

VD: 
    class Student {
        public:
        int id; // thành viên của dữ liệu
        float salary; // thanh viên của dữ liệu
        string name; //  thanh viên của dữ liệu
    }






****** C++ Oject:   Ví dụ về lớp và đối tượng trong C++ Oject

#include<iostream>

class Student {
    public: 
        int id;
        string name;
};

int main() {
    Student s1; // tạo đối tượng Student
    s1.id = 10001;
    s1.name = "Hoang Tien";
    std::cout << s1.id << std::endl;
    std::cout << s1.name << std::cout << endl;
    return 0;
}






***** C++ ví dụ về lớp và đối tượng trong C++: khởi tạo và hiển thị dữ liệu thông qua phương thức

#include<iostream>

class Student {
    public: 
        int id;
        string name;

        void insert(int i, int n) {
            id = i;
            name = n;
        }

        void display() {
            std::cout << id << " " << name << std::endl;
        }
};

int main() {    
    Student s1; // tạo đối tượng s1 của lớp Student
    Student s2; // tạo đối tượng s2 của lớp Student

    s1.insert(201, "Hoang Tien");
    s2.insert(202, "Hoang Chung");
    s1.display();
    s2.display();

    return 0;
}

// C++ Encapsulation: Tính đóng gói 

/*
    * Hiểu đơn giản, gói dữ liệu và thông tin vào trong một lớp (class) được gọi là tính đóng gói.

    - Có thể nói tính đóng gói (Encapsulation) là cơ chế của che giấu dữ liệu (Data Hiding) bởi chúng được 
    lớp (class) che giấu đi (ở dạng private) một số dữ liệu, hàm và phương thức để đảm bảo rằng các dữ 
    liệu đó sẽ được truy cập và sử dụng đúng mục đích, đúng cách thông qua các hàm và phương thức 
    ở dạng public mà class cung cấp. Đó là lý do bạn không thể truy cập đến các thuộc tính private 
    hoặc gọi đến phương thức private của class từ bên ngoài class đó.


    - Tính đóng gói được thể hiện khi mỗi đối tượng mang trạng thái là private ở bên trong một class và 
    những đối tượng khác không thể truy cập trực tiếp vào phạm vi này. Thay vào đó họ chỉ có thể 
    gọi các hàm mang phạm vi public được gọi là phương thức


    ! => LỢI ÍCH CHÍNH CỦA TÍNH ĐÓNG GÓI MANG LẠI:
    - hạn chế được các truy xuất không hợp lệ tới các thuộc tính của đối tượng
    - giúp cho trạng thái của đối tượng luôn đúng
    - giúp ẩn đi những thông tin không cân thiết về đối tượng.
    - cho phép bạn thay đổi cấu trúc bên trong lớp mà không ảnh hưởng tới lớp khác.
    - Tránh bị rò rỉ thông tin không cần thiết. 

*/

#include<iostream>
using namespace std;

class Student {
private:    //! Private là một tính chất của tính đóng gói đối tượng.
    int id;
    string name;
    int age;
    string address;
    int score;
public:
    Student() {}
    Student(int id, string name, int age, string address, int score) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->address = address;
        this->score = score;
    }
    void setId(int id) {
        this->id = id;
    }
    int getId() {
        return this->id;
    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    void setAge(int age) {
        this->age = age;
    }
    int getAge() {
        return this->age;
    }
    void setAddress(string address) {
        this->address = address;
    }
    string getAddress() {
        return this->address;
    }
    void setScore(int score) {
        if (score < 0) this->score = 0;
        else if (score > 10) this->score = 10;
        else this->score = score;
    }
    int getScore() {
        return this->score;
    }
};

int main() {
	Student s(1001, "Trung", 24, "Ha Noi", 5);
	cout << s.getId() << endl;;
	cout << s.getName() << endl;;
	cout << s.getAge() << endl;;
	cout << s.getAddress() << endl;;
	cout << s.getScore() << endl;;
	s.setScore(-7);
	cout << s.getScore() << endl;;
	s.setScore(15);
	cout << s.getScore() << endl;;
	return 0;
}




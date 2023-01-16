
/*
    Down-casting:
    + Down-casting thì ngược lại với us-casting. Down-casting là chuyển từ lớp cha 
    sang kiểu con trỏ của lớp con.

    + Down-casting có đặc điểm là bạn có thể gọi tới các phương thức chỉ có ở lớp 
    con mà không có ở lớp cha.

*/

#include<iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Base Class Some sound" << endl;
    }
};

class Dog : public Animal {
private:
    string ownername = "Value_NULL";

public:
    void sound() {
        cout << "Driver Class Woof woof: " << ownername << endl;
    }
    void play() {
        cout << "Driver Class The dog is playing: " << ownername << endl;
    }
};


int main() {
    system("cls");


    Dog *dog = new Dog();
    Animal *animal = (Animal*) dog;  //! Up-casting trước

    ((Dog*)animal)->sound(); //! Down-casting 
    ((Dog*)animal)->play(); //! Down-casting 




    cin.get();
    return 0;
}
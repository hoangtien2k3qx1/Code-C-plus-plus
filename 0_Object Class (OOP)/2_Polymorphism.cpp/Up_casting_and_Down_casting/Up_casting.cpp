
/*
    ! Up-casting và Down-casting: là ép kiểu dữ liệu

    * Up-casting: ép kiểu đi lên
    + khi biến con trỏ của lớp cha trở tới đối tượng của lớp con thì đó gọi là "Up-casting"
    ( hay là ép kiểu từ lớp dẫn xuất(lớp con) về lớp cơ sở(lớp cha) - gọi là up-casting) 

    + Up-casting: Đối tượng của lớp con bị ép kiểu (chuyển kiểu) về đối tượng của lớp cha. 



    * LƯU Ý:
        Khi biến của lớp cha tham chiếu tới đối tượng của lớp con thì biến này có thể gọi tới được
        thuộc tính và phương thức của lớp cha.
        
*/

#include<iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "1. Base Class Some sound" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "2. Driver Class Meow meow" << endl;
    }
};

int main() {
    system("cls");

    Animal *a = new Cat();
    a->sound();


    //! Up-casting
    Cat *cat = new Cat(); 
    cat->sound(); //! Thông thường
    ((Animal*)cat)->sound(); //! Up-casting. (ép kiểu về kiểu lớp cha)
    

    cin.get();
    return 0;
}
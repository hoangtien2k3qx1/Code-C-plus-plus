
/*  
C++ Copy Constructor:

    Copy constructor là một constructor mà tạo một đối tượng bằng việc khởi tạo nó với
    một đối tượng của cùng lớp đó, mà đã được tạo trước đó.

    Copy constructor được sử dụng để:
        Khởi tạo một đối tượng từ đối tượng khác với cùng kiểu.


    - COPY CONSTRUCTOR CÓ 2 LOẠI:
        + Default Copy Constructor:
        + User Defined constructor: The programmer defines the user-defined constructor.



    Two types of copies are produced by the constructor:
        + Shallow copy: sao chép nông
        + Deep copy : sao chép sâu




    ! Syntax Of User-defined Copy Constructor:

        Class_name(const class_name &old_object);  

        class A {  //  copy constructor.  
            A(A &x)  // ở chỗ này bắt buộc phải có ' &'
            {  
                deep copy constructor.  
            }  
        }   

        !===> Vậy khi nào thì cần dùng hàm copy constructor để định nghĩa lại,
         * vì một số kiểu dữ liệu không thể (VD: pointer) thì lúc này chúng ta cần
         * phải có hàm copy constructor để định nghĩa lại. 


*/

#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string fullname;
public:
    Person() {}
    Person(string fullname) : fullname(fullname) 
    {
        // cout << "Let's gooo !" << endl;
    }

    void setFullname(string fullname) { this->fullname = fullname; }

    string getFullname() { return this->fullname; }

};

    
class Vihicle {
protected:
    string modelname;
    Person *owner;

public:
    Vihicle(const string &modelname) : modelname(modelname) 
    {
        // cout << "Create a Vihicle " << modelname << endl;
    }

    Vihicle(Vihicle &othervihicle)  //! Deep copy constructor
    {
        // cout << "Clone a Vihicle " << othervihicle.getModolname() << endl;
        modelname = othervihicle.getModolname();
        // owner = othervihicle.getOwner(); //! như thế này thì nó chỉ copy địa chỉ của con trỏ thôi
        owner = new Person(othervihicle.getOwner()->getFullname());                     
    }
                                        
    string getModolname() { return this->modelname; }

    void setOwner(Person *person) {
        owner = person;
    }

    Person *getOwner() { return this->owner; }

    virtual void run() {
        cout << this->modelname << " is running" << endl;
    }

};


int main()  {
    system("cls");

    Person *person = new Person("0. TIEN TIEN TIEN");

    Vihicle *vihicle1 = new Vihicle("1. TIEN ANH HOANG");
    vihicle1->setOwner(person);

    Vihicle *vihicle2 = new Vihicle(*vihicle1);
    vihicle2->getOwner()->setFullname("2. HOANG ANH TIEN");

    cout << vihicle1->getOwner()->getFullname() << endl;
    cout << vihicle2->getOwner()->getFullname() << endl;


    cin.get();
    return 0;
}

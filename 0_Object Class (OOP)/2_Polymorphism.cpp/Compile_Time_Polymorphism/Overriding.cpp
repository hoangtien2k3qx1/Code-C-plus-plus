
/*
    ! Function Overriding in C++: GHI ĐÈ C++

    Function overriding in C++ is a feature that allows us to use a function in the child class that is already present in its parent class.
    The child class inherits all the data members, and the member functions present in the parent class.


    ! How to access Overridden Functions in C++:
        You must use the scope resolution operator, “::” to access the overridden function. Another way to access the overridden function 
        is by using the pointer of the base class to point to an object of the derived class and calling the function through the pointer.


*/

// ! Function Overriding in C++:

#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class A {
    public: 
        string name;
        string address;
    public:
        A(string name, string address) {
            this->name = name;
            this->address = address;
        }
        void print() {
            cout << name  << " - " << address << " - ";
        }

        void display() {
            cout << "Base class function!!!" << endl;
        }
};

class B : public A {
    public: 
        float gpa;
    public:
        B(string name, string address, float gpa) : A(name, address) { 
            this->gpa = gpa;
        }
        void print() {      // overriding: ghi đè
            A::print(); 
            cout << gpa << endl;
        }
        void display() {    // overriding: ghi đè
            A::display(); 
            cout << "Driver class function!!!" << endl;
        }
};


int main() {
    B p1 = B("Hoang Anh Tien", "Thanh Hoa", 3.6);
    
    p1.print();
    p1.display();

    cout << endl;

    // p2.A::display(); // cách này nó cũng tự hiểu là gọi lớp Base class(lớp cha)

    return 0;
}







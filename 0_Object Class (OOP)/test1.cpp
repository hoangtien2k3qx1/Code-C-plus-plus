#include<iostream>
using namespace std;

class A {
private:
    int x = 2;
public:
    // A() : x(2) {} // C1 (danh sách khởi tạo)
    A(int x = 2) { // C2
        this->x = x;
    }
    void funcA() {
        cout << "x = " << x << endl;
    }   
};

class B : private A {
private:
    int y;
public:
    B() : y(3) {}
    void funcA() {
        A::funcA(); // vẫn truy xuất được theo kiểu private.
        cout << "y = " << y << endl;
    }
};

int main() {
    B *b = new B();

    b->funcA();
    
    return 0;
}
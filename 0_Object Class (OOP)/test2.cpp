
#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A";
    }
    ~A() {
        cout << "B";
    }
};

class B : public A {
public:
    B() : A() {
        cout << "C";
    }
    ~B() {
        cout << "D";
    }
};

void agc(B b) {

}

int main() {
    B b;
    agc(b);

}
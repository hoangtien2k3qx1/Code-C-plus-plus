
// C++ program to demonstrate the working of private inheritance

/*
    Trong C++ thì thuộc tính Private không thể kế thừa được. 

    (hay là lớp con không thể kê thừa được các thuộc tính của lớp cha).

*/

#include <iostream>
using namespace std;

class Base {
    private:
        int pvt = 1;

    protected:
        int prot = 2;

    public:
        int pub = 3;

        //* function to access private member
        int getPVT() {
            return pvt;
        }
};

class PrivateDerived : private Base { // Access modifier is private
    public:
        //* function to access protected member from Base
        int getProt() {
            return prot;
        }

        //* function to access private member
        int getPub() {
            return pub;
        }
};

int main() {
    PrivateDerived object1;
    cout << "Private cannot be accessed." << endl;
    cout << "Protected = " << object1.getProt() << endl;
    cout << "Public = " << object1.getPub() << endl;

    return 0;
}

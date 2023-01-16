
// Public:

#include <iostream>
using namespace std;

class Base {
    private:
        int pvt = 1;

    protected:
        int prot = 2;

    public:
        int pub = 3;

        // function to access private member
        int getPVT() {
            return pvt;
        }
};

class PublicDerived : public Base { // Access modifier is public
    public:
        // function to access protected member from Base
        int getProt() {     // protected nên truy xuất được trong class kế thừa.
            return prot;
        }

        int getPub() {
            return pub;
        }
};

int main() {
    PublicDerived object1;
    cout << "Private = " << object1.getPVT() << endl;
    cout << "Protected = " << object1.getProt() << endl;
    cout << "Public = " << object1.getPub() << endl;

    cout << "\npublic = " << object1.pub << endl;

    return 0;
}

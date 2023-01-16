
// ! C++ Single Inheritance: Đơn kế thừa.

#include <iostream>
#include <cmath>
using namespace std;

class Account
{ // base class: lớp cơ sở (lớp cha)
public:
    Account() {
        cout << "1. Goi ham tao Account thu 1" << endl;
    }

    ~Account() {
        cout << "2. goi ham huy Account thu 2" << endl;
    }

    float salary = 600000;
    int a = 4;
    int b = 5;
    void eat()
    {
        cout << "Hoang Anh Tien..." << endl;
    }
    int mul()
    {
        return a * b;
    }
};

class Programer : public Account
{ // driver class: lớp dẫn xuất (lớp con)
public:
    Programer() {
        cout << "2. goi ham Programer thu 2" << endl;
    }
    ~Programer() {
        cout << "1. Goi ham huy Programer thu 1" << endl;
    }

    float bonus = 5000;

    void bark()
    {
        cout << "Dep trai Nhat The Gioi..." << endl;
    }

    int result = mul();

    void eat()
    {
        Account::eat();
        cout << "Tien Anh Hoang bababab!!!" << endl;
    }
};

int main()
{
    system("cls");

    Programer *p1 = new Programer();
    cout << "Salary: " << p1->salary << endl;
    cout << "Bonus: " << p1->bonus << endl;
    p1->eat();
    p1->bark();
    p1->result;
    cout << "Ket Qua a * b = "
         << " " << p1->a << " * "
         << " " << p1->b << " = " << p1->result << endl;


    delete p1;

    cin.get();
    return 0;
}
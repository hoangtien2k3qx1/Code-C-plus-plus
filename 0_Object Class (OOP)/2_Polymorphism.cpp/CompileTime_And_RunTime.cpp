

// ! Differences b/w compile time and run time polymorphism.
/*
    *Compile Time Polymorphism:

        + The function to be invoked(gọi, biết tới) is know at the complite time.

        + "Overloading" is a compile time polymorphism where more than one method is having the same name but with the different
        number of parameters or the type of the parameters.

        + It is achieved by function overloading and operator overloading.

        + It provides fast execution as it is known at the compile time.

        + It is less flexible as mainly all the things execute at the compile time.



    *Run Time Poltmorphism:

        + The function to be invoked, í know at the run time.

        + Overriding is a run time polymorphism where more than one method is having the same name, number of parameters and the type of the parameters.

        + It is achieved by virtual functions and pointers.

        + It provides slow execution as it is known at the run time.

        + It is more flexible as all the things execute at the run time.

*/

#include <iostream>
using namespace std;

class base
{
public:
    void fun_1() { cout << "base-1\n"; }
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base
{
public:
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }
};

int main()
{
    base *p; // pointer base class
    derived obj1;
    p = &obj1;

    p->fun_1(); // -> fun_1 // (base class)
    p->fun_2();
    p->fun_3();
    p->fun_4();
    obj1.fun_4(5);

    return 0;
}

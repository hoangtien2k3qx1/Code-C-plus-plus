
// ! C++ Multiple Inheritance: Đa kế thừa
/*
    syntax: 
            class D : visibility B-1, visibility B-2
            {  
                Body of the class;  
            }   
*/
#include <iostream>  
using namespace std;  

class A  // base class A
{  
    protected:  
        int a;  
    public:  
        void get_a(int n)  
        {  
            this->a = n;  
        }  
        void display() {
            cout << "Hoang Anh Tien" << endl;
        }
};  
  
class B  // base class B
{  
    protected:  
        int b;  
    public:  
        void get_b(int n)  
        {  
            this->b = n;  
        }  
        void display() {
            cout << "Tien Dep Trai!!!" << endl;
        }
};  

class C : public A, public B  
{  
    public:  
    void display()  
    {  
        cout << "The value of a is : " << a << std::endl;  
        cout << "The value of b is : " << b << std::endl;  
        cout<<"Addition of a and b is : "<< a + b << endl;
    }  

    void view() {
        A::display(); // Calling the display() function of class A.  
        B::display(); // Calling the display() function of class B.  
    }
};  

int main()  
{  
    C c;  
    c.get_a(10);  
    c.get_b(20);  
    c.display();  

    c.view();

    return 0;  
}  
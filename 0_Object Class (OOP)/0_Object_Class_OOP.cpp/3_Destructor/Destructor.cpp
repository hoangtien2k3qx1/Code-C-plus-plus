
/*  C++ Destructor: hay còn được gọi là hàm hủy

    - Một hàm hủy hoạt động ngược lại với hàm tạo; nó hủy các đối tượng của các lớp. 
        
        + Nó chỉ có thể được định nghĩa một lần trong một lớp. 
        + Giống như các hàm tạo, nó được gọi tự động.

    ! +   ~ Destructor

    ! + Hàm hủy Destructor không có tham số truyền vào.

*/

/*
    ! Khái niện Virtual Destructor: 
        * + virtual destructor: illegal (không được)
        * + virtual ~destructor: llegal (được)


        

    Ex:

        class Base
        {
        public:
            Base() {};
            virtual ~Base() { cout << "Destructor Base\n"; };
        };


        class Derived : public Base
        {
        public:
            Derived() {};
            ~Derived() { cout << "Destructor Derived\n"; }
        };

        int main()
        {
            Base *b = new Derived();
            delete b;
            return 0;
        }

        => Output:
                + Destructor Deriver
                + Destructor Base
                
        => nó sẽ gọi phương thức hàm hủy của lớp con trước rồi mới gọi tới 
        phương thức hàm hủy của lớp cha.

        

*/

#include <iostream>  
using namespace std;  
class Employee  
{  
    public:  
        Employee()    
        {    
            cout<<"Constructor Invoked"<<endl;    
        }    

        ~Employee()    
        {    
            cout<<"Destructor Invoked"<<endl;    
        }  
};  

int main(void)   
{  
    Employee e1; // creating an object of Employee // nó sẽ tự động goi cả hàm tạo và hàm hủy Constructor   

    return 0;  
}  
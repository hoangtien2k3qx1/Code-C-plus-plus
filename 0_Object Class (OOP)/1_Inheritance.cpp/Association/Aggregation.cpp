
// C++ Aggregation (HAS-A Relationship) : Quan hệ thu nạp
/*
    Quan hệ thu nạp ( Aggregation ):

    - Quan hệ thu nạp xảy ra khi một đối tượng có thuộc tính là một đối tượng khác 
    và 2 đối tượng này có thể tồn tại độc lập. 

    Ex: 
            class ClassA {
                private:
                    ClassB b;
                public:
                    void setB(ClassB b) {
                        this->b = b;
                    }
            };

    => Có thể thấy đối tượng của ClassB tồn tại độc lập với đối tượng của ClassA (ClassA không tạo ra đối tượng của ClassB).
*/

#include <bits/stdc++.h>  
using namespace std;  

class Address {  
    public:  
        string addressLine, city, state;    
        Address(string addressLine, string city, string state)    
        {    
            this->addressLine = addressLine;    
            this->city = city;    
            this->state = state;    
        }    
};  

class Employee {    
    private:  
        Address *address;  // Employee HAS-A Address.   
    public:  
        int id;    
        string name;    
        Employee(int id, string name, Address *address)    
        {    
            this->id = id;    
            this->name = name;    
            this->address = address;    
        }    
        void display()    
        {    
            cout << id << " - " << name << " - " << address->addressLine << " - " << address->city << " - " << address->state << endl;    
        }    
}; 

int main(void) {  
    Address a1 = Address("Nam Tu Liem", "Ha Noi", "Phung Khoang");    
    Employee e1 = Employee(58, "Hoang Anh Tien", &a1);    
    e1.display();   
    return 0;  
}  





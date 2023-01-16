
/*  
    ! Interface trong C++

    * Interface: là tất cả các phương thức trong Class đều là Abstract Class 
    thì được gọi là Interface.


    ! Interfaces in C++ (Abstract Classes)
    -Abstraction can be achieved by two ways:
        + abstraction class : hàm trừu tượng hóa
        + interfaces : giao diện
        
*/

#include <iostream>
using namespace std;


//!Interface là tất cả các hàm trong class đều là pure virtual function.
class Shape { //! => Interface 
protected:
	float dimension;
    int result;
    int ans;
public:
    Shape(float dimension = 12, int result = 5, int ans = 7) 
    : dimension(dimension), result(result), ans(ans) {};

    // pure virtual Function
    // virtual float calculateArea() {}
    virtual float calculateArea() = 0;  // pure virtual function
    virtual int getResult() = 0;        
    virtual int getAns() = 0;

};

class Square : public Shape{
public:
    float calculateArea() override {
        return dimension * dimension;
    }

    int getResult() {
        return this->result;
    }

    int getAns() {
        return this->ans + this->result;
    }

};

class Circle : public Shape{
public:
    float calculateArea() override {
        return 3.14 * dimension * dimension;
    }

    int getResult() {
        return this->result - this->ans;
    }

    int getAns() {
        return this->ans;
    }

};

int main() {

    //! Shape *shap = new Shape(); // Interface: thì không thể cấp phát động kiểu này.
    /* 
        không thể khai báo thế này vì hàm đó là Abstract Class với Pure Virtual Function
        ( có nghĩa là nó rỗng và class con phải định nghĩa lại hay OVerriding lại )
    */

    Shape *shape_list[2]; //! Interface: Nhưng vẫn có thể cấp phát kiểu này để quản lý các Overriding của hàm con.

    shape_list[0] = new Square();
    shape_list[1] = new Circle();

    for(int i = 0; i < 2; i++) {
        cout << "Calculate: " << shape_list[i]->calculateArea() << endl;
        cout << "getResult: " << shape_list[i]->getResult() << endl;
        cout << "getAns: " << shape_list[i]->getAns() << endl;
        cout << endl;
    }


	return 0;
}


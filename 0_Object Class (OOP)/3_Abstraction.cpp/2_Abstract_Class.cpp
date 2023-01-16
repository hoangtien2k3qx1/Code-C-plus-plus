
/*
   ! Pure Virtual Function in C++: Hàm thuần ảo trong C++
    Hàm thuần ảo(hàm trừu tượng) "Pure Virtual Function" được sử dụng khi:
        + không cần sử dụng hàm này trong lớp Cha(Base class). mà chỉ phục vụ cho lớp Con(Driver class)
        + lớp Con(Driver class) bắt buộc phải định nghĩa lại hàm thuần ảo.(hay ghi đè phương thức trừu tượng)


    Example:  Có hai cách để tạo một hàm ảo:
            *Cách 1:
                class Shape{
                    public:
                        virtual void calculateArea() = 0;     //! creating a pure virtual function.
                };

            *Cách 2:
                class Shape {
                    public:
                        virtual void calculateAre() {}
                };


    *CHÚ Ý:  
            + Hàm thuần ảo không có thân hàm và bắt buộc phải kết thúc với “= 0”.
            + Cú pháp “= 0” không phải là gán hàm thuần ảo có giá trị bằng 0. 
            Nó chỉ là cú pháp cho biết đó là hàm thuần ảo (pure virtual function).

*/

#include <iostream>
using namespace std;


//! Abstract class: nó chỉ cần 1 pure virtual function thì là Abstract Class
class Shape { //! => Abstrat Class
protected:
	float dimension;
public:
    Shape(float dimension = 12) : dimension(dimension) {};

    // pure virtual Function
    // virtual float calculateArea() {}
    virtual float calculateArea() = 0;  // pure virtual function

};

class Square : public Shape{
public:
    float calculateArea() override {
        return dimension * dimension;
    }
};

class Circle : public Shape{
public:
    float calculateArea() override {
        return 3.14 * dimension * dimension;
    }
};

int main() {

    //! Shape *shap = new Shape(); // không thể cấp phát động kiểu này.
    /* 
        không thể khai báo thế này vì hàm đó là Abstract Class với Pure Virtual Function
        ( có nghĩa là nó rỗng và class con phải định nghĩa lại hay OVerriding lại )
    */

    Shape *shape_list[2]; //! Nhưng vẫn có thể cấp phát kiểu này để quản lý các Overriding của hàm con.

    shape_list[0] = new Square();
    shape_list[1] = new Circle();

    for(int i = 0; i < 2; i++) {
        cout << "Result Function " << i + 1 << ": " << shape_list[i]->calculateArea() << endl;
    }


	return 0;
}


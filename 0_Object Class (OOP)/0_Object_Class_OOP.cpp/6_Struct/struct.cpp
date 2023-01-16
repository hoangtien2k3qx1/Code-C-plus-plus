
/*
    struct: 
        + là kiểu dữ liệu do người dùng tự định nghĩa
        + các thành viên trong struct đều là public

*/


//! ///////////////////////////
// C++ Struct Example: Using Constructor and Method

#include <iostream>    
using namespace std;   

struct Rectangle {      
    int width, height;      
    Rectangle(int w, int h)      
    {      
        width = w;      
        height = h;      
    }      
    void areaOfRectangle() {       
        cout<<"Area of Rectangle is: "<< (width * height); 
    }      
};      

int main(void) {    
    struct Rectangle rec = Rectangle(4, 6);    
    rec.areaOfRectangle();    
    return 0;    
}    


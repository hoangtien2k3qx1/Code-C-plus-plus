
/*
    Friend Function: Hàm Bạn
        Hàm friend là một hàm của lớp được định nghĩa bên ngoài phạm vi lớp nhưng nó có quyền 
        truy cập vào tất cả các thành viên riêng tư(private) và được bảo vệ(protected) của lớp.


    Declaration of friend function in C++:
        class class_name    
        {    
            friend data_type function_name(argument/s);   // syntax of friend function.  
        };    


    Nếu một hàm được định nghĩa là một hàm bạn bè trong C++, thì dữ liệu được bảo vệ 
    và riêng tư của một lớp có thể được truy cập bằng cách sử dụng hàm

*/

#include <iostream>    
using namespace std;    

class Box    
{    
    private:    
        int length;    
    public:    
        Box(): length(0) {}    
        friend int printLength(Box); // friend function    
};

int printLength(Box b)    
{    
    b.length += 10;    
    return b.length;    
}    

int main()    
{    
    Box b;    
    cout << "Length of box: "<< printLength(b) << endl;    
    return 0;    
}    
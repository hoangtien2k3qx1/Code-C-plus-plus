
/*  C++ bitset all() Function:

    Hàm all () bitset trong C ++ được sử dụng để kiểm tra xem tất cả các bit từ bitset 
    đã được thiết lập hay chưa. Nó trả về một giá trị boolean, tức là đúng hoặc sai.


    Syntax:
                bool all() const no except;  

    Parameter:
    It does not take any parameter.

    Return value:
    It returns a boolean value either true or false.

*/

#include <iostream>  
#include <bitset>  
using namespace std;  
int main()  
{  
    bitset<4> b;  
    bitset<4> mask("1111"); 

    if (!b.all())  
        cout << "All bits are not set." <<endl;  

    b |= mask;  
    
    if (b.all())  
        cout << "All bit are set." <<endl;  


    return 0;  
}


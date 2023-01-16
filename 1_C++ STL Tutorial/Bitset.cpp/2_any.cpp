
/*
    Hàm bit any () trong C ++ được sử dụng để kiểm tra xem ít nhất một bit từ bitet có 
    được đặt hay không. Nó trả về một giá trị boolean, tức là đúng hoặc sai.

    Syntax:
                    bool any();  


    Parameter:
    It does not take any parameter.

    Return value:
    It returns a Boolean value either 0 or 1.

*/

#include <iostream>  
#include <bitset>  
using namespace std;  
int main()  
{  
    bitset<4> b1(string("1100"));  
    bitset<4> b2(string("00"));  

    bool result1 = b1.any();  

    if (result1)  
        cout<< b1.count() << " has a minimum of one-bit set" <<endl;  
    else  
        cout<< b1.count() << " does not have any bits set" <<endl;  


    bool result2 = b2.any();  


    if (result2)  
        cout<< b2.count() << " has a minimum of one-bit set" <<endl;  
    else  
        cout<< b2.count() << " does not have any bits set" <<endl;  



    return 0;  
}  
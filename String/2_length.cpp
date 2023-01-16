
/*  
    ! C++ String length() : It's used to find the length of the string.

    This function is used to find the length of the string in terms of bytes.

    Syntax:
                int len = s1.length();  


    Parameters:
    This function contains single parameter.

    Return Value:
    This function returns the integer value in terms of bytes.



! trong C là strlen(str) còn C++ là str.length()

*/

#include<iostream>  
using  namespace std;

int main()  
{  
    string s1 = "Welcome to javatpoint";  // 21 ký tự tính cả khoảng trắng

    int len = s1.length();  

    cout << "length of the string is : " << len << endl; 

    return 0;  
} 
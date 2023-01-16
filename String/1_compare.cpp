
/*  
    ! C++ String compare: It is used to compare two string objects.

    Syntax :
                int k = str1.compare(str2);  
        
        k == 0 : it means both the strings are equal. // bằng nhau
        k != 0 : it means both the strings are unequal. // không bằng nhau
        k > 0  : either the value of the first character is greater in the compared string or all the compared characters match but the compared string is longer.
        k < 0  : either the value of the first character is lower in the compared string or all the compared characters match but the compared string is shorter.



*/

#include<iostream>  
using namespace std;  
int main()  
{  
    string str1 = "Welcome to javatpoint";  
    string str2 = "Welcome to javatpoint";  
    
    int k = str1.compare(str2);  
    if(k == 0)  
        cout << "strings are equal";  
    else  
        cout << "strings are not equal";  

    return 0;
}  
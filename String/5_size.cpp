
/*  C++ string size() :
    this function is used to return the length of the string in terms of bytes.

    syntax:

            str.sise();

    Parameters:
    This function does not contain any parameter.

    Return Value:
    This function returns the number of characters present in the string object.    

*/

//! LƯU Ý: thực chất length và size đều cho ra một kết quả => nó không khác nhau
// size thì hay được dùng trong vector
// length thì đươc dùng trong chuỗi


#include<iostream>  
using namespace std;  

int main()  
{  
    string str ="Welcome to the javatpoint tutorial";

    int size = str.size(); 

    cout << "length of the string is : " <<size << endl; 

    int length = str.length();

    cout << "Length of the string is: " << length;


    return 0;  
} 

/*  c++ string resize() :
    This function is used to resize the string to the length of k characters. 


    syntax:
            str.resize(size);
            str.resize(k, c);
            




*/

#include<iostream>  
using namespace std;  
int main()  
{  
    string str = "javatpoint";  
    cout<<"String is : " << str << endl;  

    str.resize(4);  // thay đổi kích thước còn lại 4

    cout<<"After resizing, string is: "<< str;  

    return 0;  
}   



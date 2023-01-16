
/*  
    !C++ string swap() : It is used to swap the values of two string objects
    syntax: 
            s1.swap(s2);


    Parameters
    It contains single parameter, whose value is to be exchanged with that of the string object.

    Return value
    It does not return any value.

*/

#include<iostream> 
#include<string> 
using namespace std;  

int  main()  
{  
    string r = "Hoang Anh Tien";  
    string m = "Hoang Anh Chung";

    cout << "Before  swap r contains " << r << endl << endl;
    cout << "Before  swap m contains " << m << endl << endl;

    r.swap(m);   

    cout << "After  swap r contains " << r<< endl << endl;
    cout << "After  swap m contains " << m<<endl << endl;

    return 0;  
}  

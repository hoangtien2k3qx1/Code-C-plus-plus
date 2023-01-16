/*
    Array of Pointer to Strings:

    + An array of pointer to strings is an array of character pointers that holds the 
    address of the first character of a string 


*/


#include <iostream> 
#include<stdlib.h> 
using namespace std;  
int main()  
{  
    char *names[5] = {"john",  
                    "Peter",  
                    "Marco",  
                    "Devin",  
                    "Ronan"};  
    for(size_t i=0;i<5;i++)  
    {  
        std::cout << names[i] << std::endl;  
    }  
    return 0;  
}  






#include <iostream>  
using namespace std;  

void func() {    
   static int i=0; //static variable    
   int j=0; //local variable    
   i++;    
   j++;    
   cout<<"i=" << i<<" and j=" <<j<<endl;    
}   

int main() {  
    func();    
    func();    
    func();    
}  


//////////
#include<iostream>  
using namespace std;    
void swap(int *x, int *y)  
{  
    int swap;  
    swap=*x;  
    *x=*y;  
    *y=swap;  
}  
int main()   
{    
    int x=500, y=100;    
    swap(&x, &y);  // passing value to function  
    cout<<"Value of x is: "<<x<<endl;  
    cout<<"Value of y is: "<<y<<endl;  
    return 0;  
}    
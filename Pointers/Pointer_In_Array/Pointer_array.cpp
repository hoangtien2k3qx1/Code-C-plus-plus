
// C++ considers the array name as the address of the first element.

#include <iostream>  

int main()  
{  
    int *ptr;  // integer pointer declaration  
    int marks[3]; // marks array declaration  
    std::cout << "Enter the elements of an array :" << std::endl;  

    for(int i=0;i<3;i++)  
    {  
        std::cin>>marks[i];  
    }  

    ptr=marks; // both marks and ptr pointing to the same element..  

    for (int i=0; i<3; i++) {
        std::cout << "Element_" << i << ": " << ptr[i] << std::endl;
    }
    std::cout << "The value of *ptr is :" <<*ptr<< std::endl;  
    std::cout << "The value of *marks is :" <<*marks<<std::endl;  

    return 0;
}  





//////////////
// Truy xuất ra kiểu dữ liệu trong C/C++
#include <iostream>
using namespace std;

int main()
{
	
	int value = 5;
	cout << typeid(&value).name() << endl;
	
	system("pause");
	return 0;
}


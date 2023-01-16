
// C++ Void Pointer

/*
    + Con trỏ void là một con trỏ có mục đích chung có thể chứa địa chỉ của bất kỳ kiểu 
    dữ liệu nào, nhưng nó không được liên kết với bất kỳ kiểu dữ liệu nào.

    // Error
    int *ptr;  
    float f=10.3;  
    ptr = &f; // error  


    // successfull
    void *ptr;
    int *ptr1;
    int a = 9;
    ptr = &a; 
    ptr1 = (int*)ptr;


*/


#include <iostream>  
using namespace std;  
int main()  
{  
    void *ptr; // void pointer declaration  
    int *ptr1; // integer pointer declaration
    int data=10; // integer variable initialization  

    ptr=&data;  // storing the address of data variable in void pointer variable  
    ptr1 = (int*)ptr; // assigning void pointer to integer pointer  
    // ptr1 = static_cast<int *>(ptr);
        std::cout << "The value of *ptr1 is : " << *ptr1 << std::endl;  



    ////////////////////////
    int value = 5;
    void *vPtr = &value;

    int *iPtr = static_cast<int *> (vPtr);  ép kiểu con trỏ void thành con trỏ int
    // int *iPtr = (int*) vPtr;
    cout << *iPtr << endl;

    int64_t * i64Ptr = static_cast<int64_t *> (vPtr); 
    // int64_t với long long và long int không khác biệt nhau là mấy
    // sizeof(long long) == sizeof(long int) == sizeof(int64_t)
    cout << *i64Ptr << endl;


    return 0;  
}  




////////////////////////
#include <iostream>
using namespace std;

enum Type
{
    INT,
    DOUBLE
};

void printValueOfPointer(void *ptr, Type type)
{
    switch (type)
    {
    case INT:
        cout << *(static_cast<int*>(ptr)) << '\n'; // ép con trỏ void thành con trỏ int
        break;
    case DOUBLE:
        cout << *(static_cast<double*>(ptr)) << '\n'; // ép con trỏ void thành con trỏ double
        break;
    }
}

int main()
{
    int nValue = 10;
    double dValue = 6.9;

    printValueOfPointer(&nValue, INT);
    printValueOfPointer(&dValue, DOUBLE);

    return 0;
}
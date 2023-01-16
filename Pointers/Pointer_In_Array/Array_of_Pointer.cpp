
// Array of Poin: (An array of pointers) is an array that consists of variables of pointer type


/*
    advantage of Pointer in C++
    + Con trỏ làm giảm mã và cải thiện hiệu suất, nó được sử dụng để truy xuất các chuỗi, cây, v.v. 
    và được sử dụng với các mảng, cấu trúc và hàm
    + Chúng ta có thể trả về nhiều giá trị từ hàm bằng con trỏ.
    + Nó giúp bạn có thể truy cập vào bất kỳ vị trí bộ nhớ nào trong bộ nhớ của máy tính.
    - Con trỏ với mảng:
    + địa chỉ của của mảng cũng chính là địa chỉ của phần tử đầu tiên trong mảng : &arr == &arr[0]

    + Vd: *ptr = &arr[0]: nghĩa là con trỏ sẽ trỏ vào địa chỉ đầu tiên của mảng và dùng vòng lặp để 
        truy xuất ra các phần tử trong mảng
    + con trỏ mảng giá trị là địa chỉ của một biến khác

    - Như chúng ta đã biết, địa chỉ của mảng một chiều cũng là địa chỉ của phần tử đầu tiên, 
    vì thế, đoạn chương trình bên dưới sẽ in ra 2 giá trị giống nhau:
    //show address of arr in virtual memory
    cout << &arr << endl;

    //show address of the first element of arr
    cout << &arr[0] << endl;

    - Điều này chứng tỏ rằng việc sử dụng tên mảng một chiều cũng đồng nghĩa đang sử dụng 
    địa chỉ của mảng một chiều (&arr tương đương với arr). Vì thế, chúng ta có thể in ra 
    địa chỉ của cả 5 phần tử của mảng arr bằng cách sau:
    + cout << arr << enld;
    + cout << arr + 1 << endl;
    + cout << arr + 2 << endl;
    + cout << arr + 3 << endl;
    + cout << arr + 4 << endl;

    - Chúng ta có thể thay phép gán ptr = &arr[0]; bằng phép gán ptr = &arr; 
    hoặc ngắn gọn hơn là ptr = arr; vì &arr[0], &arr hoặc arr đều cho chúng ta 
    địa chỉ của phần tử đầu tiên trong mảng arr.

    - Cũng là in ra toàn bộ giá trị của các phần tử trong mảng arr, nhưng sử dụng con trỏ chúng ta 
    có rất nhiều cách viết khác nhau:

*/


#include <iostream>  
using namespace std;  

int main()  
{  
    int ptr1[5]; // integer array declaration  
    int *ptr2[5]; // integer array of pointer declaration  
    std::cout << "Enter five numbers :" << std::endl;  
    for(int i=0;i<5;i++)  
    {  
        std::cin >> ptr1[i];  
    }  
    for(int i=0;i<5;i++)  
    {  
        ptr2[i] = &ptr1[i];   // giá trị của con trỏ là địa chỉ của 1 biến khác
    }  
    std::cout << "The values are" << std::endl;  
    for(int i=0;i<5;i++)  
    {  
        std::cout << *ptr2[i] << std::endl;  
    }  
}  


void Array_Pointer (int *arr) {
    for (size_t i = 0; i<9; i++) {
        std::cout << arr[i] << "\t";
    }
}

//  &arr[1] tương đương với (arr + 1) và arr[1] tương đương với *(arr + 1).

int main() {
    int brr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Array_Pointer(brr);
    // int *ptr = &brr[0]; // brr[0] tương đương với *arr (giá trị của một địa chỉ của con trỏ)
    int *ptr = brr;
    for (size_t i=0; i<9; i++) {
        std::cout << *(ptr + i) << " "; // C1 // &arr[1] tương đương với (arr + 1) và arr[1] tương đương với *(arr + 1).
        std::cout << ptr[i] << " "; // C2
        std::cout << brr[i] << " "; // C3;
        std::cout << *&brr[i] << " "; // C4
        std::cout << *&ptr[i] << " "; // C5
    }


    // cách viết khác
    // for (ptr = arr; ptr <= arr + 4; ptr++)
    // {
	// cout << *ptr << " ";
    // }



    /*
    &arr[1] tương đương với (arr + 1) và arr[1] tương đương với *(arr + 1).
    &arr[2] tương đương với (arr + 2) và arr[2] tương đương với *(arr + 2).
    &arr[3] tương đương với (arr + 3) và arr[3] tương đương với *(arr + 3).
    .
    .
    &arr[i] tương đương với (arr + i) và arr[i] tương đương với *(arr + i).
    */

    return 0;
}
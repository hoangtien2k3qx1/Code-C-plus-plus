
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


*/

#include <iostream>  
using namespace std;  
int main()  
{  
    int a=20,b=10,*p1=&a,*p2=&b;    
    cout<<"Before swap: *p1="<<*p1<<" *p2="<<*p2<<endl;    
    *p1=*p1+*p2;    
    *p2=*p1-*p2;    
    *p1=*p1-*p2;    
    cout<<"After swap: *p1="<<*p1<<" *p2="<<*p2<<endl;    
    return 0;  
}  
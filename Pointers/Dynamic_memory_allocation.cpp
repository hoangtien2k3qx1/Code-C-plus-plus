
// Dynamic memory allocation : cấp phát bộ nhớ động trong c++11

#include <iostream>

int main() {
    // cấp phát động
    int *p_int = new int; //C1
    // std::cout << "value into memory area: ";
    // std::cin >> *p_int;
    // std::cout << "Value at " << p_int << " is " << *p_int << std::endl;


    // vừa cấp phát bộ nhớ, vừa khởi tạo giá trị vùng nhớ
    int *p1_int = new int(5); // C2
    int *p2_int = new int { *p1_int };
    // std::cout << "value into memory area: ";
    // // std::cin >> *p2_int;
    // std::cout << "\nValue at " << p2_int << " is " << *p2_int << std::endl;


    // cấp phát động một mảng
    int *p_arr = new int[10]; // C3
    int *p_arr = new int[5] { 1, 2, 3, 4, 5 };
    // for (int i = 0; i < 10; i++)
    // {
    //     //Set value for each element
    //     std::cin >> p_arr[i];
    // }
    // for (int i=0; i<5; i++) {
    //     std::cout << *(p_arr + i) << " ";
    // }


    char *c_str = new char [100] { "Allocated on Heap partition" };



    int num_of_elements;
    cout << "Enter number of elements you want to create: ";
    cin >> num_of_elements;
    if(num_of_elements > 0)
        int *p_arr = new int[num_of_elements];

    delete[] p_arr;



    return 0;
}




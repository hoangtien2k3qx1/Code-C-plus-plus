
// Pointer to Pointer (con trỏ trỏ đến con trỏ)

// Lưu ý: không được gán int **p_to_p = &&value; //not valid ( như vậy là sai)

#include<iostream>
using namespace std;
int main()	{

	int value = 100;
	int *ptr = &value;
	int **p_to_p = &ptr;

    // int **p_to_p = &ptr || int *ptr = &value || int value = 10

    cout << endl;

    cout << "Dia chi bien value: " << endl;
    cout << &value << endl;
    cout << ptr << endl;
    cout << *(*&p_to_p) << endl;
    cout << *p_to_p << endl << endl; // địa chỉ được giữ bởi ptr

    cout << "Gia tri value: " << endl;
    cout << value << endl;
    cout << *&value << endl;
    cout << *ptr << endl;
    cout << *(*p_to_p) << endl << endl; // giá trị được giữ bởi ptr
    

    cout << "Dia chi ptr: " << endl;
    cout << &ptr << endl;
    cout << p_to_p << endl << endl; // địa chỉ của ptr

    cout << "Dia chi p_to_p: " << endl;
    cout << &*p_to_p << endl << endl;



	return 0;
}

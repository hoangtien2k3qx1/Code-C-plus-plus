
// Pointer_to_Pointer to Array 1 chiều

#include<iostream>
int main()	{

	int *p1 = NULL;
	int *p2 = NULL;
	int *p3 = NULL;
	int *p[] = { p1, p2, p3 };
	int **p_to_p = p;


    // hoặc
    int **p_to_p = new int*[3]; // cấp phát động mảng 1 chiều
    p_to_p[0] = p1;
    p_to_p[1] = p2;
    p_to_p[2] = p3;
    delete[] p_to_p;

}

//  2D dynamically allocated array
//  Pointer_to_Pointer to Array 2 chiều :

// VD: khai báo mảng tỉnh 2 chiều:     arr[5][10];

// một mảng các con trỏ được dùng để quản lý tập hợp các mảng một chiều này sẽ tạo thành mảng 2 chiều.

#include <iostream>
using namespace std;

int main()	{

	//Cấp phát vùng nhớ cho 3 con trỏ kiểu (int *)
	int **pToArrPtr = new int*[3];
	
	//Mỗi con trỏ kiểu (int *) sẽ quản lý 5 phần tử kiểu int
	for (int i = 0; i < 3; i++)
	{
		pToArrPtr[i] = new int[5];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> pToArrPtr[i][j];
		}
	}

	cout << "Mang 2 chieu: " << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << pToArrPtr[i][j] << "\t";
		}
		cout << endl;
	}

	//Giải phóng vùng nhớ cho từng dãy vùng nhớ mà 3 con trỏ đang quản lý
	for (int i = 0; i < 3; i++)
	{
		delete[] pToArrPtr[i];
	}
	
	//Giải phóng cho 3 biến con trỏ chịu sự quản lý của pToArrPtr
	delete[] pToArrPtr;

	return 0;
}



//! //////////////////////////////
Pointer to pointer to pointer to ...
	int ***ptrX3;
	int ******ptrX6;


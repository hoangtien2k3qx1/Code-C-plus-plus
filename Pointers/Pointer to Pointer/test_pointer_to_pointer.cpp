
// con trỏ cấp 2 trong C/C++

#include <iostream>
using namespace std;


// đây là dạng bài con trỏ cấp 2 nè


int main()	{

	//Cấp phát vùng nhớ cho 3 con trỏ kiểu (int *)
	int **pToArrPtr = new int*[3];
	
	for (int i = 0; i < 3; i++) {
		pToArrPtr[i] = new int[5];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
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

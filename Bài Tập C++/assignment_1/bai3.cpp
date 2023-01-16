
//* Nhóm 11

/*
    a. Viết một chương trình nhập vào một dãy n số nguyên
    b. xuất dãy vừa nhập
    c. Tính trung bình cộng các số dương và chia hết cho 3
    d. Tìm phần tử nhỏ nhất, in ra kết quả
    m. sắp xếp mảng tăng dần

*/

#include<bits/stdc++.h>
using namespace std;

// a. Viết một chương trình nhập vào một dãy n số nguyên
int * inputArray(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}


// b. xuất dãy vừa nhập
void display(int * arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


// c. Tính trung bình cộng các số dương và chia hết cho 3
int TBC(int * arr, int n) {
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++)  {
        if (arr[i] > 0 && !(arr[i] % 3)) {
            sum += arr[i];
            ++count;
        }
    }
    return sum/count;
}


// d. Tìm phần tử nhỏ nhất, in ra kết quả
int find_min(int * arr, int n) {
    int min = arr[0];
    for(int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


// sắp xếp nhanh QuickSort
int partition(int *arr, int l, int r) {
	int pivot = arr[l];
	int i = l, j = r;
	while(true) {
		while(arr[i] < pivot) ++i;
		while(arr[j] > pivot) --j;
		if (i < j) {
			swap(arr[i], arr[j]);
			i++; j--;
		} else return j;
	}
}

void quickSort(int *arr, int l, int r) {
	if (l >= r) return;
	int p = partition(arr, l, r); // return j
	quickSort(arr, l, p);
	quickSort(arr, p + 1, r);
}


int main() {
    int arr[100];
    int n; cout << "Nhap vao n so nguyen: "; cin >> n;

    cout << "Nhap vao cac phan tu mang: ";
    inputArray(arr, n);

    cout << "Xuat mang vua nhap: ";
    display(arr, n);

    cout << "\nTBC so duong va chia het cho 3: " << TBC(arr, n);
    cout << "\nPhan tu nho nhat trong mang: " << find_min(arr, n);
    cout << "\nSap xep mang tang dan: ";
    
    quickSort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}


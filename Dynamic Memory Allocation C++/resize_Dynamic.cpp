

// THAY ĐỔI KÍCH THƯỚC KHI CẤP PHÁT ĐỘNG TRONG C++

#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

//! Cách 1:
void resize(int *&arr, int newsize) { // phải là *&arr để có thể thay đổi được giá trị trong hàm
    delete[] arr;
    arr = new int[newsize];
}

int main() {
    int *arr = new int[10];
    resize(arr, 1000);
    for(int i=0; i<1000; i++) {
        arr[i] = i;
    }
    for(int i = 0; i < 1000; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}








//!  Cách 2:
#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

// Cách 2:
void resize(int **arr, int newsize) { // hoặc **arr dùng con trỏ cấp 2 để thay đổi được giá trị trong hàm
    delete[] *arr;
    *arr = new int[newsize];
}

int main() {
    int *arr = new int[10];
    resize(&arr, 1000);
    for(int i=0; i<1000; i++) {
        arr[i] = i;
    }
    for(int i = 0; i < 1000; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
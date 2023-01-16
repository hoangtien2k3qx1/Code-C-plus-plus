
/*
    Cấp phát động cho mảng 2 chiều C++:


*/

#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int SumElementsArray(int m, int n, int **arr) {
    int sum = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}


int main() {
    int m, n;
    cin >> m >> n; // m hàng , n cột

    int **arr = new int* [n]; // Cấp phát động mảng 2 chiều
    for(int i=0; i<n; i++) {
        arr[i] = new int[m];
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << SumElementsArray(m, n, arr);
    
    for(int i=0; i<m; i++) {
        delete[] arr[i]; // giải phóng bộ nhớ con các mảng 1 chiều;
    }

    delete[] arr;

    return 0;
}
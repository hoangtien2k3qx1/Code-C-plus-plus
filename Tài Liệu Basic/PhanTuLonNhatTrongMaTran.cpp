
/*
    Tìm phần tử lớn nhất trong ma trận và liệt kê cá vị trí xuất hiện của nó trong ma trận

    1 <= T <= 100
    -10^9 <= A(ij) <= 10^9

    Ex:  Nhập
        3 4
        1 2 8 3
        2 3 8 8
        1 5 2 3

    => solution() = 8
                vi tri xuat hien: A[1][3]
                vi tri xuat hien: A[2][3]
                vi tri xuat hien: A[2][4]

*/

#include<bits/stdc++.h>
#include<algorithm>

void solution(int m, int n, int arr[][100]) {
    int max_value = INT_MIN; // vi ( -10^9 <= A(ij) <= 10^9 )
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (arr[i][j] > max_value) 
                max_value = arr[i][j];
        }
    }
    std::cout << max_value << std::endl;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (max_value == arr[i][j]) {
                std::cout << "Vi tri xuat hien: " << "A["<<(i + 1)<<"]["<<(j + 1)<<"]" << std::endl; 
            }
        }
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;
    int arr[100][100];
    for(int i=0; i<m; i++) {
        for(int j=0; j <n; j++) 
            std::cin >> arr[i][j];
    }

    solution(m, n, arr);

    return 0;   
}
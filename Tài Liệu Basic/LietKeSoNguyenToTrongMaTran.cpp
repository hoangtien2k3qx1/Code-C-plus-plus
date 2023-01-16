
/*
    Cho ma trận các số nguyên tố. Hãy liệt kê các số nguyên tố trong ma trận theo thứ tự xuất hiện.
    Nếu có số nguyên tố xuất hiện nhiều lần thì in ra 1 lần duy nhất

    Ex:
        1 7 8
        2 3 3 
        7 5 2 
    => solution() = 7 2 3 5


*/

#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<stdbool.h>

bool NguyenTo(int n) {
    if (n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void InSoNguyenTo(int m, int n, int arr[][100]) {
    std::map<int, int> mp;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (NguyenTo(arr[i][j]) && mp[arr[i][j]] == 0) { // mp[arr[i][j]] điều kiện check
                std::cout << arr[i][j] << " ";
                mp[arr[i][j]] = 1; // để dánh dấu cái map đã được in ra rồi
            }
        }
    }
}

int main() {    
    int m, n;
    std::cin >> m >> n;
    int arr[100][100];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) 
            std::cin >> arr[i][j];
    } 
    
    InSoNguyenTo(m, n, arr);

    return 0;
}

/*
    Tìm cột có nhiều số Fibonacci nhất trong ma trận
    
    Trong tường hợp, có nhiều cột có cùng số lượng số Fibinacci thì in ra cột có tổng số Fibonacci lớn nhất

    Output:
        in ra cột có nhiều số Fibonacci nhất
        Liệt kê các số Fibonacci trong cột đó

    Example: 
            4   4
            1   2   3   5
            2   2   5   8
            10  1   2   3
            21  13  3   3

        =>  4
            5   8   3   3

*/

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include<set>
using namespace std;


set<long long> fibo;

void init() {
    long long f[93];
    f[0] = 0;
    f[1] = 1; 
    for(int i=2; i <= 92; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    for(int i=0; i<=92; i++) {
        fibo.insert(f[i]);
    }
}


int solution(int m, int n, int arr[][500]) {
    int ans = -1, cot;
    long long sum = 0;
    for(int i=0; i<n; i++) {
        long long temp = 0;
        int dem = 0;
        for(int j=0; i<m; j++) {
            if (arr[j][i] == 1) {
                ++dem;
                temp += arr[j][i];
            }
        }
        if (dem > ans) {
            cot = i;
            ans = dem;
            sum = temp;
        } else if(dem == ans) {
            if (sum < temp) {
                cot = i;
                sum = temp;
            }
        }
    }
    cout << cot + 1 << endl;
    for(int i=0; i < m; i++) {
        if (fibo.count(arr[i][cot]) == 1) {
            cout << arr[i][cot] << " ";
        }
    }
    cout << endl;
}

int main() {
    init();

    int m, n;
    cin >> m >> n;
    int arr[500][500];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }


    solution(m, n, arr);



    return 0;
}
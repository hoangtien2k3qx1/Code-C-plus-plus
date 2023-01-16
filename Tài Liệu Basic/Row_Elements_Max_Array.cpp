
/*
    liệt kê các dòng có tổng phần tử lớn nhất

    Example: 
        4 4
        1 2 3 4
        2 3 4 9  
        1 2 8 6 
        4 8 1 5  

    =>  18          // có tổng là 18
        2 4         // dòng 2 và dòng 4

*/

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void solution(int m, int n, int arr[][100]) {
    long long max = -1e18; // -1e18 số bé nhất( để không vượt quá stack )
    
    vector<int> row; // tạo một vector để lưu hàng có tổng lớn nhất
    for(int i=0; i<m; i++) {
        long long sum = 0;
        for(int j=0; j<n; j++) {
            sum += arr[i][j];
        }
        
        if (sum > max) {
            max = sum;
            row.clear();
            row.push_back(i);

        } else if (sum == max) {
            row.push_back(i);
        }
    }

    cout << max << endl;
    for(vector<int>::iterator itr = row.begin(); itr != row.end(); itr++) {
        cout << *itr + 1 << " ";
    }

    cout << endl;
}



int main() {
    int m, n;
    cin >> m >> n;
    int arr[100][100];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    } 

    solution(m, n, arr);

    return 0;
}

// đếm các phần tử xuất hiện trong mảng só nguyên
#include<bits/stdc++.h>
#include<iostream>
#include<set>
using namespace std;

int Set(int n){
    set<int> set; // dùng set
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        set.insert(x);
    }
    return set.size();
}


// dùng mảng đánh dấu
int Array(int n) {
    int arr[n];
    for(int & x : arr) {
        cin >> x;
    }
    sort(arr, arr + n);
    int ans = 1;
    for(int i=1; i<n; i++) {
        if (arr[i] != arr[i - 1]) {
            ++ans;
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    cout << Set(n) << endl;

    cout << Array(n) << endl;

    return 0;
}
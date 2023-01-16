
// Tìm phần tử xuất hiện trong mảng

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int UsingSet(int n) {
    set<int> set;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        set.insert(x);
    }
    return set.count(n) ? true : false;
}

int main() {
    int n; cin >> n;

    cout << UsingSet(n) << endl;



    return 0;
}
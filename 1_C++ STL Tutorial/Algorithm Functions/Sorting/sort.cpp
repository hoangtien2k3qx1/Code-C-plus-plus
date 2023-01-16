
/*
    ! C++ Algorithm sort() : The function sorts all the elements in a range.
    => hàm này để sắp xếp các phần tử trong một phạm vi
   
    Link: https://www.javatpoint.com/cpp-algorithm-sort-function



    sort(a, a + n)   // sắp xếp tăng dần
    sort(a + x, a + y) => a[x, y-1];     // sắp xếp tăng dần trên đoạn

    sort(a, a + n, less<int>())  // sắp xếp tăng dần
    sort(a, a + n, greater<int>())   // sắp xếp giảm dần

    sort(a.begin(), a.end())   // sort(a.begin() + x, a.end() + y + 1) => a[x, y];
    sort(a.begin(), a.end(), greater<int>())   // sắp xếp giảm dần


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
    int a[10];
    for(int i=0; i<10; i++) {
        cin >> a[i];
    }

    sort(a, a + 10); // sắp xếp tăng dần
    for(int x : a) {
        cout << x << " ";
    }
    cout << endl;

    sort(a, a + 10, greater<int>());
    for(int x : a) {
        cout << x << " ";
    }   
    cout << endl;

    sort(a, a + 10, less<int>()); // sắp xếp tăng dần
    for(int x : a) {
        cout << x << " ";
    }   

}



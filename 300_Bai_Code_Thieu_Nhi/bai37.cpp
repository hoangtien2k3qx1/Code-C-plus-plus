
/*
    viết chương trình nhập vào số nguyên n, Tìm số nguyên dương n lớn nhất sao cho:
        1 + 2 + 3 + ... + n < m;

*/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the n = ";
    cin >> n;
    int sum  = 0;
    for(int i=1; i<=n; i++) {
        sum += i;
        if (sum > n) {
            cout << "Index max: " <<  i - 1 << endl;
            return 0;
        }
    }
    return 0;
}
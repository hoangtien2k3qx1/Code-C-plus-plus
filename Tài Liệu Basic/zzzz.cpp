

#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int s1, s2, s3;
    int d = 1000000007;

    cin >> s1 >> s2 >> s3;

    long long h;
    if (s1 % s3) {
        s1/=s3;
        h = sqrt(((s1 % d) * (s2 % d)) % d);
    } else if (s2 % s3) {
        s2/=s3;
        h = sqrt(((s1 % d) * (s2 % d)) % d);
    } else {
        h = sqrt(s1 * s2) / s3;
    }


    cout << h;
    // cout << (a + b + h) * 4 << endl;
    
    
    return 0;
}
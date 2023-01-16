
// đếm xem chỗi có bao nhiêu từ

#include<iostream>
#include<cmath>
#include<string>
#include<bits/stdc++.h>
using namespace std;


int main() {
    string str = "abc def ghi";
    stringstream ss(str);
    
    string token;
    
    int count = 0;
    while (ss >> token)
    {
        printf("%s\n", token.c_str());
        ++count;
    }

    printf("\n%d", count);

    return 0;
}
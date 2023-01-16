/*
!   stoi() : hàm này dùng để chuyển chuỗi số sang số int

    Syntax: 
            stoi(s1);

*/
#include<iostream>
#include<string>
using namespace std;

int main() {    
    string a = "12345";

    int x = stoi(a);

    cout << x << endl;

    cout << "3 + 12345 = " << 3 + x << endl;


    return 0;
}
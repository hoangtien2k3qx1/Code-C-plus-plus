
/*  C++ deque stoll() : 
    Hàm này chuyển chuỗi thành số trả về long long



*/

#include<iostream>
#include<string>
#include<cmath>
#include<math.h>
using namespace std;

int main() {    
    string a = "1234532875157346";

    long long x = stoll(a);

    cout << x << endl;

    return 0;
}
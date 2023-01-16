

#include<iostream>
#include<string>
using namespace std;
 
string add(string a, string b)
{
    string res = ""; // todo: dùng để chứa kết quả

    while(a.length() < b.length()) a = "0" + a; //! cộng thêm các ký tự '0' vào string
    while(a.length() > b.length()) b = "0" + b; //! cộng thêm các ký tự '0' vào string

    int carry=0; // biến nhớ

    for(int i = a.length() - 1; i >= 0; i--)
    {    
        int temp = int(a[i] - '0') + int(b[i] - '0') + carry;
        res = char(temp % 10 + '0') + res;
        carry = temp / 10;
    }

    if(carry > 0) res = char(carry + '0') + res; // res = "1" + res;

    return res;
}

int main() {
    string a, b;
    std::cin >> a >> b;
    std::cout << add(a, b) << std::endl; // ! 

    return 0;
}




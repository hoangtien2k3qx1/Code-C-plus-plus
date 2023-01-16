
/*
    C++ stringstream(): tách các từ trong chuỗi trong C++

    SYNTAX: 
            stringstream a(s1);


    
    ! //
    ! Để sử dụng stringstream, chúng ta cần include thư viện sstream:

    #include <sstream>

*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    // string s = "java python PHP HTME";

    // stringstream ss(s);
    
    // string temp;
    // while(ss >> temp) {
    //     cout << temp << endl;
    // }

    std::stringstream ss;
    ss << "I'm learning" << " " << "C++ programming language" << std::endl;
    std::cout << ss.str();





    
    return 0;
}

/*
    Nhập vào một số tự nhiên n (n khai báo kiểu unsigned long)
    a. số tự nhiên n có bao nhiêu chữ số
    b. hãy tìm chữ số cuối cùng của n
    c. hãy tìm chữ số đầu tiên của n
    d. tính tổng các chữ số của n
    e. hãy tìm số đảo ngược của n. 

*/

#include<iostream>
#include<cmath>

int main() {
    int n, t1, count = 0, res = 0, sum = 0, t;
    std::cout << "Nhap vao so n = "; std::cin >> n;
    for (int i=0; i<n; i++) {
        t = n % 10;
        res = res * 10 + t;
        n /= 10;
        sum += t;
        t1 = t; 
        count++;  
    }

    std::cout << "So chu so cua n la: " << count << std::endl;
    std::cout << "Chu so dau tien cua n la: " << t1 << std::endl;
    std::cout << "Chu so cuoi cung cua n la: " << n % 10 << std::endl;
    std::cout << "Tong cac chu so cua n la: " << sum << std::endl;
    std::cout << "Chu so dao nguoc n la: " << res << std::endl;



    return 0;
}
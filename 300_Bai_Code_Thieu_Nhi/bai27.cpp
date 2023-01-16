
/*
    Nhập vào số nguyên dương n. Phân tích n thành thừa số nguyên tố

*/
#include<iostream>
#include<cmath>

int main() {
    int n;
    std::cout << "Nhap vao n = "; std::cin >> n;

    for (int i=2; i<=n; i++) {
        while (n % i == 0) {
            n /= i;
            if (n > 1) {
                std::cout << i << " * ";
            } else {
                std::cout << i ;
            }
        }
    }

    return 0;
}




/*
    Viết một chương trình liệt kê, và đếm tất cả các ước số của số nguyên dương n( n nhập từ bàn phím)

    VD:
        Nhap n: 1966 
        Cac uoc so: 1 2 983 1966
        Co 4 uoc so, tong la: 2952

*/

#include<iostream>
#include<cmath>

void Check_Uoc (int n) {
    int sum = 0, count = 0;
    std::cout << "Cac uoc so: "; 
    for (int i=1; i<=n; i++) {
        if (n % i == 0) {
            std::cout << i << " ";
            count++;
            sum += i;
        }
    }
    std::cout << "\nTong co " << count << " uoc so" << std::endl;
    std::cout << "Tong la: " << sum << std::endl; 
}

int main() {
    int n;
    std::cout << "Nhap vao n = ";
    std::cin >> n;

    Check_Uoc (n);
   

    return 0;
}



/*
    Viết chương trình tìm các số hoàn hảo (perfect number) nhỏ hơn một số
    nguyên dương n cho trước. Biết số hoàn hảo là số nguyên dương, bằng tổng các ước
    số thực sự của nó (ví dụ: 28 = 14 + 7 + 4 + 2 + 1).


    VD: Nhap n: 10000 
        Cac so hoan hao nho hon 10000: 6 28 496 8128
*/

#include<iostream>
#include<cmath>

void SoHoanHao (int n) {

    // int i, j, sum;
    // for ( i = 1; i < n; ++i ) {
    //     for ( sum = 0, j = 1; sum <= i && j <= i / 2; ++j )
    //         if ( i % j == 0 ) sum += j;
    //     if ( sum == i ) std::cout << i << " ";
    // }

    
    for (int i=1; i<=n; i++) {
        int j=1, sum = 0;
        while (sum <= i && j <= i/2) {
            if (i % j == 0) sum += j;
            j++;
        }
        if (sum == i){
            std::cout << i << " ";
        }
        sum = 0;
    }

}

int main() {    
    int n;
    std::cout << "Nhap vao so n = ";
    std::cin >> n;

    std::cout << "Cac so hoan hao nho hon " << n << ": ";
    SoHoanHao(n);

    return 0;
}



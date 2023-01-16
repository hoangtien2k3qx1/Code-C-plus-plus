
/*
    ! RÚT gọn phân số đến khi tối giản

    * chỉ cần chia cả tử và mẫu của a và b cho UCNN

*/

#include<iostream>
#include<cmath>

int gcd( int a, int b ) {
    return (!a) ? b : gcd(b % a, a);
}

int main() {
    int a, b;
    std::cout << "Nhap vao a va b: "; std::cin >> a >> b;

    int t = gcd(a, b);
    std::cout << "Rut gon phan so: " << a/t << "/" << b/t << std::endl;

    return 0;
}
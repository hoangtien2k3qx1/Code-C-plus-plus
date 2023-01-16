
/*
    nhập vào hai số a và b. Tính UCLN và BCNN của a và b

*/

// C1:
#include<iostream>
#include<cmath>

int main() {
    int a, b;
    std::cout << "Nhap vao a va b: "; std::cin >> a >> b;

    int gcd = a; // Greatest common Divisor
    while (a % gcd != 0|| b % gcd != 0) gcd--;
    std::cout << "UCLN (a, b): " << gcd << std::endl;

    int lcm = a; // Least common Multiple
    while (lcm % a || lcm % b) lcm++;

    std::cout << "BCNN (a, b): " << lcm << std::endl;

    return 0;
}




// C2:
#include <stdio.h>
    int main() {
    unsigned a, b, c;
    printf( "Nhap cap (a, b): " );
    scanf( "%u%u", &a, &b );
    c = a * b;
    while ( a - b ) ( a > b ) ? ( a -= b ) : ( b -= a );
    printf( "USCLN (a, b): %u\n", a );
    printf( "BSCNN (a, b): %u\n", c/a );
    return 0;
}

//! làm tròn số thực
//! làm tròn đến số sau dấu chấm mong muốn


#include <stdio.h>
#include <math.h>


    int main() {
    double x;
    long round;
    unsigned n;
    printf( "Nhap so thuc x: ");
    scanf( "%lf", &x );
    printf( "Do chinh xac: ");
    scanf( "%u", &n );

    x = x * pow(10, n);
    if (x > 0) 
        round = (long)(x + 0.5);
    else 
        round = (long)(x - 0.5);
        
    x = round / pow(10, n);

    printf("%.*lf\n", n > 0 ? n : 0 , x);

    return 0; 
}



/*
    Chuỗi định dạng: %.*lf có ý nghĩa như sau:
    Ký tự * cho biết số ký tự dành chỗ được chỉ định bởi một tham số (kiểu int) của
    printf() tại vị trí tương ứng.
    Nghĩa là:
    printf( "%.*lf\n", n , x );
    Với n = 4, tương đương với: printf( "%.4lf\n", x );

*/
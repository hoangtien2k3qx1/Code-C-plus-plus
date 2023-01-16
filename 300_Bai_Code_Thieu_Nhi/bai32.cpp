


#include <stdio.h>

int main() {
    char c;
    do {
    unsigned n;
    printf( "Nhap n: " );
    scanf( "%u", &n );
    while ( getchar() != '\n' ) { }
    unsigned num = 0, i = 0;
    while ( 1 ) {
    printf( "%5u", n );
    if ( n == 1 && num > 1 && ++num ) break;
    if ( n % 2 ) n = n * 3 + 1;
    else n /= 2;
    num++; i++;
    if ( i % 6 == 0 ) putchar( '\n' );
    }
    printf( "\nHailstones sinh duoc: %u\n", num );
    do {
    printf( "Tiep (y/n)? ");
    scanf( "%1[^\n]c", &c );
    while ( getchar() != '\n' ) { }
    } while ( c != 'y' && c != 'n' );
    } while ( c != 'n' );
    return 0;
}
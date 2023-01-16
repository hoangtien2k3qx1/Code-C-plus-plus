
// in ra bảng cửu chương

#include<stdio.h>
#include<math.h>
#include<conio.h>

int main() {

    printf("Bang Cuu Chuong: \n");

    for(int i=1; i<=10; i++) {
        for(int j=1; j<=9; j++) {
            printf("%c%2u x %2u = %2u", 179, j, i, j * i);
        }
        printf("%c\n", 179);
    }




    return 0;
}
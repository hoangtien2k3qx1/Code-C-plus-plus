/*
    Nhập một dãy số nguyên t1, t2 ... tn.
    In dãy số ra màn hình mỗi số trên 1 dòng.
    Tìm số chia hết cho 9 lớn nhất trong dãy. Không có số chia hết cho 9 phải in thông báo
*/

#include<stdio.h>
#include<math.h>
#include<algorithm>

void printf_Array(int *arr, int n) {
    printf("\n=> Cac Phan Tu Trong Mang <=\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

}

int soChiaHetCho9(int *arr, int n) {
    int max = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] % 9 == 0) {
            max = arr[i];
        }
    }
    return max;
}


int main() {
    int n;
    printf("\nNhap vao so phan tu: ");
    scanf("%d", &n);
    int *arr = new int[n];
    
    for(int i = 0 ; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf_Array(arr, n);    
    if (soChiaHetCho9(arr, n) != 0) {
        printf("\nSo Lon Nhat Chi Het Cho 9: %d", soChiaHetCho9(arr, n));
    } else {
        printf("\nKhong Co So Nao Chia Het Cho 9 !!!");
    }

    return 0;
}
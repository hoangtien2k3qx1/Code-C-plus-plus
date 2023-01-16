
/*  bài 35: 
    ! Viết một chương trình kiểm tra số nguyên dương n có phải là số nguyên tố hay không. Nếu không thì
    ! phải xác định số nguyên tố n gần nhất bà bé hơn n.

*/
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

#define max 10000001
int arr[max];

int NguyenTo (int n) {
    for(int i=2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return n>1;
}

void Sang_Nguyen_To(int n) {
    for(int i=0; i<=n; i++)
        arr[i] = 1; 
    arr[0] = arr[1] = 0; // loại bỏ số 0 và số 1.
    for(int i=2; i<=sqrt(n); i++) {
        if (arr[i] == 1) { // nếu i  là số nguyên tố.
            for(int j = i * i; j <= n; j += i){
                arr[j] = 0; // j không còn là số nguyên tố nữa.
            }
        }
    }
}

int swap_array_arr(int n) {
    int max_array = 0;
    Sang_Nguyen_To(n);
    for(int i = 0; i <= n-1; i++) {
        if (arr[i]) {
            if (i >= max_array) {
                max_array = i;
            }
        }
    }
    return max_array;
}

int main() {    
    int n;
    printf("Enter the digit n = ");
    scanf("%d", &n);
    if (NguyenTo(n)) {
        cout <<  n << " is Prime" << endl;
        return 0;
    } else {
        cout << n << " No is Prime" << endl;
    }
    cout << "Prime at lest " << n << ": " << swap_array_arr(n) << endl;

    return 0;
}











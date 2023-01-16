
/*
    Viết chương trình in ra n số nguyên tố đầu tiên

    Ex: 
    n = 15;
        => 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

*/
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

#define max 10001
int arr[max];

int sang_nguyen_to(int n) {
    for(int i = 0; i < max; i++)  {
        arr[i] = 1; // coi tat ca la so nguyen to
    }
    arr[0] = arr[1] = 0; 
    for(int i = 2; i <= sqrt(max); i++) {
        if (arr[i]) {
            for(int j = i * i; j < max; j += i) {
                arr[j] = 0;
            }
        }
    }
}

void Print_sangnguyento(int n) {
    int count = 0;
    sang_nguyen_to(n);
    for(int i = 0; i <= 47; i++) {
        if (arr[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    int n;
    cout << "Enter the n = ";
    cin >> n;

    cout << "All Prime 2 -> n: ";
    Print_sangnguyento(n);

    return 0;
}
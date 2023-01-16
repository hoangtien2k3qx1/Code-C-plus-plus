
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

float Do_Tin_Cay(float * arr, int n) {
    float result = 0.0;
    for(int i = 0; i < n; i++) {
        result += arr[i];
    }
    return (float)result/n;
} 

int main() {
    system("cls");
    long long n; cout << "Nhap vao n phan tu: "; cin >> n;
    float * arr = new float[n];

    for(int i = 0; i < n; i++) {
        cout << "arr["<<i<<"] = ";
        cin >> arr[i];
    }

    cout << "\n=> Khoang Tin Cay Gia Tri Trung Binh: " << setprecision(2) << fixed << Do_Tin_Cay(arr, n);

    cin.get();
    return 0;
}
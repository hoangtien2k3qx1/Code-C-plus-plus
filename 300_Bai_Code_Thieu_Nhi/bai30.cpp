
/*
    Viết chương trình nhập lãi xuất năm r (%), tiền vốn p và thời hạn gởi tiền n
    (năm). Mỗi trị nhập phải cách nhau bởi dấu “,”. In ra vốn tích lũy a của từng năm.
    Chương trình có kiểm tra nhập thiếu hoặc nhập lỗi   


    a = p(1 + r)n
    Trong đó, a (mount) là vốn tích lũy được, p (principal) là vốn gốc, r là
    (rate) lãi suất và n là số năm đầu tư.


    Nhap lai suat, tien von, thoi han: 0.027, 15000, 3 
*/

#include<iostream>
#include<cmath>
#include<string>

// bài toán lãi kép
typedef struct LaiXuat {
    double p;  // số vốn ban đầu
    float r;  // lãi xuất năm
    int n; // số năm
} LaiXuat;

float TienLaiHangNam() {
    LaiXuat ptr;
    return (ptr.p * pow((1 + ptr.r), ptr.n));
}

int main() {
    LaiXuat p;
    printf("Nhap vao p: ");
    scanf("%lf", &p.p);
    printf("Nhap vao r: ");
    scanf("%f", &p.r);
    printf("Nhap vao n: ");
    scanf("%d", &p.n);


    printf("%f", TienLaiHangNam());

    return 0;
}
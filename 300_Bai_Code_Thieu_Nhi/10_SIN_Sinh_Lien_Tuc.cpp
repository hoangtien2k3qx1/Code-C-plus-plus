
/*
    * Số bảo hiểm xã hội của Canada (SIN - Canadian Social Insurance Number)
    là một số có 9 chữ số, được kiểm tra tính hợp lệ như sau:
    - Số phải nhất (vị trí là 1, tính từ phải sang), là số kiểm tra (check digit).
    - Trọng số được tính từ phải qua trái (không tính check digit), bằng s1 + s2:
    + s1 là tổng các số có vị trí lẻ.
    + Các số có vị trí chẵn nhân đôi. Nếu kết quả nhân đôi có hai chữ số thì kết quả là
    tổng của hai chữ số này. s2 là tổng các kết quả.
    SIN hợp lệ có tổng trọng số với số kiểm tra chia hết cho 10.

    ! Ví dụ: SIN 193456787
    - Số kiểm tra là 7 (màu xanh tô đậm).
    - Trọng số là tổng của s1 và s2, với:
    + s1 = 1 + 3 + 5 + 7 = 16
    + Các số có vị trí chẵn nhân đôi: (9 * 2) (4 * 2) (6 * 2) (8 * 2)  18 8 12 16
    s2 = (1 + 8) + 8 + (1 + 2) + (1 + 6) = 27
    Trọng số bằng s1 + s2 = 16 + 27 = 43.
    Vì tổng trọng số với số kiểm tra 43 + 7 = 50 chia hết cho 10 nên số SIN hợp lệ.
    Viết chương trình nhập một số SIN. Kiểm tra xem số SIN đó có hợp lệ hay không

*/

//! Ví dụ: SIN 193456787

#include<iostream>
#include<cmath>
#include<string>

int sum_s1 (int arr[]) {
    int sum1;
    for (int i=0; i<8; i+=2) {
        sum1 += arr[i];
    }
    return sum1;
}

int sum_s2 (int arr[]) {
    int sum2, t;
    for (int i=1; i<8; i+=2) {
        if (arr[i] * 2 > 10) {
            t = arr[i] * 2;
            sum2 += ((t%10) + (t/10));
        } else {
            sum2 += arr[i];
        }
    }
    return sum2;
}

int main() {
    int SIN, sum1, sum2;
    std::cout << "Nhap vao SIN = ";
    std::cin >> SIN;

    int arr[9];
    for (int i=0; i<9; i++) {
        arr[i] = SIN % 10;
        SIN /= 10;
    }

    int Sum = sum_s1 (arr) + sum_s2 (arr) + arr[8];
    if (Sum % 10 == 0) {
        std::cout << "SIN hop le!";
    } else {
        std::cout << "SIN khong hop le!";
    }


    return 0;
}

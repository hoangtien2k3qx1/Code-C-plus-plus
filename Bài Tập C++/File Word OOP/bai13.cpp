
/*
    Câu 13: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
        2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
        3.	Nhập vào hai ma trận đồng cấp. Thực hiện cộng hai ma trận vừa nhập (dùng hàm bạn). In ra màn hình hai ma trận ban đầu và ma trận kết quả.


*/

#include<bits/stdc++.h>
using namespace std;

class MaTrix {
    private:
        int m, n;
        float arr[100][100];
        float brr[100][100];
        float crr[100][100];

    public:
        MaTrix() {
            this->m = m;
            this->n = n;
        }
    void inputArray1();
    void inputArray2();
    friend void Sum_Two_Matrix(MaTrix);

};

void MaTrix::inputArray1() {
    cout << "Nhap vao so hang 1: "; cin >> m;
    cout << "Nhap vao so cot 1: "; cin >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "arr["<<i<<"]["<<j<<"] = ";
            cin >> arr[i][j];
        }
    }
}

void MaTrix::inputArray2() {
    cout << "Nhap vao so hang 2: "; cin >> m;
    cout << "Nhap vao so cot 2: "; cin >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "brr["<<i<<"]["<<j<<"] = ";
            cin >> brr[i][j];
        }
    }
}

void Sum_Two_Matrix(MaTrix matrix) {
    for(int i = 0; i < matrix.m; i++) {
        for(int j = 0; j < matrix.n; j++) {
            matrix.crr[i][j] = matrix.arr[i][j] + matrix.brr[i][j];
        }
    }
    for(int i = 0; i < matrix.m; i++) {
        for(int j = 0; j < matrix.n; j++) {
            cout << matrix.crr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    MaTrix arr;
    arr.inputArray1();
    arr.inputArray2();

    cout << "Tong 2 ma tran tren: " << endl; 
    Sum_Two_Matrix(arr);

    return 0;
}


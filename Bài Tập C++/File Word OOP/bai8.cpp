
/*
    Câu 8: Viết chương trình thực hiện các yêu cầu sau:
    1.	Khai báo lớp ma trận với các thuộc tính: số hàng, số cột, các phần tử của ma trận.
    2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
    3.	Nhập vào 1 ma trận. In ra màn hình ma trận vừa nhập. Tính tổng các phần tử nằm 
    trên 4 đường viền của ma trận.


*/

#include<bits/stdc++.h>
using namespace std;

class MaTrix {
    private:
        int m, n;
        int **arr; 

        void Dynamicaly() {
            arr = new int* [m];
            for(int i = 0; i < m; i++) {
                arr[i] = new int[n];
            }
        }   

    public:
        // MaTrix();
        // ~MaTrix();

    int getM() {
        return this->m;
    }

    int getN() {
        return this->n;
    }

    void inputArray();
    void outputArray();
    int TongPhanTu4VienNgoai();

};


void MaTrix::inputArray() {
    cout << "Nhap vao so hang: "; cin >> m;
    cout << "Nhap vao so cot: "; cin >> n;

    Dynamicaly();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "arr["<<i<<"]["<<j<<"] = ";
            cin >> arr[i][j];
        }
    }

}

void MaTrix::outputArray() {
    cout << "Ma Tran Vua Nhap: " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int MaTrix::TongPhanTu4VienNgoai() {
    int sum = 0;
    for(int i = 0; i < m; i++) { // Tính theo cột
        sum += arr[i][0] + arr[i][n-1];
    }
    for(int j = 1; j < n - 1; j++) { // tính theo hàng
        sum += arr[0][j] + arr[m-1][j];
    }
    return sum;
}


int main() {
    MaTrix arr;
    arr.inputArray();
    arr.outputArray();
    cout << "\nTONG PHAN TU TREN 4 DUONG VIEN: " << arr.TongPhanTu4VienNgoai() << endl;
    return 0;
}

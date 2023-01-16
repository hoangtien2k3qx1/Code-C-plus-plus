
/*
    Bài 7: : Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp ma trận vuông với các thuộc tính: cấp ma trận, các phần tử của ma trận.
        2.	Xây dựng các phương thức: nhập, xuất một đối tượng ma trận.
        3.	Nhập và 1 ma trận. In ra màn hình ma trận vừa nhập. Tính tổng các phần tử nằm trên 
        đường chéo chính, tổng các phần tử nằm trên đường chéo phụ của ma trận.

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
        // MaTrix(const MaTrix&);
        // ~MaTrix();


    int getM() {
        return this->m;
    }

    int getN() {
        return this->n;
    }

    void inputArray();
    void outputArray();

    int SumElementArray(); // Tổng phần tử trên đường chéo chính
    int SubElementArray(); // tổng phần tử trên đường chéo phụ

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

// Tổng phần tử trên đường chéo chính
int MaTrix::SumElementArray() {
    int sum = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) {
                sum += arr[i][j];
            }
        }
    }   
    return sum;
}


// Tổng phần tử trên đường chéo phụ
int MaTrix::SubElementArray() {
    int sum_n = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (j == n - i - 1) {
                sum_n += arr[i][j];
            }
        }
    }   
    return sum_n;
}


int main() {
    MaTrix arr;

    arr.inputArray();
    arr.outputArray();

    cout << "Tong phan tu tren duong cheo chinh: " << arr.SumElementArray() << endl;
    cout << "Tong phan tu tren duong cheo phu: " << arr.SubElementArray() << endl;

    return 0;
}



/*
    Để bài: 403. yêu cầu xoay ma trận 180 độ
        yêu cầu: có lớp, kế thừa, đa hình, chồng toán tử.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class MaTran {
public:
    int row, col;
    int **arr;

public:
    MaTran() {}
    MaTran(int row, int col) {
        this->row = row;
        this->col = col;
        arr = new int*[row];
        for(int i = 0; i < row; i++) {
            arr[i] = new int[col];
        }
    }
    virtual ~MaTran() {
        for(int i = 0; i < row; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};


class MaTran2 : public MaTran {
public:
    int **brr;

public:
    MaTran2(int row, int col) : MaTran(row, col){
        brr = new int*[this->row];
        for(int i = 0; i < this->row; i++) {
            brr[i] = new int[this->col];
        }
    }
    ~MaTran2() {
        for(int i = 0; i < this->row; i++) {
            delete[] brr[i];
        }
        delete[] brr;
    } 

    void Xoay_Ma_Tran_180(MaTran2&);
    friend istream& operator >> (istream&, MaTran2&);
    friend ostream& operator << (ostream&, MaTran2);

};

istream& operator >> (istream& input, MaTran2 &mt) {
    for(int i = 0; i < mt.row; i++) {
        for(int j = 0; j < mt.col; j++) {
            cout << "\tarr["<<i<<"]["<<j<<"] = ";
            input >> mt.arr[i][j];
            mt.brr[i][j] = mt.arr[i][j];
        }
    }
    return input;
}

ostream& operator << (ostream& output, MaTran2 mt) {
    for(int i = 0; i < mt.row; i++) {
        for(int j = 0; j < mt.col; j++) {
            cout << "\t" << mt.brr[i][j] << " ";
        }
        cout << endl;
    }
    return output;
}

void MaTran2::Xoay_Ma_Tran_180(MaTran2 &mt) {
    for(int i = mt.row - 1; i >= 0; i--) {
        for(int j = mt.col - 1; j >= 0; j--) {
            mt.brr[mt.row - 1 - i][mt.col - 1 - j] = mt.arr[i][j]; 
        }
    }  
}

int main() {
    system("cls");
    int row, col;
    cout << "Nhap vao co hang: "; cin >> row;
    cout << "Nhap vao so cot: "; cin >> col;

    MaTran2 mt = MaTran2(row, col);
    cout << "\n*Nhap Vao Cac Phan Tu Ma Tran: " << endl;
    cin >> mt;

    cout << "\n*Ma Tran Vua Nhap Vao: " << endl;
    cout << mt;

    mt.Xoay_Ma_Tran_180(mt);
    cout << "\n*Ma Tran Da Duoc Xoay 180: " << endl;
    cout << mt;
    
    cin.get();
    return 0;
}

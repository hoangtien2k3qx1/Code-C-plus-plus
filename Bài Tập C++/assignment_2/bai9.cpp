
/*
    Bài 9: Xây dựng lớp SoPhuc có các thuộc tính riêng PhanThuc, PhanAo kiểu double: 
        1: Xây dựng các toán tử tạo lập: 
        SoPhuc(), SoPhuc(float a, float b) 
        2: Xây dựng các phương thức: 
        - Nhập vào 1 số phức. 
        - HIển thị 1 số phức. 
        - Cộng 2 số phức. 
        - Nhân 2 số phức. 


*/

#include<bits/stdc++.h>
using namespace std;


class SoPhuc {
    private:
        double phanthuc;
        double phanao;
    
    public:
        SoPhuc() {
            phanthuc = 0;
            phanao = 0;
        }

        SoPhuc(double phanthuc, double phanao) {
            this->phanthuc = phanthuc;
            this->phanao = phanao;
        }

        friend istream& operator >> (istream&, SoPhuc&);
        friend ostream& operator << (ostream&, SoPhuc);

        SoPhuc operator+ (const SoPhuc);
        SoPhuc operator- (const SoPhuc);
        SoPhuc operator* (const SoPhuc);
        SoPhuc operator/ (const SoPhuc);

};


istream& operator >> (istream& input, SoPhuc &p) {
    cout << "Nhap vao phan thuc: "; input >> p.phanthuc;
    cout << "Nhap vao phan ao: "; input >> p.phanao;
    return input;
}

ostream& operator << (ostream& output, SoPhuc p) {
    output << p.phanthuc << " + " << p.phanao << "i" << endl;
    return output;
}


SoPhuc SoPhuc::operator+ (const SoPhuc res) {
    SoPhuc res1;
    res1.phanthuc = this->phanthuc + res.phanthuc;
    res1.phanao = this->phanao + res.phanao;
    return res1;
}

SoPhuc SoPhuc::operator- (const SoPhuc res) {
    SoPhuc ans;
    ans.phanthuc = this->phanthuc - res.phanthuc;
    ans.phanao = this->phanao - res.phanao;
    return ans;
}

SoPhuc SoPhuc::operator* (const SoPhuc C)
{
	SoPhuc C1;
	C1.phanthuc = this->phanthuc * C.phanthuc - this->phanao * C.phanao;
	C1.phanao = this->phanthuc * C.phanao + this->phanao * C.phanthuc;
	return C1;
}

SoPhuc SoPhuc::operator/ (const SoPhuc C)
{
	SoPhuc C1;
	C1.phanthuc = (this->phanthuc * C.phanthuc + this->phanao * C.phanao) / (pow(C.phanthuc, 2) + pow(C.phanao, 2));
	C1.phanao = (this->phanao * C.phanthuc - this->phanthuc * C.phanao) / (pow(C.phanthuc, 2) + pow(C.phanao, 2));
	return C1;
}


int main() {
    SoPhuc p1(0, 0), p2(0, 0);

    cout << "Nhap vao so phuc p1: \n";
    cin >> p1;
    cout << "Nhap vao so phuc p2: \n";
    cin >> p2;
    
    cout << "\n\tp1: " << p1 << endl << "\tp2: " << p2 << endl;

    // SoPhuc sum = p1 + p2;
    cout << "\tTong: p1 + p2 = " << p1 + p2;
    cout << "\tHieu: p1 - p2 = " << p1 - p2;
    cout << "\tTich: p1 * p2 = " << p1 * p2;
    cout << "\tThuong: p1 / p2 = " << p1 / p2 << endl;


    return 0;
}



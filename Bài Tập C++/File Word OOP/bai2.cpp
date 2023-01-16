
/*
    Bài 2: Viết chương trình thực hiện các yêu cầu sau:
        1.	Khai báo lớp đa thức với các thuộc tính: bậc đa thức, các hệ số tương ứng.
        2.	Xây dựng các phương thức: nhập, xuất một đối tượng đa thức.
        3.	Xây dựng phương thức cộng, trừ hai đa thức và in kết quả ra màn hình.

*/

#include<bits/stdc++.h>
using namespace std;

class DaThuc {
    private:
        int n; //bac cua da thuc
        int *a; //mang chua he so da thuc
    public:
        DaThuc(){
            n = 0;
            a = NULL;
        }
        DaThuc(int n1){
            n = n1; 
            a = new int [n];
        }
        ~DaThuc(){
            n = 0;
            delete a;
        }
        friend ostream& operator << (ostream&, DaThuc&);
        friend istream& operator >> (istream&, DaThuc&);
        DaThuc operator + (const DaThuc&);
        DaThuc operator - (const DaThuc&);

};

istream& operator >> (istream &is, DaThuc &d)
{
    cout<<"\nBac da thuc n = "; is >> d.n;
    d.a = new int[d.n + 1];
    cout<<"\nNhap cac he so cua da thuc: \n";
    for(int i = 0; i <= d.n; i++)
    {
        cout << "a["<<i<<"]= "; is >> d.a[i];
    }
    return is;
}

ostream& operator << (ostream &os, DaThuc &d)
{
    for(int i = 0; i <= d.n; i++)
    {
        os << d.a[i] << "x^"<< i; 
        if(i != d.n) 
            os << " + ";
    }
    return os;
}

DaThuc DaThuc::operator + (const DaThuc &d) {
    int Max = (n > d.n) ? n : d.n;
	int Min = (n < d.n) ? n : d.n;

    DaThuc sum(Max);

    for(int i = 0; i <= Min; i++) {
        sum.a[i] = a[i] + d.a[i];
    }
    for(int i = Min + 1; i <= Max; i++) {
        sum.a[i] = (n == Max) ? a[i] : d.a[i];
    }

    return sum;
}

DaThuc DaThuc::operator - (const DaThuc &d)
{
    int Max = (n > d.n) ? n : d.n;
	int Min = (n < d.n) ? n : d.n;

    DaThuc sub(Max);

    for(int i = 0; i <= Min; i++) {
        sub.a[i] = a[i] - d.a[i];
    }
    for(int i = Min + 1; i <= Max; i++) {
        sub.a[i] = (n == Max) ? a[i] : d.a[i];
    }

    return sub;
}

int main()
{

    DaThuc a,b;

    cout<<"\nNhap da thuc a: "; cin>>a;
    cout<<"\nNhap da thuc b: "; cin>>b;

    cout<<"\n\t  a: " << a;
    cout<<"\n\t  b: " << b;

    DaThuc sum = a + b; cout<<"\n\ta+b: "<< sum;
    DaThuc sub = a - b; cout<<"\n\ta-b: "<< sub;

    return 0;
} 


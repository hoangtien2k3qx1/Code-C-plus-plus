
/*
    Class : lớp
        attribute : thuộc tính
        method, behavior : phương thức
        object : đối tương

    - Encaptulation: tính đống gói

    - Access modifier: 
            + Private
            + Public
            + protected

*/

#include<bits/stdc++.h>
using namespace std;

class SinhVien {
    private:
        string id, name;
        int age;
    public:
        void nhap();
        void xuat();
        friend void inthongtin(SinhVien);
        friend void ChuanHoa(SinhVien &);
};


void ChuanHoa(SinhVien &a) {
    string res = "";
    stringstream ss(a.name);
    string token;
    while(ss >> token) {
        res += toupper(token[0]);
        for(int i=1; i<token.length(); ++i) {
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1); 
    a.name = res;
}

void inthongtin(SinhVien a) {
    cout << a.id << "\t" << a.name << "\t" << a.age << endl;
}

void SinhVien::nhap() {
    cout << "Nhap age: "; cin >> age;
    cin.ignore();
    cout << "Nhap id: "; getline(cin, id);
    cout << "Nhap name: "; getline(cin, name);
}

void SinhVien::xuat() {
    cout << id << "\t" << name << "\t" << age << endl;
}


int main() {
    SinhVien sv;

    sv.nhap();
    ChuanHoa(sv);
    inthongtin(sv);
    sv.xuat();

    return 0;
}











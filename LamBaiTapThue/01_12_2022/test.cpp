
#include<bits/stdc++.h>
using namespace std;

template<typename T, typename D, typename V>
class ThongTin {   // abstract class 
private:
    int m, n;

public:
    ThongTin<T, D, V>() {}
    ThongTin<T, D, V>(T m, T n) : m(m), n(n) {}
    virtual ~ThongTin<T, D, V>() {
        this->m = this->n = 0;
    }

    T& getM() { return this->m; }
    T& getN() { return this->n; }

    virtual bool check_So_Nguyen_To(T) = 0;
    virtual V So_Nguyen_To_Dau_Tien() = 0;
    virtual V print(T) = 0;         // Implements abstract lass 
    virtual V print_line(T) = 0;    // Implements abstract lass 
    
};

template<typename T, typename D, typename V>
class MaTrix : public ThongTin<T, D, V> {
private:
    T arr[100][100];
    // T **arr; 
    // V Dynamicaly() {
    //     arr = new T * [this->getM()];
    //     for(T i = 0; i < this->getM(); i++) {
    //         arr[i] = new T[this->getN()];
    //     }
    // }   

public:
    MaTrix<T, D, V>() {}
    ~MaTrix<T, D, V>() {
        // delete[] arr;
    }

    template<typename A, typename B, typename C> 
    friend istream& operator >> (istream&, MaTrix<A, B, C> &);
    template<typename A, typename B, typename C> 
    friend ostream& operator << (ostream&, MaTrix<A, B, C> ); 

    bool check_So_Nguyen_To(T);
    V So_Nguyen_To_Dau_Tien();
    V print(T);         // Implements interface
    V print_line(T);    // Implements interface

    bool operator < (const MaTrix &check) { return check.m < check.n; }

};

template<typename T, typename D, typename V>
V MaTrix<T, D, V>::print(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename T, typename D, typename V>
V MaTrix<T, D, V>::print_line(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << " KET QUA ";
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << endl;
}

template<typename T, typename D, typename V>
istream& operator >> (istream& input, MaTrix<T, D, V> &mt) {
    cout << "\t\t"; mt.print(33);
    cout << "\t\t<=> Nhap Vao Kich Thuoc Mang <=>" << endl;
    cout << "\t\t\t- Nhap So Hang: "; input >> mt.getM();
    cout << "\t\t\t- Nhap So Cot: "; input >> mt.getN();

    // Dynamicaly();

    cout << "\t\t"; mt.print(33);
    cout << "\t\t<=> Nhap Vao Cac Phan Tu Mang <=>" << endl;
    for(T i = 0; i < mt.getM(); i++) 
        for(T j = 0; j < mt.getN(); j++) {
            cout << "\t\t\t+ Array["<<i<<"]["<<j<<"] = ";
            input >> mt.arr[i][j];
        }
    cout << "\t\t"; mt.print(33); cout << endl;
    return input;
}

template<typename T, typename D, typename V>
ostream& operator << (ostream& output, MaTrix<T, D, V> mt) {
    cout << "\n\n\t\t"; mt.print_line(12);
    cout << "\t\t<=> MA TRAN 2 CHIEU VUA NHAP <=>" << endl;
    for(T i = 0; i < mt.getM(); i++) {
        for(T j = 0; j < mt.getN(); j++) {
            cout << "\t\t" << mt.arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\t\t"; mt.print(33); cout << endl;
    return output;
}

template<typename T, typename D, typename V>
bool MaTrix<T, D, V>::check_So_Nguyen_To(T a) {
    for(T i = 2; i <= sqrt(a); i++) 
        if (a % i == 0) 
           return false;
    return a > 1;
}

template<typename T, typename D, typename V>
V MaTrix<T, D, V>::So_Nguyen_To_Dau_Tien() {
    MaTrix<T, D, V> mt;
    cout << "\n\n\t\t"; mt.print_line(12);
    cout << "\t\t<=> SO NGUYEN TO DAU TIEN: ";
    bool check = true;
    for(T i = 0; i < this->getM(); i++) {
        for(T j = 0; j < this->getN(); j++) {
            if (this->check_So_Nguyen_To(this->arr[i][j]) && check == true) {
                cout << this->arr[i][j];
                check = false;
            }
        }
    }
    if (check) {
        cout << "Khong Co";
        cout << "\n\t\t"; mt.print(33); cout << endl << endl;
        return;
    }
    cout << "\n\t\t"; mt.print(33); cout << endl << endl;
}

int main() {
    system("cls");
    MaTrix<int, double, void> arr;
    cin >> arr; cout << arr;
    arr.So_Nguyen_To_Dau_Tien();
    cin.get();
    return 0;
}


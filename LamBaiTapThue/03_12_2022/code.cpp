/*
    Đề Bài: 
        Hãy liệt kê các vị trí chẵn lớn nhất trong mảng một chiều các số nguyên.

    Yêu câu: Code C++ hướng đối tượng.
*/

#include<bits/stdc++.h>
using namespace std;

class BassClass {
public:
	virtual void HienThongTin(){
		cout << "\t\t<=> NHAP VAO KICH THUOC CUA MANG MOT CHIEU:  ";
	}
};

template<typename T, typename V>
class ThongTin {
protected:
    T n;
public:
    ThongTin<T, V>() {}
    ThongTin<T, V>(T n) : n(n) {}
    ~ThongTin<T, V>() { n = 0; }
    T& getN() {return this->n; }

    V NhapThongTin() {
        cin >> n;
    }
    V XuatThongTin() {
        cout << "\n\t<=> MANG CAC PHAN TU VUA NHAP VAO <=> " << endl;
    }
    virtual V print(T) = 0;         // Polymophythms 
    virtual V print_line(T) = 0;    // Polymophythms 
};

template<typename T, typename V>
class Mang : public ThongTin<T, V> {
private:    
    T arr[100];
public:
    Mang<T, V>(int n) : ThongTin<T, V>(n) {}
    Mang<T, V>() {}
    // @overrding
    V NhapThongTin() {  
        ThongTin<T, V>::NhapThongTin();
        cout << "\n\t<=> Nhap Vao Phan Tu Mang <=> " << endl;
        for(T i = 0; i < Mang<T, V>::getN(); i++) {
            cout << "\t\tarr["<<i<<"] = "; cin >> Mang<T, V>::arr[i];
        }
    }
    // @overrding
    V XuatThongTin() {
        ThongTin<T, V>::XuatThongTin();
        cout << "\t\tArray[ ";
        for(T i = 0; i < Mang<T, V>::getN(); i++) 
            cout << Mang<T, V>::arr[i] << "  "; 
        cout << "]";
    }
    template<typename A, typename B> friend istream& operator >> (istream&, Mang<A, B> &);
    template<typename A, typename B> friend ostream& operator << (ostream&, Mang<A, B>);
    T number(Mang<T, V> m);
    V Xu_Ly_Thong_Tin(Mang<T, V> m);
    V print(T);         // Polymophythms 
    V print_line(T);    // Polymophythms 
};

template<typename T, typename V> V Mang<T, V>::print(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename V> V Mang<T, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename T, typename V> istream& operator >> (istream& input, Mang<T, V> &m) {
    m.NhapThongTin();
    return input;
}

template<typename T, typename V> ostream& operator << (ostream& output, Mang<T, V> m) {
    cout << "\n\n\t"; m.print_line(14);
    m.XuatThongTin();
    cout << "\n\t"; m.print(37); cout << endl << endl;
    return output;
}

const int IFN = 10000;
template<typename T, typename V> T Mang<T, V>::number(Mang<T, V> m) {
    T max = -IFN;
    for (T i = 0; i < m.n; i++)
        if (m.arr[i] > max && m.arr[i] % 2 == 0) max = m.arr[i];
    return max;
}

template<typename T, typename V> V Mang<T, V>::Xu_Ly_Thong_Tin(Mang<T, V> m) {
    cout << "\n\n\t"; m.print_line(14);
    T max = number(m);
    if (max == -IFN)
        cout << "Mang Khong Co Phan Tu Chan !!!";
    else {
        T b[100];
        for (T i = 0; i < m.n; i++)
            if (m.arr[i] == max) b[i] = 1;
            else b[i] = 0;
            cout << "\t\tResult[ ";
            for (T i = 0; i < m.n; i++) 
                if (b[i] == 1) cout << i + 1 << "  ";
            cout << "]";
    }
    cout << "\n\t"; m.print(37); cout << endl << endl;
}

class DriverClass : public BassClass {
public:
	void HienThongTin(){
		cout << "\t<=> NHAP VAO N PHAN TU CUA MANG:  ";
	}
};

int main() {
    system("cls");
    DriverClass ds;
    BassClass *p = &ds;  
    p->HienThongTin();
    Mang<int, void> arr;
    cin >> arr; 
    cout << arr;
    arr.Xu_Ly_Thong_Tin(arr);
    return 0;
}

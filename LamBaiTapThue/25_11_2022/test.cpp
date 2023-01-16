#include<bits/stdc++.h>
using namespace std;

template<typename T>
class ToaDo {
public:
    T x;
    T y;
};

template<typename T, typename F, typename D, typename V>
class ThongTin : public ToaDo<T> {
public:
    virtual V in_ToaDo(ToaDo<T>) = 0;
    virtual F tinhToaDo(ToaDo<T>, ToaDo<T>) = 0;
    V print(T);         // Polymophythms
    V print_line(T);    // Polymophythms
};

template<typename T, typename F, typename D, typename V>
class DaGiac : public ThongTin<T, F, D, V> {
private:
    ToaDo<T> toado;
    DaGiac<T, F, D, V> * next;

public:
    DaGiac<T, F, D, V>() {}
    virtual ~DaGiac<T, F, D, V>() {
        toado.x = toado.y = 0;
        next = NULL;
    }

    bool empty(DaGiac<T, F, D, V> *);
    T size(DaGiac<T, F, D, V> *);
    DaGiac<T, F, D, V> * makeNode_DaGiac();
    V addHead(DaGiac<T, F, D, V> *&);
    V addTail(DaGiac<T, F, D, V> *&);

    V in_ToaDo(ToaDo<T>);               // implements
    F tinhToaDo(ToaDo<T>, ToaDo<T>);    // implements

    V print(T);         // Implements abstract lass 
    V print_line(T);    // Implements abstract lass 

    V in_DanhSach_ToaDo(DaGiac<T, F, D, V> *);
    D TinhDienTichDaGiacLoi(DaGiac<T, F, D, V> *);
    D TinhChuViDaGiacLoi(DaGiac<T, F, D, V> *);

};

template<typename T, typename F, typename D, typename V>
V DaGiac<T, F, D, V>::print(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename T, typename F, typename D, typename V>
V DaGiac<T, F, D, V>::print_line(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << " KET QUA ";
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << endl;
}


template<typename T, typename F, typename D, typename V>
bool DaGiac<T, F, D, V>::empty(DaGiac<T, F, D, V> *dagiac) {
    return dagiac == NULL;
}

template<typename T, typename F, typename D, typename V>
T DaGiac<T, F, D, V>::size(DaGiac<T, F, D, V> *dagiac) {
    T count = 0;
    while(dagiac != NULL) {
        ++count;
        dagiac = dagiac->next;
    }
    return count;
}

template<typename T, typename F, typename D, typename V>
DaGiac<T, F, D, V> * DaGiac<T, F, D, V>::makeNode_DaGiac() {
    ToaDo<T> s;
    DaGiac<T, F, D, V> std;
    cout << "\n\n\t\t\t"; std.print(52);

    cout << "\n\t\t\t\t+ Nhap Toa Do X: "; cin >> s.x;
    cout << "\t\t\t\t+ Nhap Toa Do Y: "; cin >> s.y;

    DaGiac<T, F, D, V> * temp = new DaGiac<T, F, D, V>();
    temp->toado = s;
    temp->next = NULL;

    cout << "\t\t\t"; std.print(52);
    cout << endl << endl;
    return temp;
}

template<typename T, typename F, typename D, typename V>
V DaGiac<T, F, D, V>::addHead(DaGiac<T, F, D, V> *&s) {
    DaGiac<T, F, D, V> * temp = makeNode_DaGiac();
    if (s == NULL) {
        s = temp;
    } else {
        temp->next = s;
        s = temp;
    }
}

template<typename T, typename F, typename D, typename V>
V DaGiac<T, F, D, V>::addTail(DaGiac<T, F, D, V> *&s) {
    DaGiac<T, F, D, V> *temp = makeNode_DaGiac();
    if (s == NULL){
        s = temp;
    } else {
        DaGiac<T, F, D, V> *p = s;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

template<typename T, typename F, typename D, typename V>
V DaGiac<T, F, D, V>::in_ToaDo(ToaDo<T> td) {
    DaGiac<T, F, D, V> in;
    cout << "\t\t\t\t\t+ Toa Do X: " << td.x << endl;
    cout << "\t\t\t\t\t+ Toa Do Y: " << td.y << endl;
    cout << "\t\t\t\t"; in.print(28);
    cout << endl;
}

template<typename T, typename F, typename D, typename V>
V DaGiac<T, F, D, V>::in_DanhSach_ToaDo(DaGiac<T, F, D, V> *s) {
    cout << endl << endl;
    cout << "\t\t\t"; s->print_line(22); 
    cout << "\t\t\t  ==> THONG TIN CAC TOA DO VUA NHAP VAO DSLK <==" << endl << endl;
    int i = 1;
    while (s != NULL) {
        cout << "\t\t\t\t-> Thong Tin Toa Do So " << i++ << " <-" << endl;
        s->in_ToaDo(s->toado);
        s = s->next;
    }
    cout << "\t\t\t"; s->print(52);
    cout << endl;
}

template<typename T, typename F, typename D, typename V>
F DaGiac<T, F, D, V>::tinhToaDo(ToaDo<T> toado1, ToaDo<T> toado2) {
    return (F)sqrt(pow(toado2.x - toado1.x, 2) + pow(toado2.y - toado1.y, 2));  
}

template<typename T, typename F, typename D, typename V>
D DaGiac<T, F, D, V>::TinhChuViDaGiacLoi(DaGiac<T, F, D, V> *s) {
    DaGiac<T, F, D, V> * p = s;
    p = p->next;
    return 5 * (s->tinhToaDo(s->toado, p->toado));
}

template<typename T, typename F, typename D, typename V>
D DaGiac<T, F, D, V>::TinhDienTichDaGiacLoi(DaGiac<T, F, D, V> *s) {
    D P = s->TinhChuViDaGiacLoi(s);
    return (5 * pow(P, 2)) / (4 * tan(36));
}

int main() {
    system("cls");
    DaGiac<int, float, double, void> * head = NULL;

    while(true) {
        cout << endl << endl;
        cout << "\t\t\t****************************************************" << endl;
        cout << "\t\t\t**  __________________ MENU ____________________  **" << endl;
        cout << "\t\t\t**   1. Nhap Toa Do Dinh Vao DSLK Don.            **" << endl;
        cout << "\t\t\t**   2. In Danh Sach Cac Toa Do Vua Nhap.         **" << endl;
        cout << "\t\t\t**   3. Tinh Chu Vi Da Giac Loi.                  **" << endl;
        cout << "\t\t\t**   4. Tinh Dien Tich Da Giac Loi.               **" << endl;
        cout << "\t\t\t**   0. Ket Thuc Chuong Trinh.                    **" << endl;
        cout << "\t\t\t**  ____________________________________________  **" << endl;
        cout << "\t\t\t****************************************************" << endl;

        // cout << "______________________________________________________" << endl;
        cout << "\t\t\t"; head->print(52);
        cout << "\t\t\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;

        switch(lc) {
            case 1:
                head->addTail(head);
                break;
            case 2:
                head->in_DanhSach_ToaDo(head);
                break;
            case 3:
                cout << "\n\n\t\t\t"; head->print_line(22);
                cout << "\n\t\t\t\t=> Chu Vi Da Giac: " << head->TinhChuViDaGiacLoi(head) << endl;
                cout << "\t\t\t"; head->print(52); cout << endl << endl;
                break;
            case 4:
                cout << "\n\n\t\t\t"; head->print_line(22);
                cout << "\n\t\t\t\t=> Dien Tich Da Giac: " << head->TinhDienTichDaGiacLoi(head) << endl;
                cout << "\t\t\t"; head->print(52); cout << endl << endl;
                break;
            default:
                cout << "\n\n\t\t\t\t\tKET THUC CHUONG TRINH" << endl << endl << endl;
                return 0;
        }

        // char c;
        // do {
        //     cout << "\nChon (Y/y - N/n) de tiep tuc: "; cin >> c;
        //     if (c == 'N' || c == 'n') {
        //         cout << "\tKET THUC CHUONG TRINH" << endl;
        //         return 0;
        //     }
        // } while(c == 'N' || c == 'n');

    }

    cin.get();
    return 0;
}
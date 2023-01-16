
#include<bits/stdc++.h>
using namespace std;

template<typename T, typename S, typename D>
class ThongTin {
public:
    S maMatHang;
    S tenMatHang;
    S donViTinh;
    D donGia;
    T soLuongTon;
};

template<typename T, typename S, typename D, typename V>
class SuaHop {
private:
    ThongTin<T, S, D> toado;
    SuaHop<T, S, D, V> * next;

public:
    SuaHop<T, S, D, V>() {}
    virtual ~SuaHop<T, S, D, V>() {}

    bool empty(SuaHop<T, S, D, V> *);
    T size(SuaHop<T, S, D, V> *);
    SuaHop<T, S, D, V> * makeNode_DaGiac();
    V addHead(SuaHop<T, S, D, V> *&);
    V addTail(SuaHop<T, S, D, V> *&);

    V in_ToaDo(ThongTin<T, S, D>);               // implements
    V print(T);         // Implements abstract lass 
    V print_line(T);    // Implements abstract lass 

    V in_DanhSach_ToaDo(SuaHop<T, S, D, V> *);
    bool operator < (SuaHop<T, S, D, V> *p) {
        return this->toado.donGia < p->toado.donGia;
    }
    SuaHop<T, S, D, V> * Sap_Xep_Theo_Don_Gia_Tang_Dan(SuaHop<T, S, D, V> *);
};

template<typename T, typename S, typename D, typename V>
V SuaHop<T, S, D, V>::print(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename T, typename S, typename D, typename V>
V SuaHop<T, S, D, V>::print_line(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << " KET QUA ";
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << endl;
}

template<typename T, typename S, typename D, typename V>
bool SuaHop<T, S, D, V>::empty(SuaHop<T, S, D, V> *dagiac) {
    return dagiac == NULL;
}

template<typename T, typename S, typename D, typename V>
T SuaHop<T, S, D, V>::size(SuaHop<T, S, D, V> *dagiac) {
    T count = 0;
    while(dagiac != NULL) {
        ++count;
        dagiac = dagiac->next;
    }
    return count;
}

template<typename T, typename S, typename D, typename V>
SuaHop<T, S, D, V> * SuaHop<T, S, D, V>::makeNode_DaGiac() {
    ThongTin<T, S, D> s;
    SuaHop<T, S, D, V> std;
    cout << "\n\n\t\t\t"; std.print(52);

    cin.ignore();
    cout << "\n\t\t\t\t+ Nhap Ma Mat Hang: "; getline(cin, s.maMatHang);
    cout << "\t\t\t\t+ Nhap Ten Mat Hang: "; getline(cin, s.tenMatHang);
    cout << "\t\t\t\t+ Nhap Don Vi Tinh: "; getline(cin, s.donViTinh);
    cout << "\t\t\t\t+ Nhap Don Gia: "; cin >> s.donGia;
    cout << "\t\t\t\t+ Nhap So Luong Ton: "; cin >> s.soLuongTon;

    SuaHop<T, S, D, V> * temp = new SuaHop<T, S, D, V>();
    temp->toado = s;
    temp->next = NULL;

    cout << "\t\t\t"; std.print(52);
    cout << endl << endl;
    return temp;
}

template<typename T, typename S, typename D, typename V>
V SuaHop<T, S, D, V>::addHead(SuaHop<T, S, D, V> *&s) {
    SuaHop<T, S, D, V> * temp = makeNode_DaGiac();
    if (s == NULL) {
        s = temp;
    } else {
        temp->next = s;
        s = temp;
    }
}

template<typename T, typename S, typename D, typename V>
V SuaHop<T, S, D, V>::addTail(SuaHop<T, S, D, V> *&s) {
    SuaHop<T, S, D, V> *temp = makeNode_DaGiac();
    if (s == NULL){
        s = temp;
    } else {
        SuaHop<T, S, D, V> *p = s;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

template<typename T, typename S, typename D, typename V>
V SuaHop<T, S, D, V>::in_ToaDo(ThongTin<T, S, D> td) {
    SuaHop<T, S, D, V> in;
    cout << "\t\t\t\t\t+ Ma Mat Hang: " << td.maMatHang << endl;
    cout << "\t\t\t\t\t+ Ten Mat Hang: " << td.tenMatHang << endl;
    cout << "\t\t\t\t\t+ Don Vi Tinh: " << td.donViTinh << endl;
    cout << "\t\t\t\t\t+ Don Gia: " << td.donGia << endl;
    cout << "\t\t\t\t\t+ So Luong Ton: " << td.soLuongTon << endl;
    cout << "\t\t\t\t"; in.print(28);
    cout << endl;
}

template<typename T, typename S, typename D, typename V>
V SuaHop<T, S, D, V>::in_DanhSach_ToaDo(SuaHop<T, S, D, V> *s) {
    cout << endl << endl;
    cout << "\t\t\t"; s->print_line(22); 
    cout << "\t\t\t  ==> THONG TIN CAC SUA DONG HOP VUA NHAP VAO DSLK <==" << endl << endl;
    int i = 1;
    while (s != NULL) {
        cout << "\t\t\t\t-> Thong Tin Sua Dong Hop So " << i++ << " <-" << endl;
        s->in_ToaDo(s->toado);
        s = s->next;
    }
    cout << "\t\t\t"; s->print(52);
    cout << endl;
}

template<typename T, typename S, typename D, typename V>
SuaHop<T, S, D, V> * SuaHop<T, S, D, V>::Sap_Xep_Theo_Don_Gia_Tang_Dan(SuaHop<T, S, D, V> * check) {
    cout << endl << endl;
    cout << "\t\t\t"; check->print_line(22); 
    cout << "\t\t\t\tDa Sap Xep Tang Dan Theo Don Gia !" << endl;
    for(SuaHop<T, S, D, V> * p = check; p != NULL; p = p->next) {
        for(SuaHop<T, S, D, V> * q = p->next;  q != NULL; q = q->next) {
            if (p < q) {
                swap(p->toado.maMatHang, q->toado.maMatHang);
                swap(p->toado.tenMatHang, q->toado.tenMatHang);
                swap(p->toado.donViTinh, q->toado.donViTinh);
                swap(p->toado.donGia, q->toado.donGia);
                swap(p->toado.soLuongTon, q->toado.soLuongTon);
            }
        }
    }
    cout << "\t\t\t\t\t*Nhap 2 de xem thong tin !!!" << endl;
    cout << "\t\t\t"; check->print(52);
    cout << endl;
    return check;
}

int main() {
    system("cls");
    SuaHop<int, string, double, void> * head = NULL;

    while(true) {
        cout << endl << endl;
        cout << "\t\t\t****************************************************" << endl;
        cout << "\t\t\t**  __________________ MENU ____________________  **" << endl;
        cout << "\t\t\t**    1. Nhap Thong Tin Sua Hop Vao DSLK Don.     **" << endl;
        cout << "\t\t\t**    2. In Danh Sach Cac Sua Hop Vua Nhap.       **" << endl;
        cout << "\t\t\t**    3. Sap Xep Tang Dan Theo Don Gia Sua Hop.   **" << endl;
        cout << "\t\t\t**    0. Ket Thuc Chuong Trinh.                   **" << endl;
        cout << "\t\t\t**  ____________________________________________  **" << endl;
        cout << "\t\t\t****************************************************" << endl;

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
                head->Sap_Xep_Theo_Don_Gia_Tang_Dan(head);
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

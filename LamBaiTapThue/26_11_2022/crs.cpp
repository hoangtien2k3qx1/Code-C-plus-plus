/*
    Viết chương trình thực hiện yêu cầu sau:
        a. Khai báo cấu trúc dữ liệu của một danh sách liên kết đơn các tỉnh.
        Biết rằng thông tin của một tỉnh bao gồm: tên tỉnh(tối đa 30 ký tự), 
        diện tích (kiểu số thực), dân số(số nguyên dài).
        b. Cài đặt tất cả các thao tác cơ bản cho danh sách liên kết đơn các tỉnh.
        c. Tính tổng diện tích tấc cả các tỉnh trong danh sách liên kết.
        d. Tìm địa chỉ của node chứa tỉnh có diện tích lớn nhất trong danh sách.
        e. Tìm một tỉnh có diện tích lớn nhất trong danh sách liên kết đơn.
        f. Sắp xếp danh sách tăng dần theo diện tích.

*/

#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

template<typename S, typename D, typename T> class Node {
public:
    S tenTinh;
    D dienTich;
    T danSo;
};

template<typename S, typename D, typename T, typename V>
class ThongTin : public Node<S, D, T> {
public:
    // Node<S, D, T> node;
    ThongTin<S, D, T, V>() : Node<S, D, T>() {};
    ~ThongTin<S, D, T, V>() {}
    V print(T);         // Overriding
    V print_line(T);    // Overriding
};

template<typename S, typename D, typename T, typename V>
class DanhSach_Tinh : public ThongTin<S, D, T, V> {
private:
    Node<S, D, T> node;
    DanhSach_Tinh<S, D, T, V> * next;

public:
    DanhSach_Tinh<S, D, T, V>() {}
    virtual ~DanhSach_Tinh<S, D, T, V>() {  
        node.tenTinh = "";
        node.dienTich = 0.0;
        node.danSo = 0;
        next = NULL;
    }

    bool empty(DanhSach_Tinh<S, D, T, V> *);
    T size(DanhSach_Tinh<S, D, T, V> *);

    V print(T);             // Overriding
    V print_line(T);        // Overriding

    DanhSach_Tinh<S, D, T, V> * makeNode();
    V addHead(DanhSach_Tinh<S, D, T, V> *&);
    V addTail(DanhSach_Tinh<S, D, T, V> *&);

    V In(Node<S, D, T>);
    V In_Thong_Tin(DanhSach_Tinh<S, D, T, V> *);
    D Tong_Dien_Tich_Cac_Tinh(DanhSach_Tinh<S, D, T, V> *);
    V Dia_Chi_Tinh_Dien_Tich_Lon_Nhat(DanhSach_Tinh<S, D, T, V> *);
    V Tinh_Dien_Tich_Lon_Nhat(DanhSach_Tinh<S, D, T, V> *);
    DanhSach_Tinh<S, D, T, V> * Sap_Xep_Dien_Tich_Tang_Dan(DanhSach_Tinh<S, D, T, V> *);

    V Xu_Ly_Thong_Tin(DanhSach_Tinh<S, D, T, V> *);

};

template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::print(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::print_line(T n) {
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << " KET QUA ";
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << endl;
}

template<typename S, typename D, typename T, typename V>
bool DanhSach_Tinh<S, D, T, V>::empty(DanhSach_Tinh<S, D, T, V> * check) {
    return check == NULL;
}

template<typename S, typename D, typename T, typename V>
T DanhSach_Tinh<S, D, T, V>::size(DanhSach_Tinh<S, D, T, V> * check) {
    T count = 0;
    while(check != NULL) {
        ++count;
        check = check->next;
    }
    return count;
}

template<typename S, typename D, typename T, typename V>
DanhSach_Tinh<S, D, T, V> * DanhSach_Tinh<S, D, T, V>::makeNode() {
    DanhSach_Tinh<S, D, T, V> * ddd;
    cout << endl << endl; cout << "\t\t"; ddd->print(50);

    Node<S, D, T> temp;
    static int index = 0;
    cout << "\n\t\t<=> NHAP(BO SUNG) VAO THONG TIN TINH THU " << index++ + 1 << " <=> " << endl;
    cout << "\t\t\t+ Nhap Ten Tinh: "; getline(cin, temp.tenTinh);
    cout << "\t\t\t+ Nhap Dien Tich: "; cin >> temp.dienTich;
    cout << "\t\t\t+ Nhap Dan So: "; cin >> temp.danSo;

    DanhSach_Tinh<S, D, T, V> * check = new DanhSach_Tinh<S, D, T, V>();
    check->node = temp;
    check->next = NULL;

    cout << "\t\t"; ddd->print(50);
    cout << endl;
    return check;
}

template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::addHead(DanhSach_Tinh<S, D, T, V> *& check) {
    DanhSach_Tinh<S, D, T, V> * temp = makeNode();
    if (check == NULL) {
        check = temp;
    } else {
        temp->next = check;
        check = temp;
    }
}

template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::addTail(DanhSach_Tinh<S, D, T, V> *& check) {
    DanhSach_Tinh<S, D, T, V> * temp = makeNode();
    if (check == NULL) {
        check = temp;
    } else {
        DanhSach_Tinh<S, D, T, V> * p = check;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::In(Node<S, D, T> std) {
    DanhSach_Tinh<S, D, T, V> * check;
    cout << "\t\t\t  + Ten Tinh: " << std.tenTinh << endl;
    cout << "\t\t\t  + Dien Tich: " << std.dienTich << endl;
    cout << "\t\t\t  + Dan So: " << std.danSo << endl;
    cout << "\t"; cout << "\t\t"; check->print(28);
}

template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::In_Thong_Tin(DanhSach_Tinh<S, D, T, V> * check) {
    cout << endl << endl; cout << "\t\t"; check->print_line(20);
    cout << "\n\t\t==> THONG TIN CAC TINH VUA NHAP VAO DSLK DON :) <==" << endl << endl;
    int i = 1;
    while (check != NULL) {
        cout << "\t\t\t*TAT CA THONG TIN TINH THU " << i++ << ": " << endl;
        check->In(check->node);
        check = check->next;
    }
    cout << "\t\t"; check->print(50);
    cout << endl;
}


template<typename S, typename D, typename T, typename V>
D DanhSach_Tinh<S, D, T, V>::Tong_Dien_Tich_Cac_Tinh(DanhSach_Tinh<S, D, T, V> * check) {
    D result = 0.0;
    DanhSach_Tinh<S, D, T, V> * p = check;
    while(p != NULL) {
        result += p->node.dienTich;
        p = p->next;
    }
    return result;
}


template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::Dia_Chi_Tinh_Dien_Tich_Lon_Nhat(DanhSach_Tinh<S, D, T, V> * check) {
    cout << endl << endl; cout << "\t\t"; check->print_line(20);
    cout << "\n\t\t\t*DIA CHI NODE CO DIEN TICH LON NHAT*" << endl;
    DanhSach_Tinh<S, D, T, V> * p = check;
    D ans = p->node.dienTich;
    T count = 1;
    while(p != NULL) {
        if (p->node.dienTich > ans) {
            ans = p->node.dienTich;
            count++;
        }
        p = p->next;
    }
    cout << "\n\t\t\t\tNode Thu: " << count << endl;
    cout << "\t\t"; check->print(50);
    cout << endl << endl;
}


template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::Tinh_Dien_Tich_Lon_Nhat(DanhSach_Tinh<S, D, T, V> * check) {
    DanhSach_Tinh<S, D, T, V> * temp = check;
    D ans = temp->node.dienTich;
    T index = 0, i = 0;
    for(DanhSach_Tinh<S, D, T, V> * p = check; p != NULL; p = p->next) {
        if(p->node.dienTich > ans) {
            ans = p->node.dienTich;
            index = i;
        }
        i++;
    }

    for(int k = 0; k < index; k++) {
        temp = temp->next;
    }

    cout << endl << endl; cout << "\t\t"; check->print_line(20);
    cout << "\n\t\t<=> THONG TIN TINH CO DIEN TICH LON NHAT <=> " << endl << endl;
    temp->In(temp->node); cout << "\t\t"; temp->print(50);
    cout << endl << endl;
}

template<typename S, typename D, typename T, typename V>
DanhSach_Tinh<S, D, T, V> * DanhSach_Tinh<S, D, T, V>::Sap_Xep_Dien_Tich_Tang_Dan(DanhSach_Tinh<S, D, T, V> * check) {
    for(DanhSach_Tinh<S, D, T, V> * p = check; p != NULL; p = p->next) {
        for(DanhSach_Tinh<S, D, T, V> * q = p->next; q != NULL; q = q->next) {
            if (p->node.dienTich > q->node.dienTich) {
                swap(p->node.dienTich, q->node.dienTich);
                swap(p->node.danSo, q->node.danSo);
                swap(p->node.tenTinh, q->node.tenTinh);
            }
        }
    }
    return check;
}

template<typename S, typename D, typename T, typename V>
V DanhSach_Tinh<S, D, T, V>::Xu_Ly_Thong_Tin(DanhSach_Tinh<S, D, T, V> * node) {
    while(true) {
        cout << endl << endl;
        cout << "\t\t**************************************************" << endl;
        cout << "\t\t**  __________________ MENU __________________  **" << endl;
        cout << "\t\t**     1. Nhap(Bo Sung) Thong Tin Cac Tinh.     **" << endl;
        cout << "\t\t**     2. In Danh Sach Cac Tinh Vua Nhap.       **" << endl;
        cout << "\t\t**     3. Tong Dien Tich Tat Ca Cac Tinh.       **" << endl;
        cout << "\t\t**     4. Dia Chi Node Dien Tich Lon Nhat.      **" << endl;
        cout << "\t\t**     5. Tinh Co Dien Tich Lon Nhat.           **" << endl;
        cout << "\t\t**     6. Sap Xep Dien Tich Tang Dan DSLK.      **" << endl;
        cout << "\t\t**     0. KET THUC CHUONG TRINH :))).           **" << endl;
        cout << "\t\t**  ___________________________________________ **" << endl;
        cout << "\t\t**************************************************" << endl;

        cout << "\t\t"; node->print(50); cout << "\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;

        switch(lc) {
            case 1:
                cin.ignore(); node->addTail(node); 
                break;
            case 2:
                node->In_Thong_Tin(node); break;
            case 3:
                cout << endl << endl; 
                cout << "\t\t"; node->print_line(20);
                cout << "\n\t\t\t=> TONG DIEN TICH CAC TINH:  ";
                cout << node->Tong_Dien_Tich_Cac_Tinh(node) << endl;
                cout << "\t\t"; node->print(50); cout << endl << endl;
                break;
            case 4: 
                node->Dia_Chi_Tinh_Dien_Tich_Lon_Nhat(node); 
                break;
            case 5:
                node->Tinh_Dien_Tich_Lon_Nhat(node); 
                break;
            case 6:
                cout << endl << endl; cout << "\t\t"; node->print_line(20);
                cout << "\n\t\t<=> DANH SACH DA DUOC SAP XEP TANG DAN THEO DIEN TICH <=> " << endl;
                cout << "\t\t\t<=> Nhap 2 De In Danh Sach Da Sap Xep <=> " << endl;
                node->Sap_Xep_Dien_Tich_Tang_Dan(node);
                cout << "\t\t"; node->print(50); cout << endl << endl; 
                break;
            default:
                cout << "\n\n\t\t\tKET THUC CHUONG TRINH" << endl << endl;
                return;
        }
    }
}

int main() {
    system("cls");
    DanhSach_Tinh<string, double, long long, void> * node = NULL;
    node->Xu_Ly_Thong_Tin(node);
    delete[] node;
    return 0;
}


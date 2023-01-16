/*
    Viết chương trình thực hiện các yêu cầu sau trên danh sách liên kết các học sinh:
    a. khai báo cấu trúc dữ liệu một danh sách liên kết đơn các học sinh. Biết rằng thông tin
    của một học sinh bao gồm: họ tên (30 ký tự), điểm toán, điểm văn và điểm trung bình
    (tất cả là số thực).
    b. Cài đặt tất cả các thao tác cơ bản cho danh sách liên kết các học sinh.
    c. Liệt kê các học sinh có điểm toán nhỏ hơn 5 trong danh sách.
    d. Đến số lượng học sinh có điểm toán và điểm văn lớn hơn 8 điểm trong danh sách.
    e. Viết hàm sắp xếp các học sinh giảm dần theo điểm trung bình.
*/

#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

template<typename S, typename F> // template (generic in C++/Java)
class Node {    // tạo Node (Khai báo dữ liệu)
public: // 
    S hoTen;    // string hoTen
    F diemToan; // float diemToan
    F diemVan;
    F diemTB;
};

template<typename S, typename F, typename T, typename V>    // interface
class ThongTin : public Node<S, F> { // class Thong Tin kế thừa class Node  
public: // khuoon hình( đóng gói)
    Node<S, F> node; // khai báo Node
    ThongTin<S, F, T, V>() : Node<S, F>() {}; // Initializer list (danh sách khởi tạo)
    ~ThongTin<S, F, T, V>() {}

    // abstract class 
    V print(T) {}   // overriding (đa hình)

    // interface: 
    virtual V print_line(T) {}  // pure virtual (hàm thuần ảo). 
    virtual V In(Node<S, F>){}  // pure virtual (hàm thuần ảo). 

};

template<typename S, typename F, typename T, typename V>
class HocSinh : public ThongTin<S, F, T, V> {   // Class kế thừa class thong tin
private:                            // khuôn hình (đóng gói). 
    Node<S, F> node;                // tạo node.
    HocSinh<S, F, T, V> * next;     // tạo con trỏ next trong danh sách liên kết

public:
    HocSinh<S, F, T, V>() {}     // constructor không tham số.
    virtual ~HocSinh<S, F, T, V>() {    // hàm hủy ảo
        this->node.hoTen = " ";
        this->node.diemToan = this->node.diemVan = this->node.diemTB = 0.0;
    }

    bool empty(HocSinh<S, F, T, V> *);  // kiểm tra danh sách rỗng
    T size(HocSinh<S, F, T, V> *);      // kích thước dánh sách
    HocSinh<S, F, T, V> * makeNode();   // tạo node cho sanh sách
    V addHead(HocSinh<S, F, T, V> *&);  // thêm phần tử vào đầu danh sách
    V addTail(HocSinh<S, F, T, V> *&);  // thêm phần tử vào cuối dánh sách

    V print(T);         // overriding class Thong Tin (đa hình)
    V print_line(T);    // overriding implements (đa hình).
    V In(Node<S, F>);   // overriding implements (đa hình).

    // operator (nạp chồng toán tử)
    bool operator < (HocSinh<S, F, T, V> *p) {
        return this->node.diemTB < p->node.diemTB;
    }

    V In_Thong_Tin(HocSinh<S, F, T, V> *);              // in ra thông tin trong danh sách.
    V HS_Diem_Toan_Nho_Hon_5(HocSinh<S, F, T, V> *);    // học sinh có điểm toán lớn hơn 5
    T So_Luong_HSDiem_Toan_Van_LonHon_8(HocSinh<S, F, T, V> *);     // số lượng học sinh có điểm văn và toán lớn hơn 8
    HocSinh<S, F, T, V> * Sap_Xep_HS_Giam_Dan_Theo_DTB(HocSinh<S, F, T, V> *);  // sắp xếp học sinh với điểm trung bình giảm dần

    V Xu_Ly_Thong_Tin(HocSinh<S, F, T, V> *);   // xử lý tất cả thông tin trong danh sách

};

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::print(T n) {
    cout << "\t\t";
    for(T i = 0; i < n; i++) 
        cout << "_"; 
    cout << endl;
}

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::print_line(T n) {
    cout << "\t\t";
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << " KET QUA ";
    for(T i = 0; i < n; i++) 
        cout << "_";
    cout << endl;
}

template<typename S, typename F, typename T, typename V>
bool HocSinh<S, F, T, V>::empty(HocSinh<S, F, T, V> * check) {
    return check == NULL;
}

template<typename S, typename F, typename T, typename V>
T HocSinh<S, F, T, V>::size(HocSinh<S, F, T, V> * check) {
    T count = 0;
    while(check != NULL) {
        ++count;
        check = check->next;
    }
    return count;
}

template<typename S, typename F, typename T, typename V>
HocSinh<S, F, T, V> * HocSinh<S, F, T, V>::makeNode() {
    Node<S, F> temp;
    HocSinh<S, F, T, V> ans;
    cout << endl << endl;
    ans.print(50);
    static int index = 0;
    cout << "\n\t\t<=> NHAP(BO SUNG) VAO THONG TIN HOC SINH THU " << index++ + 1 << " <=> " << endl;
    cout << "\t\t\t+ Nhap Ho Ten: "; getline(cin, temp.hoTen);
    cout << "\t\t\t+ Nhap Diem Toan: "; cin >> temp.diemToan;
    cout << "\t\t\t+ Nhap Diem Van: "; cin >> temp.diemVan;
    cout << "\t\t\t+ Nhap Diem TB: "; cin >> temp.diemTB;

    HocSinh<S, F, T, V> * check = new HocSinh<S, F, T, V>();
    check->node = temp;
    check->next = NULL;

    ans.print(50);
    cout << endl;

    return check;
}

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::addHead(HocSinh<S, F, T, V> *& check) {
    HocSinh<S, F, T, V> * temp = makeNode();
    if (check == NULL) {
        check = temp;
    } else {
        temp->next = check;
        check = temp;
    }
}

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::addTail(HocSinh<S, F, T, V> *& check) {
    HocSinh<S, F, T, V> * temp = makeNode();
    if (check == NULL) {
        check = temp;
    } else {
        HocSinh<S, F, T, V> * p = check;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::In(Node<S, F> std) {
    HocSinh<S, F, T, V> * check;
    cout << "\t\t\t\t+ Ho Ten: " << std.hoTen << endl;
    cout << "\t\t\t\t+ Diem Toan: " << std.diemToan << endl;
    cout << "\t\t\t\t+ Diem Van: " << std.diemVan << endl;
    cout << "\t\t\t\t+ Diem TB: " << std.diemTB << endl;
    cout << "\t"; check->print(32);
}

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::In_Thong_Tin(HocSinh<S, F, T, V> * check) {
    cout << endl << endl;
    check->print_line(21); // ket qua.
    cout << "\n\t\t==> THONG TIN CAC TINH VUA NHAP VAO DSLK DON :) <==" << endl << endl;
    int i = 1;
    while (check != NULL) {
        cout << "\t\t\t*TAT CA THONG TIN HOC SINH THU " << i++ << ": " << endl;
        check->In(check->node);
        check = check->next;
    }
    check->print(50);
    cout << endl;
} 

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::HS_Diem_Toan_Nho_Hon_5(HocSinh<S, F, T, V> * check) {
    cout << endl << endl; 
    check->print_line(20);
    cout << "\n\t\t<=> DANH SACH HOC SINH CO DIEM TOAN NHO HON 5 <=> " << endl;
    HocSinh<S, F, T, V> * p = check;
    static T index = 1;
    bool checkResult = false;
    while(p != NULL) {
        if (p->node.diemToan < 5) {
            cout << "\t\t\t*THONG TIN HOC SINH THU " << index++ << ": " << endl;
            p->In(p->node);
            checkResult = true;
        }
        p = p->next;
    }
    if (checkResult == false) {
        cout << "\n\t\t\tKHONG CO HOC SINH NAO DIEM TOAN DUOI 5" << endl;
    }
    check->print(50); 
    cout << endl << endl;
}

template<typename S, typename F, typename T, typename V>
T HocSinh<S, F, T, V>::So_Luong_HSDiem_Toan_Van_LonHon_8(HocSinh<S, F, T, V> * check) {
    T count = 0;
    for(HocSinh<S, F, T, V> * p = check; p != NULL; p = p->next) 
        if (p->node.diemToan > 8 || p->node.diemVan > 8) 
            count++;
    return count;
}

template<typename S, typename F, typename T, typename V>
HocSinh<S, F, T, V> * HocSinh<S, F, T, V>::Sap_Xep_HS_Giam_Dan_Theo_DTB(HocSinh<S, F, T, V> * check) {
    for(HocSinh<S, F, T, V> * p = check; p != NULL; p = p->next) {
        for(HocSinh<S, F, T, V> * q = p->next;  q != NULL; q = q->next) {
            if (p < q) {
                swap(p->node.diemTB, q->node.diemTB);
                swap(p->node.diemToan, q->node.diemToan);
                swap(p->node.diemVan, q->node.diemVan);
                swap(p->node.hoTen, q->node.hoTen);
            }
        }
    }
    return check;
}

template<typename S, typename F, typename T, typename V>
V HocSinh<S, F, T, V>::Xu_Ly_Thong_Tin(HocSinh<S, F, T, V> * node) {
    while(true) {
        cout << endl << endl;
        cout << "\t\t**************************************************" << endl;
        cout << "\t\t**  __________________ MENU __________________  **" << endl;
        cout << "\t\t**  1. Nhap(Them) Thong Tin Cac Hoc Sinh.       **" << endl;
        cout << "\t\t**  2. In Danh Sach Cac Hoc Sinh Vua Nhap.      **" << endl;
        cout << "\t\t**  3. Danh Sach Hoc Sinh Co Diem Nho Hon 5.    **" << endl;
        cout << "\t\t**  4. So Luong HS Diem Toan Va Van Lon Hon 8.  **" << endl;
        cout << "\t\t**  5. Sap Xep Hoc Sinh Giam Dan Theo Diem TB.  **" << endl;
        cout << "\t\t**  0. KET THUC CHUONG TRINH :))).              **" << endl;
        cout << "\t\t**  ___________________________________________ **" << endl;
        cout << "\t\t**************************************************" << endl;

        node->print(50);
        cout << "\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;

        switch(lc) {
            case 1:
                cin.ignore(); node->addTail(node); 
                break;
            case 2:
                node->In_Thong_Tin(node); break;
            case 3:
                node->HS_Diem_Toan_Nho_Hon_5(node);
                break;
            case 4:
                cout << endl << endl; node->print_line(20);
                cout << "\n\t\t=> TONG SO LUONG HS DIEM TOAN VA VAN LON HON 8:  " << endl;
                cout << "\t\t\t*Tong So: " << node->So_Luong_HSDiem_Toan_Van_LonHon_8(node) << endl;
                node->print(50); cout << endl << endl;
                break;
            case 5:
                cout << endl << endl; node->print_line(20);
                cout << "\n\t\t=> SAP XEP GIAM DAN THEO DIEM TRUNG BINH <=" << endl;
                cout << "\n\t\t*Nhan phim 2 de xem thong tin da sap xep" << endl;
                node->Sap_Xep_HS_Giam_Dan_Theo_DTB(node);        
                node->print(50); cout << endl << endl;
                break;
            default:
                cout << "\n\n\t\t\tKET THUC CHUONG TRINH" << endl << endl;
                return;
        }
    }
}

int main() {
    system("cls");
    HocSinh<string, float, int, void> * node = NULL;
    node->Xu_Ly_Thong_Tin(node);
    delete node;
    return 0;
}


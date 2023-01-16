/*
    Viết chương trình thực hiện các yêu cầu sau:
    a. Nhập mảng 1 chiều các thí sinh (THISINH). Biết rằng một thí sinh gồm những thành phần sau:
        - Mã thí sinh: chuỗi tối đa 5 ký tự.
        - Họ tên thí sinh: chuỗi tối đa 30 ký tự.
        - Điểm toán: kiểu số thực.
        - Điểm lý: kiểu số thực.
        - Điểm hóa: kiểu số thực.
        - Điểm tổng cộng: kiểu số thực.
    b. Xuất mảng.
    c. Liệt kê các thí sinh thi đậu trong mảng. Một thí sinh được gọi là đậu khi tổng điểm 3 môn
    lớn hơn 15 và không có môn nào được điểm 0.
    d. sắp xếp theo thứ tự giảm dần theo điểm tổng cộng.

*/
#include<bits/stdc++.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
#define max 100

template<typename D, typename V>
class DIEM {
protected:  // Encapsulation
    D diemToan;
    D diemLy;
    D diemHoa;
    D diemTongCong;
public:
    DIEM<D, V>() {
        diemToan = diemLy = diemHoa = diemTongCong = 0.0;   // Constructor no parameter
    }
    DIEM<D, V>(D diemToan, D diemLy, D diemHoa) {           // Constructor parameter
        this->diemToan = diemToan;
        this->diemLy = diemLy;
        this->diemHoa = diemHoa;
    }
    virtual ~DIEM<D, V>() {}                                // pure virtual 

    V NhapThonTin() {   // @overriding
        cout << "\t\t\t\t+ Nhap Diem Toan: "; cin >> diemToan;
        cout << "\t\t\t\t+ Nhap Diem Ly: "; cin >> diemLy;
        cout << "\t\t\t\t+ Nhap Diem Hoa: "; cin >> diemHoa;
        this->diemTongCong = (diemToan + diemLy + diemHoa);
    }

    V XuatThongTin() {  // @overriding
        cout << "\t\t\t\t+ Diem Toan: " << diemToan << endl;
        cout << "\t\t\t\t+ Diem Ly: " << diemLy << endl;
        cout << "\t\t\t\t+ Diem Hoa: " << diemHoa << endl;
        cout << "\t\t\t\t+ Diem Tong Cong: " << diemTongCong << endl;
    }

    D& getDiemToan() { return this->diemToan; }
    D& getDiemLy() { return this->diemLy; }
    D& getDiemHoa() { return this->diemHoa; }
    D& getDiemTongCong() { return this->diemTongCong; }
};

template<typename Ch, typename D, typename T, typename V>
class THISINH : public DIEM<D, V> {  // inheritance
private:                                // Encapsulation
    Ch maTS[5];
    Ch tenTS[30];
public:
    THISINH<Ch, D, T, V>() {} // constructor no parameter
    THISINH<Ch, D, T, V>(Ch maTS, Ch tenTS, D diemToan, D diemLy, D diemHoa)   // Initializer list OOP
    : DIEM<D, V>(diemToan, diemLy, diemHoa), maTS(maTS), tenTS(tenTS) {}
    virtual ~THISINH<Ch, D, T, V>() {}

    Ch& getMaTS() { return this->maTS; }
    Ch& getTenTS() { return this->tenTS; }

    // @overriding  // Polymorphims
    V NhapThonTin() {
        cout << "\t\t\t\t+ Nhap Ma Thi Sinh: "; cin.getline(maTS, 20);
        T count = 0; while(maTS[count] != '\0') count++;
        if (count > 5) {
           do {
                cout << "\t\t\t\t+ Nhap Lai Ma Thi Sinh (5 ky tu): "; cin.getline(maTS, 20);
                count = 0;
                while(maTS[count] != '\0') count++;
            } while(count > 5); 
        }
        cout << "\t\t\t\t+ Nhap Ten Thi Sinh: "; cin.getline(tenTS, 30);
        DIEM<D, V>::NhapThonTin(); 
    }

    // @overriding  // Polymorphims
    V XuatThongTin() {
        cout << "\t\t\t\t+ Ma Thi Sinh: " << maTS << endl;
        cout << "\t\t\t\t+ Ten Thi Sinh: " << tenTS << endl;
        DIEM<D, V>::XuatThongTin();
    }

    //  operator input //  operator output
    template<typename A, typename B, typename C, typename E> friend istream& operator >> (istream&, THISINH<A, B, C, E>&);
    template<typename A, typename B, typename C, typename E> friend ostream& operator << (ostream&, THISINH<A, B, C, E>);

    bool operator < (THISINH<Ch, D, T, V> ts) { 
        return this->getDiemTongCong() < ts.getDiemTongCong();
    }

    V Thi_Sinh_Thi_Dau(THISINH<Ch, D, T, V> *, T);
    THISINH<Ch, D, T, V> * Sap_Xep_Giam_Dan_Theo_DiemTongCong(THISINH<Ch, D, T, V> *, T);
    V print(T);         // Implements abstract lass ThongTin
    V print_line(T);    // Implements abstract lass ThongTin
    static V Xu_Ly_Thong_Tin();
};

template<typename Ch, typename D, typename T, typename V> V THISINH<Ch, D, T, V>::print(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename Ch, typename D, typename T, typename V> V THISINH<Ch, D, T, V>::print_line(T n) {
    for(T i = 0; i < n; i++) cout << "_"; cout << " KET QUA ";
    for(T i = 0; i < n; i++) cout << "_"; cout << endl;
}

template<typename Ch, typename D, typename T, typename V> istream& operator >> (istream& input, THISINH<Ch, D, T, V> &lv) {
    lv.NhapThonTin();
    return input;
}

// Convert Integer to String in OOP
template<typename Ch, typename D, typename T, typename V> ostream& operator << (ostream& output, THISINH<Ch, D, T, V> lv) {
    lv.XuatThongTin();
    return output;
}

template<typename Ch, typename D, typename T, typename V>
V THISINH<Ch, D, T, V>::Thi_Sinh_Thi_Dau(THISINH<Ch, D, T, V> * arr, T n) {
    cout << endl << endl; cout << "\t\t"; arr->print_line(21); // ket qua.
    for(T i = 0; i < n; i++) 
        if (arr[i].getDiemTongCong() >= 15) 
            if (arr[i].getDiemToan() > 0 && arr[i].getDiemLy() > 0 && arr[i].getDiemHoa() > 0) {
                cout << "\n\t\t<=> Thong Tin Cua Thi Sinh Thu " << i + 1 << " Trong Danh Sach <=>" << endl;
                cout << arr[i];
                cout << "\t\t\t"; arr->print(35);
            }
    cout << "\t\t"; arr->print(52); cout << endl;
}

template<typename Ch, typename D, typename T, typename V>
THISINH<Ch, D, T, V> * THISINH<Ch, D, T, V>::Sap_Xep_Giam_Dan_Theo_DiemTongCong(THISINH<Ch, D, T, V> * arr, T n) {
    cout << endl << endl; cout << "\t\t";
    arr->print_line(21); // ket qua.
    cout << "\t\t<=> Da Sap Xep Theo Diem Tong Cong GiaM Dan: " << endl;
    cout << "\t\t\t<=> Nhan 2 de xem thong tin <=>" << endl;
    for(T i = 0; i < n - 1; i++) {
        for(T j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "\t\t"; arr->print(52); cout << endl;
    return arr;
}

template<typename Ch, typename D, typename T, typename V> V THISINH<Ch, D, T, V>::Xu_Ly_Thong_Tin() {
    THISINH<Ch, D, T, V> * arr = new THISINH<Ch, D, T, V>[max];
    while(true) {
        cout << endl << endl << endl;
        cout << "\t\t +++++++_^_^____________ MENU ________^_^__++++++++ " << endl;
        cout << "\t\t|     1. Nhap Vao Thong Tin Cac Thi Sinh.          |" << endl;
        cout << "\t\t|     2. In Danh Sach Thong Tin Cac Thi Sinh.      |" << endl;
        cout << "\t\t|     3. Thong Tin Cac Thi Sinh Thi Dau .          |" << endl;
        cout << "\t\t|     4. Sap Xep Giam Dan Theo Diem Tong Cong.     |" << endl;
        cout << "\t\t|     0. Ket Thuc Chuong Trinh.                    |" << endl;
        cout << "\t\t|++++++++++++++++++++++++++++++++++++++++++++++++++|" << endl;
        cout << "\t\t---> Nhap Lua Chon --->:  ";
        int lc; cin >> lc;
        switch(lc) {
            case 1:
                int n; cout << "\n\t\t\t<=> NHAP VAO N THI SINH: "; cin >> n;
                cout << endl << endl;
                cout << "\t\t"; arr->print(52);
                for(T i = 0; i < n; i++) {
                    cin.ignore();
                    cout << "\n\t\t\t<=> Nhap Vao Thong Tin Thi Sinh " << i + 1 << " <=>" << endl;
                    cin >> arr[i];
                    cout << "\t\t\t"; arr->print(39);
                }
                cout << "\t\t"; arr->print(52);
                cout << endl;
                break;
            case 2:
                cout << endl << endl; cout << "\t\t";
                arr->print_line(21); 
                for(T i = 0; i < n; i++) {
                    cout << "\n\t\t<=> Thong Tin Cua Thi Sinh Thu " << i + 1 << " Trong Danh Sach <=>" << endl;
                    cout << arr[i];
                    cout << "\t\t\t"; arr->print(35);
                }
                cout << "\t\t"; arr->print(52);
                cout << endl;
                break;
            case 3:
                arr->Thi_Sinh_Thi_Dau(arr, n);
                break;
            case 4: 
                arr->Sap_Xep_Giam_Dan_Theo_DiemTongCong(arr, n);
                break;
            case 0:
                cout << "\n\t\t\t!!! <KET THUC CHUONG TRINH> !!!" << endl;
                return;
        }
    }
    delete[] arr;
}

int main() {
    system("cls");
    THISINH<char, double, int, void>::Xu_Ly_Thong_Tin();
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "\t\t\t* Day-Month-Year: "<< ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    cout << endl << endl << endl;
    cin.get();
    return 0;
};





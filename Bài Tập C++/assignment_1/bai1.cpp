
//* Nhóm 11

//! Dùng C++ viết chương trình cho các yêu cầu sau:

/*
    Câu 1:
        a. viết chương trình nhập vào 1 xâu
        b. xuất xâu vừa nhập
        c. đảo ngược xâu
        d. cho biết chiều dài của chuỗi
        e. chuyển xâu thành chữ in hoa
        f. đếm số ký tự "X" xuất hiện trong xâu
        g. khai báo một xâu s2 kiểm tra xâu s2 có bằng xâu ban đầu hay không ?
        h. kiểm tra xâu có đối xứng không

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// a. viết chương trình nhập vào 1 xâu
void inputString(string &s) {
    cout << "Nhap vao xau: ";
    getline(cin, s);
}

// b. xuất xâu vừa nhập
void outputString(string s) {
    cout << "Xau vua nhap: ";
    cout << s << endl;
}

// c. đảo ngược xâu
string reverseString(string s) {
    int length = s.length();

    string val = "";
    for(int i = length - 1; i >= 0; i--) {
        val.push_back(s[i]); 
    }

    return val;
}

// d. cho biết chiều dài của chuỗi
int lengthString(string s) {
    return s.length();
}

// e. chuyển xâu thành chữ in hoa
string upperString(string s) {
    for(int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    }
    return s;
}

// f. đếm số ký tự "X" xuất hiện trong xâu
int CountElements(string s, char x) {
    int count = 0;

    int i = 0;
    while(s[i] != '\0') {
        if (s[i] == x) ++count;
        i++;
    }

    return count;
}


// g. khai báo một xâu s2 kiểm tra xâu s2 có bằng xâu ban đầu hay không ?
int checkTwoString(string s1, string s2) {
    if (s1 > s2) return 1;
    else if (s1 == s2) return 0;
    else return -1;
}


// h. kiểm tra xâu có đối xứng không
bool checkPalindrome(string s) {
    int length = s.length();
    for(int i = 0; i < length/2; i++) {
        if (s[i] != s[length - i - 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    string s;

    while(1) {
        cout << "\n____________Menu_____________\n";
        cout << "\n1. Viet chuong trinh nhap vao 1 xau";
        cout << "\n2. Xuat xau vua nhap";
        cout << "\n3. Dao nguoc xau do!!!";
        cout << "\n4. Cho biet chieu dai cua xau";
        cout << "\n5. Chuyen xau thanh chu in hoa";
        cout << "\n6. Dem so ky tu X xuat hien trong xau";
        cout << "\n7. Kiem tra xau s2 co bang xau ban dau khong";
        cout << "\n8. Kiem tra xau co doi xung khong";
        cout << "\n0. KET THUC !!!";
        cout << "\n______________________________\n";

        int lc; cout << "Nhap vao lua chon: "; cin >> lc;
        cin.ignore();
        if (lc == 1) {
            inputString(s);
        } else if (lc == 2) {
            outputString(s);
        } else if (lc == 3) {
            cout << "Chuoi dao nguoc: " << reverseString(s) << endl;
        } else if (lc == 4) {
            cout << "Chieu dai cua chuoi: " << lengthString(s) << endl;
        } else if (lc == 5) {
            cout << "Chuoi in hoa: " << upperString(s) << endl;
        } else if (lc == 6) {
            char x; cout << "Nhap vao ky tu X can xet: "; cin >> x;
            cout << "So ky tu X trong chuoi: " << CountElements(s, x) << endl;
        } else if (lc == 7) {
            string s2; cout << "Nhap vao chuoi s2: "; getline(cin, s2);
            int check = checkTwoString(s, s2);
            if (check == 1) 
                cout << "Chuoi s1 lon hon chuoi s2!";
            else if (!check)
                cout << "Hai chuoi bang nhau!!!";
            else 
                cout << "Chuoi s1 be hon chuoi s2!!!";
        } else if (lc == 8) {
            if (checkPalindrome(s)) {
                cout << "Chuoi doi xung nhau!!!" << endl;
            } else {
                cout << "Chuoi khong doi xung nhau!!!" << endl;
            }
        } else if (lc == 0) {
            break;
        }
    }

    return 0;
}

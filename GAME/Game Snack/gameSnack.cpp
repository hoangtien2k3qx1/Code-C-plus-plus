
// Game Snack Basic C++ OOP: hoangtien2k3

#include "kmin_console.cpp"
#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<ctime>
#include<math.h>
using namespace std;

#define MAX 100
#define LEN 1
#define XUONG 2
#define TRAI 3
#define PHAI 4
#define TUONG_TREN 5
#define TUONG_DUOI 22
#define TUONG_TRAI 5
#define TUONG_PHAI 100

class ToaDo {
    private:
        int x;
        int y;

    public:
        ToaDo() {}
        ToaDo(int x, int y) : x(x), y(y) {}
        ~ToaDo() {}

        void khoiTaoRan();
        void hienThiRan(ToaDo);
        ToaDo diChuyen(int);
        void batSuKien(int&);
        void veTuong();
        void xuLyThua(int);
        ToaDo hienThiMoi();
        bool kiemTraDaAnMoi(ToaDo);
        void themDot();
        bool kiemTraRanChamTuong();
        bool kiemTraRanCanVaoDuoi();

};


ToaDo ran[MAX];
int soDot = 4;


void ToaDo::khoiTaoRan() {
    ran[0].x = TUONG_TRAI + 42;
    ran[1].x = TUONG_TRAI + 41;
    ran[2].x = TUONG_TRAI + 40;
    ran[0].y = ran[1].y = ran[2].y = TUONG_TREN + 8;
}


void ToaDo::hienThiRan(ToaDo dotCuoiCu) {
    for(int i = 0; i < soDot; i++) {
        if (i != 0) {
            gotoXY(ran[i].x, ran[i].y);
            cout << "$";
        }
        gotoXY(ran[i].x, ran[i].y);
        cout << (char)232;
    }

    // int i = 1;
    // setTextColor(i);
    // i++;
    // if (i > 15)
    //     i = 1;

    gotoXY(dotCuoiCu.x, dotCuoiCu.y);
    cout << " ";
}


ToaDo ToaDo::diChuyen(int huong) {
    ToaDo dotCuoiCu = ran[soDot - 1];
    for(int i = soDot - 1; i >= 1; i--) {
        ran[i] = ran[i - 1];
    }

    switch(huong) {
        case LEN: ran[0].y--; break;
        case XUONG: ran[0].y++; break;
        case TRAI: ran[0].x--; break;
        case PHAI: ran[0].x++; break;
    }
    return dotCuoiCu;
}


void ToaDo::batSuKien(int &huong) {
    int key = inputKey();
    if (key == KEY_UP && huong != XUONG || key == 'w'|| key == 'W') {
        huong = LEN;
    } else if ((key == KEY_DOWN) && huong != LEN|| key == 's' || key == 'S') {
        huong = XUONG;
    } else if ((key == KEY_LEFT) && huong != PHAI || key == 'a' || key == 'A') {
        huong = TRAI;
    } else if ((key == KEY_RIGHT) && (huong != TRAI) || key == 'd' || key == 'D') {
        huong = PHAI;
    }
}


void ToaDo::veTuong() {
    for(int x = TUONG_TRAI; x <= TUONG_PHAI; x++) {
        gotoXY(x, TUONG_TREN);
        cout << (char)220;
    }
    for(int y = TUONG_TREN + 1; y <= TUONG_DUOI; y++) {
        gotoXY(TUONG_TRAI, y);
        cout << (char)221;
    }
    for(int x = TUONG_TRAI; x <= TUONG_PHAI; x++) {
        gotoXY(x, TUONG_DUOI);
        cout << (char)223;
    }
    for(int y = TUONG_TREN + 1; y <= TUONG_DUOI - 1; y++) {
        gotoXY(TUONG_PHAI, y);
        cout << (char)222;
    }
}


ToaDo ToaDo::hienThiMoi() {
    srand(time(NULL));
    int x = TUONG_TRAI + 1 + rand() % ((TUONG_PHAI-1) - (TUONG_TRAI+1) + 1);
    int y = TUONG_TREN + 1 + rand() % ((TUONG_DUOI-1) - (TUONG_TREN+1) + 1);
    gotoXY(x, y);
    cout << (char)3;
    // int i = 1;
    // setTextColor(i++);

    // C1
    // ToaDo temp;
    // temp.x = x;
    // temp.y = y;
    // return temp;

    // C2
    return ToaDo{x, y}; // C2 giống y hệt với cách 1, cách 2 thì nhanh hơn.
}


bool ToaDo::kiemTraDaAnMoi(ToaDo moi) {
    if (ran[0].x == moi.x && ran[0].y == moi.y)
        return true;
    else
        return  false;
}


void ToaDo::themDot() {
    ran[soDot] = ran[soDot - 1];
    soDot++;
}

void ToaDo::xuLyThua(int diem) {
    Sleep(1200);
    clrscr();
    gotoXY(TUONG_PHAI/2 - 7, 8);
    cout << "\tDIEM SO: " << diem << endl << endl << endl;
    setTextColor(4);

    cout << "\t    000000      00000    0       0   000000          00000     0        0    000000   00000"  << endl;
    cout << "\t   0           0     0   0 0   0 0   0             0       0    0      0     0        0    0" << endl;
    cout << "\t   0    000    0 000 0   0  0 0  0   000000        0       0     0    0      000000   0 000"  << endl;
    cout << "\t   0     0     0     0   0   0   0   0             0       0      0  0       0        0    0" << endl;
    cout << "\t    000000     0     0   0       0   000000          00000         00        000000   0    0" << endl;

}

bool ToaDo::kiemTraRanChamTuong() {
    for(int i = 0; i <= 100; i++) {
        if (ran[i].y == 5 && (ran[i].x >= 5 && ran[i].x <= 100)) {
            return true;
        } else if (ran[i].y == 22 && (ran[i].x >= 22 && ran[i].x <= 100)) {
            return true;
        } else if (ran[i].x == 5 && (ran[i].y >= 5 && ran[i].y <= 22)) {
            return true;
        } else if (ran[i].x == 100 && (ran[i].y >= 5 && ran[i].y <= 22)) {
            return true;
        }
    }
    return false;
}


bool ToaDo::kiemTraRanCanVaoDuoi() {
    for(int i = 1; i <= soDot; i++) {
        if ((ran[0].x == ran[i].x) && (ran[0].y == ran[i].y)) {
            return true;
        }
    }
    return false;
}


int main() {
    system("cls");

    ToaDo td;

    int diem = 0;
    bool checkGameOver1 = false;
    bool checkGameOver2 = false;

    td.khoiTaoRan();
    int x = 0, y = 0;
    int huong = PHAI;

    td.veTuong();
    gotoXY(TUONG_PHAI/2-7, 24);
    setTextColor(10);
    cout << "Coder: hoangtien2k3";
    ToaDo moi = td.hienThiMoi();

    gotoXY(TUONG_PHAI/2 - 3, 4);
    cout << "DIEM SO: " << diem;

    int i = 1;
    while(checkGameOver1 == false && checkGameOver2 == false)
    {
        ToaDo dotCuoiCu = td.diChuyen(huong);
        td.batSuKien(huong);
        td.hienThiRan(dotCuoiCu);

        setTextColor(i++);
        if (i > 15) {
            i = 1;
        }

        if (td.kiemTraDaAnMoi(moi) == true) {
            moi = td.hienThiMoi();
            td.themDot();
            diem++;
            gotoXY(TUONG_PHAI/2 - 3, 4);
            cout << "DIEM SO: " << diem;
        }

        checkGameOver1 = td.kiemTraRanChamTuong();
        checkGameOver2 = td.kiemTraRanCanVaoDuoi();

        Sleep(80);
    }
    td.xuLyThua(diem);

    _getch();
    cin.get();
    return 0;
}


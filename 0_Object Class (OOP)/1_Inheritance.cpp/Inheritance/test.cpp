

#include<bits/stdc++.h>
using namespace std;


class Vihicle {
private:
    int x, y;

public:
    Vihicle() {
        cout << "Let's go" << endl;
    };

    Vihicle(int x, int y) : x(x), y(y) {}
    ~Vihicle() {
        cout << "Ham huy Vihicle !" << endl;
    };

    void print() {
        cout << "Tien Dep Trai oke !!!" << endl;
    }

};


class Taxi : public Vihicle {
private:
    int a, b;

public:
    Taxi() { //! chỉ định gọi hàm này.
        Vihicle::print();
        cout << "Hoang Anh Tien !" << endl;
    }
    virtual ~Taxi() {
        cout << "Ham huy Taxi !" << endl;
    }


    void print() {
        Vihicle::print();
        cout << "Oke chua!!!" << endl;
    }


};



int main() {
    system("cls");

    Taxi *taxi = new Taxi();



    delete taxi;




    cin.get();
    return 0;
}
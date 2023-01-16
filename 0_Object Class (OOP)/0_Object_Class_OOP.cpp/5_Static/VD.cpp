
#include<bits/stdc++.h>
using namespace std;

class Static {
    public:
        static int a;
        
    public:
        Static() {}

        void in() {
            static int b = 10;
            b += 5;
            cout << b << endl;
        }


};

int Static::a = 10;


int main() {
    system("cls");

    Static s1;
    for(int i = 0; i < 5; i++) {
        // s1.a += 5;
        // cout << s1.a << endl;


        s1.in();
    }


    cin.get();
    return 0;
}
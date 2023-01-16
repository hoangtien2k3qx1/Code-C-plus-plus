
/*
    ! Returning multiple values from a C++ function:



*/

#include <tuple>
#include<bits/stdc++.h>
using namespace std;

tuple<int, int> divide(int dividend, int divisor) {
    return make_tuple(dividend, divisor);
}


int main() {
    system("cls");

    int quotient, remainder;

    tie(quotient, remainder) = divide(8, 4);

    cout << quotient << " - " << remainder << endl;

    cin.get();
}



/*
    Tìm cột có nhiều số Fibonasi nhất trong ma trận, trong trường hợp có nhiều cột có cùng số lượng
    Fibonacci thì in ra cột có tông số Fibonacci lớn nhất

    Ex:
        4 4 
        1 2 3 5
        2 2 5 8
        10 1 2 3
        21 13 3 3
    
    =< solution() = 4 
                    5 8 3 3 


*/

#include<bits/stdc++.h>

int Fibonacci(int n) {
    if (n == 0) return 0;
    else if(n == 1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}



int main() {
    int n;
    std::cin >> n;

    std::cout << Fibonacci(n) << " ";

    return 0;
}

/*
    ! 1. Template trong C++
        * Template (khuôn mẫu) là một kiểu dữ liệu trừu tượng tổng quát hóa 
        cho các kiểu dữ liệu int, float, double, bool...

        * - Template trong C++ có 2 loại:
                + Function template 
                + Class template

        * Lợi ích:
            + Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì
            phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ
            liệu khác nhau.

*/

/*
    ! 1. Function template:

        ! Function template single parameter:
            * systax:
                template <class T>
                T someFunction(T arg1, ...) {
                    ...
                }

        ! Function Templates with Multiple Parameters:
            * syntax;
                template<class T1, class T2,.....>
                return_type function_name (arguments of type T1, T2....) {
                    ...
                }


    ! 2. Class template:

        ! Class template with single parameter:
            *syntax:
                template<class Ttype>
                class class_name {
                    ...
                }

        ! Class template with Multiple parameters:
            *syntax:
                template<class T1, class T2, ......>
                class class_name {
                    ...
                }

*/

/*
    ! Default type:
        *syntax:
            template <class Type = int> //defaults to type int
            class Point {
                Type x;
                Type y;
            };

            Point<> point; 

            => do không có kiểu dũ liệu truyền vào, nên trình biên dịch sẽ mặt định 
            hiểu kiểu dữ liệu truyền vào là int.


    ! Template và Friend:

        Ex:
            template <class Type>
            class Point
            {
            public:
                friend void Sum(Type X); // khai báo hàm bạn
                friend void Sum();      // khai báo hàm bạn
            };

            template <class Type>
            void Sum(Type X)
            {
                printf("a friend of only a class template with same type\n");
            }

            void Sum()
            {
                printf("a friend of every class template\n");
            }


    ! Template với thành viên tĩnh: biến tĩnh Static
        Ex:
            template <class Type> 
            class Point
            {
            public:
                static int N;
            };

            Template <class Type> int Point<Type>::N = 0;

            void main()
            {
                Point<int> t1;
                t1.N++;
                Point<float> t2;
                t2.N++;
                Point<int> t3;
                t3.N++;
                cout << "T1: " << t1.N << endl;
                cout << "T2: " << t2.N << endl;
                cout << "T3: " << t3.N << endl;
            }



*/

#include <iostream>
using namespace std;

template <class T1, class T2> // generic
class A
{
    T1 a;
    T2 b;

public:
    A(T1 x, T2 y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        std::cout << "Values of a and b are : " << a << " ," << b << std::endl;
    }
};

int main()
{
    A<int, float> d(5, 6.5);
    d.display();
    return 0;
}


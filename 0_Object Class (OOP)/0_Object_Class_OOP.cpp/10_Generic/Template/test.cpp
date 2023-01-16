
//! Namespace và Template trong C++

#include <bits/stdc++.h>

namespace Example
{
    template <typename T, typename X>
    class Solution
    {
    protected:
        T a;
        X b;
        const T x = 12;

    public:
        Solution(T, X);
        X sum() const;
        T &getA();
        void setA(T a);
    };
}

template <typename T, typename X>
Example::Solution<T, X>::Solution(T a, X b) : a(a), b(b) {}

template <typename T, typename X>
X Example::Solution<T, X>::sum() const
{
    return this->a + this->b;
}

template <typename T, typename X>
T &Example::Solution<T, X>::getA()
{
    return this->a;
}

template <typename T, typename X>
void Example::Solution<T, X>::setA(T a) {}

int main()
{
    system("cls");

    Example::Solution<int, float> p1(4, 6.93);

    std::cout << p1.sum() << std::endl;
    std::cout << p1.getA() << std::endl;

    p1.getA() = 10;
    std::cout << p1.getA() << std::endl;

    std::cin.get();
    return 0;
}

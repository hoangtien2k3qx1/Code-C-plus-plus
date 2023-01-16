
#include <iostream>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;


template<typename T>
class Complex
{
    T real, img;
public:
    Complex():real(0), img(0){}
    
    //friend declarations
    template<typename U>
    friend istream& operator>>(istream& input, Complex<U>& c1);
    template<typename V>
    friend ostream& operator<<(ostream& output, Complex<V>& c1);
    
    Complex operator+(Complex& c1);
};

template<typename T>
istream& operator>>(istream& input, Complex<T>& c1)
{
    cout<<"Real: ";
    input>>c1.real;
    cout<<"Imag: ";
    input>>c1.img;
    return input;
}

template<typename T>
ostream& operator<<(ostream& output, Complex<T>& c1)
{
    output<<c1.real<<"+"<<c1.img<<"i";
    return output;
}

template<typename T>
Complex<T> Complex<T>::operator+(Complex<T>& c1)
{
    Complex temp;
    temp.real = this->real + c1.real;
    temp.img = this->img + c1.img;
    return temp;
}

int main()
{
    Complex<int> cmp1;
    cin>>cmp1;
    return 0;
}

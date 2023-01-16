
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Geometry {
public:
	virtual double perimeter() = 0; // hàm tính chu vi
	virtual double area() = 0; // hàm tính diện tích
	virtual void display() {
		cout << "Perimeter: " << perimeter() << endl;
		cout << "Area: " << area() << endl;
	}
};

class Triangle : public Geometry {
private:
	int a;
	int b;
	int c;
public:
	Triangle() {}
	Triangle(int a, int b, int c) : a(a), b(b), c(c) {} // Initialize list
	double perimeter() {
		return a + b + c;
	}
	double area() { // herong
		double p = (a + b + c) / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

class Rectangle : public Geometry {
private:
	int w;
	int h;
public:
    Rectangle(int w, int h) : w(w), h(h) {}
	double perimeter() {
		return (w + h) * 2;
	}
	double area() {
		return w * h;
	}
};

class Circle :public Geometry {
private:
	int r;
public:
	Circle() {}
	Circle(int r) : r(r) {}
	double perimeter() {
		return 2 * 3.14 * r;
	}
	double area() {
		return 3.14 * r * r;
	}
};

int main(){
	system("cls");
	int a, b, c, d, e, r;
	cout << "Nhap thong so tam giac: "; cin >> a >> b >> c;
	cout << "Nhap thong so hinh chu nhat: "; cin >> d >> e;
	cout << "Nhap thong so hinh tron: "; cin >> r ;

	Geometry * g[3];
	g[0] = new Triangle(a, b, c);
	g[1] = new Rectangle(d, e);
	g[2] = new Circle(r);

	for(int i = 0; i < 3 ;i++){
		switch(i){
			case 0:
				cout << "HINH TAM GIAC" << endl;
				break;
			case 1:
				cout << "HINH CHU NHAT" << endl;
				break;
			case 2:
				cout << "HINH TRON" << endl;
				break;
		}
		g[i]->display();
	}

	cin.get();
	return 0;
}
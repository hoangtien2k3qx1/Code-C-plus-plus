
// Tính Chu Vi của Tam giác khi biết tọa độ 3 đỉnh (OOP)

#include<iostream>
#include<cmath>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() {
        
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void setX(int x) {
        this->x = x;
    }
    int getX() {
        return x;
    }
    void setY(int y) {
        this->y = y;
    }
    int getY() {
        return y;
    }
};

class Triangle {
private:
	Point vertice1; // Aggregation
	Point vertice2;
	Point vertice3;

public:
	Triangle(Point vertice1, Point vertice2, Point vertice3) {
		this->vertice1 = vertice1;
		this->vertice2 = vertice2;
		this->vertice3 = vertice3;
	}
	
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		vertice1 = Point(x1, y1);
		vertice2 = Point(x2, y2);
		vertice3 = Point(x3, y3);
	}

	double getPerimeter() {
		double d1 = sqrt(pow(vertice1.getX() - vertice2.getX(), 2) + pow(vertice1.getY() - vertice2.getY(), 2));
		double d2 = sqrt(pow(vertice1.getX() - vertice3.getX(), 2) + pow(vertice1.getY() - vertice3.getY(), 2));
		double d3 = sqrt(pow(vertice2.getX() - vertice3.getX(), 2) + pow(vertice2.getY() - vertice3.getY(), 2));
		return d1 + d2 + d3;
	}
};

int main() {
	Point vertice1(1, 3);
	Point vertice2(2, 3);
	Point vertice3(4, 2);
	Triangle triangle1(vertice1, vertice2, vertice3);
	Triangle triangle2(4, 5, 2, 6, 3, 7);
	cout << triangle1.getPerimeter() << endl;
	cout << triangle2.getPerimeter() << endl;
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;

class Point {
public:
    int x;
    int y;
public:
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    friend Point operator - (Point A, Point B) {
        return Point(A.x - B.x, A.y - B.y);
    }

    double distance(Point B) {
        return sqrt(pow(this->x - B.x, 2) + pow(this->y - B.y, 2));
    }

    void display() {
        cout << "X = " << x << "Y = " << y << endl;
    }
};

class Triangle : public Point {
private:
    Point A;
    Point B;
    Point C;
public:
    Triangle() {}
    Triangle(Point A, Point B, Point C) : A(A), B(B), C(C) {}



    double perimeter() {
        return A.distance(B) + A.distance(C) + B.distance(C);
    }

    double area() {
        return abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)) * 0.5;
    }

    Point center() {
		return Point(double(A.x + B.x + C.x) / 3, double(A.y + B.y + C.y) / 3);
	}

	bool isTriangle() {
		double a = A.distance(B);
		double b = B.distance(C);
		double c = C.distance(A);
		if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0)
		{
			return true;
		}
		return false;
	}
};

int main()
{
    Point A(1,2);  // kết quả có thể ra khác nhau tùy vào cách viết hàm ở 2 lớp Point, Triangle
    Point B(4,5);
    Point C = B - A;
    C.display();

    Triangle tri(Point(1,2), Point(4,5), Point(6,7)); 

    cout << "Perimeter: " << tri.perimeter() << endl;  
    cout << "Area: " << tri.area() << endl;

    tri.center().display(); // tri.center() trả về điểm có tọa độ trọng tâm, có hoành độ x, tung độ y
                            // Point G = tri.center(); tạo ra G và gán tri.center() cho G
                            // G.display()    sau đó gọi hàm display() , đây là cách viết khác

    Point(5,5).display(); // in ra x = 5, y = 5

    cout << tri.isTriangle(); // nếu là false in ra 0, true in ra 1

    cout << endl;

    return 0;
}
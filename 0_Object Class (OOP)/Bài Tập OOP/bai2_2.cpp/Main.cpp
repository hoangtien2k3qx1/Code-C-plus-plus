
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#include "Point.cpp"
#include "PolyLine.cpp"

int main() {
	PolyLine polyLine;
	polyLine.appendPoint(Point(1, 1));
	polyLine.appendPoint(Point(2, 3));
	polyLine.appendPoint(3, 0);
	polyLine.appendPoint(4, 2);
	cout << polyLine.getLength();
	return 0;
}
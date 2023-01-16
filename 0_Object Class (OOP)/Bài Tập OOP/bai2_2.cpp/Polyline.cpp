
#include "Point.cpp"

class PolyLine {
private:
	vector<Point> points;

public:
	PolyLine() {
	}

	PolyLine(vector<Point> points) {
		this->points = points;
	}

	void appendPoint(Point point) {
		points.push_back(point);
	}

	void appendPoint(int x, int y) {
		points.push_back(Point(x, y));
	}

	double getLength() {
		double length = 0;
		for (int i = 0; i < points.size() - 1; i++) {
			int x1 = points[i].getX();
			int y1 = points[i].getY();
			int x2 = points[i + 1].getX();
			int y2 = points[i + 1].getY();
			double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			length += distance;
		}
		return length;
	}
};
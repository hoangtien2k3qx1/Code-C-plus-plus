
#pragma once

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

	int getX() {
		return x;
	}

	void setX(int x) {
		this->x = x;
	}

	int getY() {
		return y;
	}

	void setY(int y) {
		this->y = y;
	}
};
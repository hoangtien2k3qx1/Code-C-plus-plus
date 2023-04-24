#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class DIEM3D {
public:
    DIEM3D(int x, int y, int z) : x(x), y(y), z(z) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getZ() const {
        return z;
    }

    bool operator>(const DIEM3D& other) const {
        int sumSquaredThis = x * x + y * y + z * z;
        int sumSquaredOther = other.x * other.x + other.y * other.y + other.z * other.z;
        return sumSquaredThis > sumSquaredOther;
    }

private:
    int x;
    int y;
    int z;
};

int main() {
    int N;
    std::cin >> N; 

    std::vector<DIEM3D> diemList; 

    for (int i = 0; i < N; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        DIEM3D diem(x, y, z);
        diemList.push_back(diem);
    }

    // Tính t?ng các di?m
    int sumX = 0;
    int sumY = 0;
    int sumZ = 0;
    for (const DIEM3D& diem : diemList) {
        sumX += diem.getX();
        sumY += diem.getY();
        sumZ += diem.getZ();
    }

    std::cout << "(" << sumX << ", " << sumY << ", " << sumZ << ")" << std::endl;

    std::sort(diemList.begin(), diemList.end(), std::less<DIEM3D>());

    for (const DIEM3D& diem : diemList) {
        std::cout << "(" << diem.getX() << ", " << diem.getY() << ", " << diem.getZ() << ")" << std::endl;
    }

    return 0;
}

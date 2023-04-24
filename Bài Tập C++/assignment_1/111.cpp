#include <iostream>

class DIEM3D {
private:
    int x;
    int y;
    int z;

public:
    DIEM3D() {
        x = 0;
        y = 0;
        z = 0;
    }

    DIEM3D(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    // Get và Set
    void setX(int _x) {
        x = _x;
    }

    void setY(int _y) {
        y = _y;
    }

    void setZ(int _z) {
        z = _z;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getZ() {
        return z;
    }

    DIEM3D doiXung(int k) {
        DIEM3D result;
        switch (k) {
            case 1: // Oxy
                result.setX(x);
                result.setY(y);
                result.setZ(-z);
                break;
            case 2: // Oyz
                result.setX(-x);
                result.setY(y);
                result.setZ(z);
                break;
            case 3: //  Oxz
                result.setX(x);
                result.setY(-y);
                result.setZ(z);
                break;
            case 4: // qua tâm O
                result.setX(-x);
                result.setY(-y);
                result.setZ(-z);
                break;
            default:
                std::cout << "Khong hop le!";
                break;
        }
        return result;
    }

    // (x, y, z)
    void hienThi() {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main() {
    // input
    int xA, yA, zA;
    int xB, yB, zB;
    int k;
    std::cin >> xA >> yA >> zA;
    std::cin >> xB >> yB >> zB;
    std::cin >> k;

    DIEM3D A(xA, yA, zA);

    int hoanhDoA = A.getX();
    std::cout << hoanhDoA << std::endl;

    // 
    int tong = xB + yB + zB;
    std::cout << tong << std::endl;

    // 
    DIEM3D doiXung = A.doiXung(k);
    doiXung.hienThi();

    return 0;
}

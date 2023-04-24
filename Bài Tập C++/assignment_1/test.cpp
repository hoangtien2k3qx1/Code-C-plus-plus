#include <iostream>
#include <string>

using namespace std;

class SinhVien {
private:
    string hoTen;
    int maSV;
    float diem;

public:
    SinhVien() {}
    SinhVien(string hoTen, int maSV, float diem) {
        this->hoTen = hoTen;
        this->maSV = maSV;
        this->diem = diem;
    }

    friend ostream& operator<<(ostream& os, const SinhVien& sv) {
        os << "\t+ Ho ten: " << sv.hoTen << endl;
        os << "\t+ Ma so sinh vien: " << sv.maSV << endl;
        os << "\t+ Diem: " << sv.diem << endl;
        return os;
    }

    friend istream& operator>>(istream& is, SinhVien& sv) {
        cout << "\t+ Nhap ho ten: ";
        is.ignore();
        getline(is, sv.hoTen);
        cout << "\t+ Nhap ma so sinh vien: ";
        is >> sv.maSV;
        cout << "\t+ Nhap diem: ";
        is >> sv.diem;
        return is;
    }

    float getDiem() {
        return diem;
    }
};

class MangSinhVien {
private:
    SinhVien* mangSV;
    int soLuong;

public:
    MangSinhVien() {
        mangSV = NULL;
        soLuong = 0;
    }

    MangSinhVien(int soLuong) {
        this->soLuong = soLuong;
        mangSV = new SinhVien[soLuong];
    }

    ~MangSinhVien() {
        delete[] mangSV;
    }

    void operator=(const MangSinhVien& other) {
        soLuong = other.soLuong;
        mangSV = new SinhVien[soLuong];
        for (int i = 0; i < soLuong; i++) {
            mangSV[i] = other.mangSV[i];
        }
    }

    friend ostream& operator<<(ostream& os, const MangSinhVien& mangSV) {
        os << "Danh sach sinh vien: " << endl;
        for (int i = 0; i < mangSV.soLuong; i++) {
            os << "Sinh vien thu " << i + 1 << ": " << endl;
            os << mangSV.mangSV[i];
        }
        return os;
    }

    friend istream& operator>>(istream& is, MangSinhVien& mangSV) {
        cout << "Nhap so luong sinh vien: ";
        is >> mangSV.soLuong;
        mangSV.mangSV = new SinhVien[mangSV.soLuong];
        for (int i = 0; i < mangSV.soLuong; i++) {
            cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
            is >> mangSV.mangSV[i];
        }
        return is;
    }

    void setSoLuong(int soLuong) {
        this->soLuong = soLuong;
    }

    int getSoLuong() {
        return soLuong;
    }

    float tinhDiemTrungBinhLop() {
        float diemTong = 0;
        for (int i = 0; i < soLuong; i++) {
            diemTong += mangSV[i].getDiem();
        }
    	return diemTong / soLuong;
	}

	void sapXepTheoDiem() {
	    for (int i = 0; i < soLuong - 1; i++) {
	        for (int j = i + 1; j < soLuong; j++) {
	            if (mangSV[i].getDiem() < mangSV[j].getDiem()) {
	                SinhVien temp = mangSV[i];
	                mangSV[i] = mangSV[j];
	                mangSV[j] = temp;
	            }
	        }
	    }
	}
	
	void inDanhSachSinhVienDiemCaoNhat() {
	    float diemCaoNhat = mangSV[0].getDiem();
	    for (int i = 0; i < soLuong; i++) {
	        if (mangSV[i].getDiem() == diemCaoNhat) {
	            cout << mangSV[i] << endl;
	        }
	        else {
	            break;
	        }
	    }
	}

};

int main() {
	MangSinhVien lopHoc;
	cin >> lopHoc;
	cout << endl << "Thong tin lop hoc: " << endl;
	cout << lopHoc;
	cout << "\n=> Diem trung binh cua lop hoc: " << lopHoc.tinhDiemTrungBinhLop() << endl;
	lopHoc.sapXepTheoDiem();
	cout << "\n=> Danh sach sinh vien sau khi sap xep theo diem giam dan: " << endl;
	cout << lopHoc;
	cout << "\n=> Danh sach sinh vien co diem cao nhat: " << endl;
	lopHoc.inDanhSachSinhVienDiemCaoNhat();
	return 0;
}

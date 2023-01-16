
/*
	* Để đảm bảo tính đóng gói của đối tượng trọng class, nên người ta dùng 2 phương: 
		- setter 
		- getter
				+ setter dùng để cập nhật lại dữ liệu cho các thuộc tính của class 
				mà vẫn đảm bảo tính đóng gói
				+ getter dùng để trả về giá trị của thuộc tính và vẫn đảm bảo tính 
				đóng gói của class
			
    ! Syntax: setter
        void set<tên thuộc tính> (<tham số giá trị mới>) {
            this-><tên thuộc tính> = <tham số giá trị mới>;
        }

    Ex:
        void setAddress(string address) {
		    this->address = address;
	    }


    ! Syntax: getter
        <kiểu dữ liệu thuộc tính> get<tên thuộc tính> () {
            return this-><tên thuộc tính>;
        }
    
    Ex:
        string getAddress() {
		    return address;
	    }

*/

#include<iostream>
using namespace std;

class Person {
private:
	int id;
	string name;
	int age;
	string address;
public:
	Person(int id, string name, int age, string address) {
		this->id = id;
		this->name = name;
		this->age = age;
		this->address = address;
	}
	int getId() {
		return id;
	}
	void setId(int id) {
		this->id = id;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	int getAge() {
		return age;
	}
	void setAge(int age) {
		this->age = age;
	}
	string getAddress() {
		return address;
	}
	void setAddress(string address) {
		this->address = address;
	}
};

int main() {
	Person p = Person(20041, "Tien", 19, "Thanh Hoa");
	cout << "Id: " << p.getId() << endl;
	cout << "Name: " << p.getName() << endl;
	cout << "Age: " << p.getAge() << endl;
	cout << "Address: " << p.getAddress() << endl;

	p.setAddress("Quang Xuong - Thanh Hoa");
	p.setId(123456789);
	p.setAge(20);
	p.setName("Hoang Anh Tien");

	cout << "\nId: " << p.getId() << endl;
	cout << "Name: " << p.getName() << endl;
	cout << "Age: " << p.getAge() << endl;
	cout << "Address: " << p.getAddress() << endl;

	return 0;
}


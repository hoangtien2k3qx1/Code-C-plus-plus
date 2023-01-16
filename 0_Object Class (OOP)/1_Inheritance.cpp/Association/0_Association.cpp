
/*
    Quan hệ kết hợp ( Association ) :
        Quan hệ kết hợp xảy ra khi một đối tượng có thuộc tính là một đối tượng khác. 
*/

#include<iostream>
using namespace std;

class Manager {
private:
	string name;

public:
	Manager() {

	}
	Manager(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

class Employee {
private:
	string name;
	Manager manager;

public:
	Employee(string name, Manager manager) {
		this->name = name;
		this->manager = manager;
	}

	string getManagerName() {
		return manager.getName();
	}

	string getName() {
		return name;
	}
};


=> Trong đoạn code trên lớp Employee có thuộc tính là đối tượng thuộc lớp Manager, do đó hai lớp này có quan hệ kết hợp. 

=> Quan hệ kết hợp được chia làm 2 loại là quan hệ thu nạp (Aggregation) và quan hệ hợp thành (Composition)


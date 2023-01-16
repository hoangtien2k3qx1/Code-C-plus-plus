
// Virtual Destructor
/*
    Virtual Destructor:
    - Trong một lớp thì Destructor có thể được đánh dấu làm hàm 
	ảo còn Constructor thì không được đánh dấu là hàm ảo.

        virtual Product();   // illegal : không thể 
        virtual ~Product();  // legal : có thể 

*/

*** Trường hợp 1: Phương thức lớp cha không đánh dấu Virtual:

#include<iostream>
using namespace std;

class Base
{
public:
	Base() {};
	~Base() { cout << "Destructor Base\n"; };
};


class Derived : public Base
{
private:
	int* m_array;
public:
	Derived() { this->m_array = new int[1024]; };
	~Derived()
	{
		cout << "Destructor Derived\n";
		delete this->m_array;
	}
};

int main()
{
	Base *b = new Derived();
	delete b;
	return 0;
}

=> Với lớp con như trên, mặc dù định nghĩa phương thức để giải phóng m_array 
nhưng phương thức của lớp con không được gọi. 
Có nghĩa là chương tình đã rò rỉ 1024 * 4 bytes bộ nhớ.




//* //////////////////////////////////////////////




*** Trường hợp 2: Phương thức lớp cha có đánh dấu Virtual:
#include<iostream>
using namespace std;

class Base
{
public:
	Base() {};
	virtual ~Base() { cout << "Destructor Base\n"; };
};


class Derived : public Base
{
private:
	int * m_array;
public:
	Derived() { this->m_array = new int[1024]; };
	~Derived()
	{
		cout << "Destructor Derived\n";
		delete this->m_array;
	}
};

int main()
{
	Base *b = new Derived();
	delete b;
	return 0;
}

=> Như vậy phương thức hủy của lớp con được gọi trước sau đó mới gọi phương thức hủy lớp cha. 
Vì thế nên bộ nhớ sẽ được giải phóng hoàn toàn. Virtual Destructor là khái niệm rất 
quan trọng trong việc kế thừa.




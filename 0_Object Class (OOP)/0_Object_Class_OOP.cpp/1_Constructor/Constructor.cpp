
/*
    ! Constructor : hay còn gọi là hàm tạo

    - Constructor trong C++ là một phương thức đặc biệt được gọi là tự động tại thời điểm tạo đối tượng.
    Nó được sử đụng để khởi tạo thành viên dữ liệu của các đối tượng mới. Constructor đùng tên của lớp hoặc struct

    ! - Constructor: chia làm hai loại

            * + constructor mặc định (không có tham số)
            * + constructor có tham số


    ! - Constructor : không có kiểu trả về.

    **** Constructor mặc định C++: tên của Constructor trùng với tên của Class( và nó tự gọi hàm)

    (một constructor không có đối số được gọi là một constructor mặc định)


    - Nạp chồng constructor.

*/

/*
    ! Initializer list: DANH SÁCH KHỞI TẠO


    ! - Khi nào thì cần dùng danh sách khởi tạo: 
        
        * + khởi tạo các thành viên hàm không tĩnh (non-static constance)

            Ex:
                
                class Test {
                        const int t;
                    public:
                        Test(int t): t(t) {}  //Phải dùng danh sách khởi tạo
                        int getT() { return t; }
                };
                
                int main() {
                    Test t1(10);
                    cout << t1.getT();
                    return 0;
                }

                => output: 10


        * + Để khởi tạo các thành viên tham chiếu.

            Ex:

                class Test {
                        int &t;
                    public:
                        Test(int &t) : t(t) {}  //Phải dùng danh sách khởi tạo
                        int getT() { return t; }
                };
                
                int main() {
                    int x = 20;
                    Test t1(x);
                    cout<<t1.getT()<<endl;
                    x = 30;
                    cout<<t1.getT()<<endl;
                    return 0;
                }

                => OUTPUT:
                        20
                        30
                


        * + Khởi tạo đối tượng thành viên không có hàm mặc định:

            Ex:

                class A {
                    int i;
                public:
                    A(int );
                };
                
                A::A(int arg) {
                    i = arg;
                    cout << "A's Constructor called: Value of i: " << i << endl;
                }
                
                / Lớp B. chứa đối tượng thuộc lớp A
                class B {
                    A a;
                public:
                    B(int );
                };
                
                B::B(int x):a(x) {  //Phải dùng danh sách khởi tạo
                    cout << "B's Constructor called";
                }
                
                int main() {
                    B obj(10);
                    return 0;
                }
                => OUTPUT:
                    A's Constructor called: Value of i: 10
                    B's Constructor called
                

        * + Để khởi tạo các thanh viên lớp cơ sở.

            Ex: 

                class A {
                    int i;
                public:
                    A(int );
                };
                
                A::A(int arg) {
                    i = arg;
                    cout << "A's Constructor called: Value of i: " << i << endl;
                }
                
                / Lớp B thừa kế từ A
                class B: A {
                public:
                    B(int );
                };
                
                B::B(int x): A(x) { // Phải dùng danh sách khởi tạo
                    cout << "B's Constructor called";
                }
                
                int main() {
                    B obj(10);
                    return 0;
                }

        
        * + Khi tên tham số của hàm giống thành viên dữ liệu.

            Ex:

                class A {
                    int i;
                public:
                    A(int );
                    int getI() const { return i; }
                };
                
                A::A(int i): i(i) { }  // Phải dùng con trỏ this hoặc danh sách khởi tạo

                Hàm tạo trên có thể viết lại như sau:
                A::A(int i) {
                    this->i = i;
                }

                
                int main() {
                    A a(10);
                    cout<<a.getI();
                    return 0;
                }
                => OUTPUT:
                    10


        * + Về hiệu xuất thì danh sách khởi tạo sẽ nhanh hơn.

*/


#include <iostream>
using namespace std;

class Employee {
    public:
        int id; // data member (bien instance)
        string name; // data member(bien instance)
        float salary;
        Employee(int, string, float);
        void display();
};

Employee::Employee(int id, string name, float salary) {
    this->id = id;      // con trỏ this
    this->name = name;
    this->salary = salary;
}

void Employee::display() {
    cout << id << " " << name << " " << salary << endl;
}

int main(void) {
    Employee e1 = Employee(101, "Phan Van Vinh", 500); // tao doi tuong Employee
    Employee e2 = Employee(102, "Dao Van Hoa", 1000);
    e1.display();
    e2.display();
    return 0;
}
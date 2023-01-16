
/*
    * Từ khóa " Const " và " Mutable "

        int main()
        {
            int a = 5;
            const int b = 10; // int const b = 10; 
            int mutable c = 50; // thuộc tính mutable thì có thể thay đổi được giá trị.

            x = 5;	// Báo lỗi (vì là hàng số ko thể thay đổi giá trị)
            y = 7;	// Báo lỗi (vì là hàng số ko thể thay đổi giá trị)

            return 0;
        }

        => Vị trí đặt const dù trước hay sau int thì đều có chung một chức năng 
        là chỉ định x, y là hằng, thay đổi giá trị của 2 biến đó sẽ bị báo lỗi.
        

    ! BIẾN THAM CHIẾU:
        => Tham chiếu có thể thay đổi được giá trị, nhưng biến đó là hằng tham chiếu 
        thì cũng không thể thay đổi được giá trị.

        int main()
        {
            int x = 10;
            const int& A = x;  // Khai báo A là hằng tham chiếu tới vùng nhớ của x

            A = 6;	// Báo lỗi do A là biến tham chiếu hằng
            x = 6;	// Không báo lỗi do x là một biến bình thường

            return 0;
        }


    ! BIẾN CON TRỎ:
        
        +   int main()
            {
                int x = 7;
                int y = 13;

                const int *p = &x;	// Đọc là Non-const pointer to a const value

                *p = 100;	// Báo lỗi
                p = &y;	// Không báo lỗi

                return 0;
            }

            => Không thể thay đổi được giá trị vùng nhớ của p, nhưng vẫn có thể thay đổi 
            được địa chỉ vùng nhớ mà p trỏ tới.



        +   int main()
            {
                int x = 7;
                int y = 13;

                int *const p = &x;	// Đọc là Const pointer to a non-const value

                *p = 100;	// Không báo lỗi
                p = &y;	// Báo lỗi

                return 0;
            }

            => Có thể thay đổi được giá trị vùng nhớ, nhưng không thể thay đổi địa chỉ 
            mà con trỏ p trỏ tới.



        - Nếu muốn con trỏ p vừa không thể thay đổi giá trị, vừa không thể thay đổi 
        địa chỉ vùng nhớ mà con trỏ p trỏ tới:
            
            systax:     const int *const p = &x;

*/

/*
    ! Tham số hàm là Const Reference: hằng tham chiếu

    +   int func(const int& number)
        {
            / Your Codes
        }


    +   void Message() const   //! có từ khóa const ở cuối, nên Message là 1 phương thức hằng thành viên, thì tất cả các thuộc tính của lớp đó sẽ không thể thay đổi giá trị trong quá trình biên dịch.  
        {
            cout << "This is const object" << endl;
        }


    +   const int &getData() const {
            return m_Data;
        }
    


    ! Const Cast:

        int func(int &number) 
        {
            number += 100;
            return number;
        }

        int main()
        {
            const int x = 13;

            int ans = func(x);	// Báo lỗi

            int ans = func(const_cast<int &>(x));	// Dùng const_cast

            cout << ans << endl; // 113
            cout << x << endl;  // 13

            return 0;
        }

        => " const_cast " giải quyết việc truyền thuộc tính kiểu const vào phương thức hàm để thay đổi giá trị.

        ! Syntax:
                const_cast<type name>(expression)

*/


#include<bits/stdc++.h>
using namespace std;


class MyClass
{
private:
	int m_Data;
    mutable int a1; 

public:
	MyClass(int Data) : m_Data(Data) {}

	// Message() Function for non-const object
	void Message()
	{
		cout << "This is non-const object" << endl;
	}


    void Message() const  //! có từ khóa const ở cuối, nên Message là 1 phương thức hằng thành viên, thì tất cả các thuộc tính của lớp đó sẽ không thể thay đổi giá trị trong quá trình biên dịch.  
	{
		cout << "This is const object" << endl;
	}
    

	// Get value of m_Data to use or modify
	int& getData()   //! kiểu trả về là tham chiếu int, nên có thể thay đổi được giá trị.
	{
		return m_Data;
	}

    const int& getData() const { //! hàm này không thể thay đổi giá trị
        return m_Data;
    }

    // int& getData() const {  //! sai, vì phương thức này trả vê tham chiếu, mà thêm const là thành phương thức tỉnh, thì không thể trả về tham chiếu được nữa.
    //     return m_Data;
    // }

};



int main()
{
	MyClass obj1(13);
	const MyClass obj2(100);

	obj1.getData() = 86;  //! vì & đứng trước tên hàm, nên đó là hàm tham chiếu, vậy nên có thể thay đổi được giá trị bên trong hàm.
	// obj2.getData() = 1;	//! báo lỗi do getData() không phải phương thức hằng nên ko truy xuất được.

    cout << obj1.getData() << endl;  
    cout << obj2.getData() << endl;

	obj1.Message(); //! vì obj1 là đối tượng bình thường nên nó sẽ gọi tới Messege thứ 1.
	obj2.Message(); //! vì obj2 là đối tượng hằng, nên chỉ có thể gọi phương thức hằng Messenge thứ 2.

	return 0;
}


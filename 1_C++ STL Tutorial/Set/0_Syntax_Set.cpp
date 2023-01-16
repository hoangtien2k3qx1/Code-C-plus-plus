
/*  C++ STL Set: cũng kiểu dữ liệu và duy nhất

    + Set trong C++ là một tập hợp các phần tử duy nhất được sắp xếp theo thứ tự cụ thể, 
    và được sử dụng làm tiêu chuẩn để xử lý các đối tượng chứa nhiều phần tử trong C++.

    + Mỗi phần tử trong set có giá trị phải là duy nhất, có nghĩa là nó không được trùng 
    lặp với các giá trị còn lại trong set. 
    
    + Ngoài ra thì phần tử trong set không thể thay 
    đổi giá trị, tuy nhiên chúng có thể được chèn hoặc xóa khỏi set.



    Syntax:
            template < class T,                             // set::key_type/value_type  
                    class Compare = less<T>,        // set::key_compare/value_compare  
                    class Alloc = allocator<T>         // set::allocator_type  
                    > class set;  



    Sytax: Khai báo 1 set trong c++
                std::set<type> st;




    Loại:	            Truy cập ngẫu nhiên:           Thêm xóa tìm kiếm ngẫu nhiên:
    vector	                    O(1)	                            O(N)
    set, multiset	            chậm	                            O(logN)
  


*/
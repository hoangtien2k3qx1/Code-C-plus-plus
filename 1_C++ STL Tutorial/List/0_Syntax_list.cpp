
/*  
    * List: list còn được gọi là danh sách liên kết đôi trong C++. (double linked list)

    * List trong C++ là một danh sách liên kết đôi được sử dụng làm tiêu chuẩn để xử lý 
    các đối tượng chứa nhiều phần tử trong C++.

    * Điều đó tạo ra ưu điểm của list trong C++ đó là, việc chèn và xóa một vị trí bất 
    kỳ trong list có thể được thực hiện trong một thời gian cố định với tốc độ cao O(1).

    * Tuy nhiên so với list thì vector trong C++ tuy chỉ có khả năng thêm xóa phần tử vào 
    vị trí cuối cùng, nhưng lại có ưu thế trong việc truy cập vào vị trí ngẫu nhiên với 
    tốc độ cao.

    * Khác với vector với các phần tử được lưu trong một mảng động thì phần tử trong 
    list và forward_list lại được lưu trong các phân vùng bộ nhớ độc lập được gọi là Node. 
    Và những node này được liên kết tuần tự với nhau thông qua con trỏ của chúng.


    Syntax:
                list<type> lst; 



    Loại:	        Truy cập ngẫu nhiên:	        Thêm xóa ngẫu nhiên:
    vector	            O(1)	                       O(N)
    list	            O(N)	                       O(1)


*/
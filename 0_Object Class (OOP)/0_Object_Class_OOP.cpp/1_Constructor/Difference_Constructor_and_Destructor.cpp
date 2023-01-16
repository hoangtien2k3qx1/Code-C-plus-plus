
// Sự khác nhau giữa constructor và descontructor trong C++


    Constructor                                                 Destructor

    + nó phân bổ bộ nhớ cho một đối tượng                       + nó giải phóng bộ nhớ cho một đối tượng
    
    + class_name (đối số nếu có) {};                            + ~ class_name (không có đối số) {};

    + Trình xây dựng được gọi tự động,                          + Destructor được gọi tự động, khi khối được 
      trong khi đối tượng được tạo.                               thoát hoặc chương trình kết thúc.

    + Có thể có nhiều constructor trong lớp.                    + Nhưng luôn có một hàm hủy duy nhất trong lớp.

    + Copy constructor cho phép một constructor khai            + Không có khái niệm như vậy.
    báo và khởi tạo một đối tượng từ một đối tượng khác.
    











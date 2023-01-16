
// cin.ignore Trong C+ :

+   cin.ignore trong C++ là một hàm thành viên trong class istream có tác dụng trích xuất các ký tự từ luồng đầu 
    vào tiêu chuẩn (cin) và loại bỏ chúng, cho đến khi đã trích xuất đủ số ký tự chỉ định, hoặc là cho tới khi tìm 
    thấy ký tự phân tách được chỉ định.


+   syntax:     cin.ignore(n, delim);




//! Difference between getline and cin.getline

+ getline (string) in C++: // hàm này dùng cho ' string ' 
    Syntax:

        istream& getline(istream& is, 
                string& str, char delim);


        getline(cin, str);




+ syntax:     cin.getline( str, n );  // hàm nay dùng cho mảng ký tự ' char '


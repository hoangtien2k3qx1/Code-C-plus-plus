
// iterator in C++
/*
    ! Iterators are just like pointers used to access the container elements.


    Ex:
            map<int, string>::iterator it;
            vector<int>::iterator it; 


        + Operator* cereference và trả về giá trị bên trong container tại vị trí mà iterator được đặt.
        + Operator++ di chuyển iterator đến phần tử tiếp theo trong container.
        + Operator-- ngược lại so với operator++.
        + Operator== và operator!= dùng để so sánh vị trí tương đối của 2 phần tử đang được trỏ đến bởi 2 iterator.
        + Operator= dùng để gán vị trí mà iterator trỏ đến.
        

    ! Defference between Interator and Pointer:

            + Iterator là một con trỏ được sử dụng để đại diện cho một phần tử nào đó. 

            + Được sử dụng đại diện cho các biến được trỏ đến để thực hiện các thao tác 
            thêm, sửa, xóa, .. Trong trường hợp này con trỏ iterator it đã trỏ đến phần 
            tử đầu tiên của vector 

            + Một Iterator là một đối tượng có thể đi qua (iterate over) một container 
            class mà không cần biết trật tự các phần tử bên trong mảng. 
            Iterator còn là một cách để truy cập dữ liệu bên trong các container.



*/


#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int, string> mapa; // key, data
    map<int, string>::iterator it;
    
    mapa.insert(pair<int, string> (0,"Viet Nam 0"));
    mapa.insert(pair<int, string> (1,"Viet Nam 1"));
    mapa.insert(pair<int, string> (2,"Viet Nam 2"));
    mapa.insert(pair<int, string> (3,"Viet Nam 3"));
    mapa.insert(pair<int, string> (4,"Viet Nam 4"));
    mapa.insert(pair<int, string> (5,"Viet Nam 5"));

    for(map<int,string>::iterator i = mapa.begin();i!=mapa.end();i++){
        cout << i->first << ": " << i->second << endl;
    }

    return 0;
}
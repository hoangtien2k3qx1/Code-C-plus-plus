
/*
    * Map là một kiểu dữ liệu với mỗi phần tử là ánh xạ giữa yếu tố key (khóa) với giá trị (value) của nó. 

    Tương tự set, map không chứa hai phần tử nào giống nhau và các phần tử trong map được 
    sắp xếp theo một thứ tự nào đó. Mỗi phần tử trong map có yếu tố key dùng để xác định 
    value của nó, điều này cũng có nghĩa là key và value có thể có kiểu khác nhau.


    + Các lớp vector, list thuộc cấu trúc Sequence Containers (cấu trúc tuần tự)
    + riêng với lớp map thuộc 1 cấu trúc khác đó là Associative Containers (cấu trúc liên kết), 
    là kiểu dữ liệu cho phép quản lý 1 cặp key/value - khóa và giá trị



    + LỚP[A] Pair:
        pair cho phép gộp 2 đối tượng thành 1 cặp, hai đối tượng có thể chèn cùng hoặc khác kiểu
        với thuộc tính first là key và second là value.

            !Syntax: 
                    pair<valueType1, valueType2> variableName;

                    variableName.first      => giá trị thứ 1
                    variableName.second     => giá trị thứ 2



    !Syntax: 
                map<key, value> name;

                map<int, int> a;
                map<char, int> b;



    ! + Cũng giống với những lớp vector, list đều có:

        default constructor:    map<char, int> character0;

        ranger constructor:     map<char, int> character1(character0.begin(), character0.end());

        copy constructor:       map<char, int> character2(character1);




    + Duyệt Map:
            map<int, char*> texes;
            texts[0] = "ab";
            texts[1] = "bc";
            texts[0] = "cd";

            map<int, char*>::iterator i;
            for (i = texts.begin(); i != texts.end(); i++)
                cout << *i << endl;

            => output (0, "cd"), (1, "bc") , (vì map chỉ lưu phần tử duy nhất)


*/

#include<bits/stdc++.h>
#include <string.h>  
#include <iostream>  
#include <map>  
#include <utility>  
using namespace std;  

int main()  
{  
    map<int, string> Employees;  

    Employees[101] = "Nikita";  
    Employees[105] = "John";  
    Employees[103] = "Dolly";  
    Employees[104] = "Deep";  
    Employees[102] = "Aman";  

    cout << "Employees[104]=" << Employees[104] << endl << endl;  
    cout << "Map size: " << Employees.size() << endl;  

    cout << endl << "Natural Order:" << endl;  

    for(map<int, string>::iterator itr = Employees.begin(); itr != Employees.end(); ++itr)  
    {  
        cout << (*itr).first << ": " << (*itr).second << endl;  
    }  

    cout << endl << "Reverse Order:" << endl; 

    for( map<int,string>::reverse_iterator itr = Employees.rbegin(); itr != Employees.rend(); ++itr)  
    {  
        cout << itr->first << ": " << itr->second << endl;  
    }  

    return 0;
}  
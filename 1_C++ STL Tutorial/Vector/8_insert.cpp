
/*  C++ Vector insert(): It is used to insert new element at specified position.

    ! Syntax: Consider a vector v. Syntax would be:
        + insert(iterator, val);  
          * insert(vị trí chèn vào, giá trị được chèn vào)

        + insert(iterator, n, val);  
          * insert(vị trí chèn vào , số lần giá trị xuất hiện , giá trị được chèn vào )

        + insert(iterator, InputIterator first, InputIterator last);
          * insert(vị trí chèn vào , phạm vị đầu , phạm vi cuối) 


    Parameter:
        + iterator:An iterator defines the position, where the new elements are to be inserted.
        !( Một trình lặp xác định vị trí, nơi các phần tử mới sẽ được chèn vào. )
        + val: The valspecifies the value which is to be inserted.
        !( Giá trị xác định giá trị sẽ được chèn vào )
        + n: Number of times the value is to be occurred.
        !(Số lần giá trị được xuất hiện.)
        + (first,last): It defines the range of elements which is to be inserted.
        !(Nó xác định phạm vi của các phần tử sẽ được chèn vào.)


    Return value:
        It returns an iterator pointing to the newly inserted element.
        !(Nó trả về một trình vòng lặp trỏ đến phần tử mới được chèn vào.)

*/


// Example 1:   insert(iterator,val);  
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string> v {"java"};  
    string str = "programs";  

    v.insert(v.begin() + 1, str);  
    for(int i=0; i< v.size(); i++)  
        cout << v[i] << " ";
        
    return 0;  
}  


// Example 2:   insert(iterator, n, val);
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string>  v {"C" , "Tutorials"};

    v.insert(v.begin() + 1, 2, "C");  
    for(int i=0; i<v.size(); i++)  
        cout << v[i] << " ";  

    return 0;  
}  


// Example 3:   insert(iterator, InputIterator first, InputIterator last);  
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    
    vector<int> v1 {1, 2, 3, 4, 5};  
    vector<int> v2 {6, 7, 8, 9, 10}; 

    v1.insert(v1.end(), v2.begin(), v2.begin() + 5);  
    // v1.insert(v1.end(), v2.begin(), v2.end()); 
    for(int i=0; i<v1.size(); i++)  
        cout << v1[i] << " ";  


    return 0;  
}  




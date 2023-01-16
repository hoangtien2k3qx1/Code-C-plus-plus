
/*  C++ Deque insert(): 

    C++ Deque insert() function inserts new element just before the specified position pos 
    and the size of the container increases by the number of elements are inserted. 
    Insertion of an element can be done either from front or from the back.


    Syntax
                    iterator insert(iterator pos, value_type val);  
                    insert(iterator pos, int n, value_type val);  
                    insert(iterator pos, InputIterator first,InputIterator last);  


    Parameter:
    pos: Position before which the new element is to be inserted.

    val: New value to be inserted.

    n: Number of times the value to be inserted.

*/

#include <iostream>  
#include<deque>  
using namespace std;  
int main()  
{  
    deque<string> language={"java",".net","C"};  
    deque<string>::iterator itr=language.begin();  

    language.insert(++itr,"C++");  
    for(itr=language.begin();itr!=language.end();++itr)  
        cout<<*itr<<" ";  

    cout << endl;

    language.insert(language.begin(), 2, "Tien");
    for(int i=0; i<language.size(); i++) { 
        cout << language[i] << " ";
    }


    return 0;  
}  



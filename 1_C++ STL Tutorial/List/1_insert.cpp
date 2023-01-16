
/*  C++ List insert():

    C++ List insert() function inserts a new element just before the specified position. 
    It increases the size of the list container by the number of elements added in the list.


    Syntax:
                insert( iterator pos, const value_type value);  
                insert( iterator pos, int n, const value_type value);  
                insert( iterator pos, InputIterator first, InputIterator last);  

    Parameter:
        pos: It defines the position before which the new element is to be inserted.

        value: The value to be inserted.

        n: Number of times the value to be occurred.

        ( first,last): It defines the range of the elements to be inserted at position pos.

    Return value
    It returns an iterator pointing to the newly constructed element.

*/

#include <iostream>  
#include<list>  
using namespace std;  
int main()  
{  
    list<int> li = {1, 2, 3, 4, 0};  
    list<int>::iterator itr = li.begin();  

    li.insert(li.end(), 5);  
    for(itr = li.begin(); itr != li.end(); ++itr)  
        cout << *itr << " ";


    return 0;  
}  
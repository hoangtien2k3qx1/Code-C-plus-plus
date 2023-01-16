
/*  C++ Vector erase(): 

    erase : tẩy xóa

    It deletes the specified elements pointed by the iterator


    Syntax: 
            v.erase(pos);  

            v.erase(start_iterator, end_iterator);  

    Parameter:
    pos: It defines the position of the element which is to be removed from the vector.
    (start_iterator,end_iterator) : It defines the range of the elements to be removed from the vector.


    Return value:
    It does not return any value.

*/

//Example 1:    v.erase(pos); 
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<char> v{'C','+','#'};  
    v.erase(v.begin() + 1);  
    for(int i=0;i<v.size();i++)  
    cout<<v[i] << " "; 
    return 0;  
}  


// Example 2:   v.erase(start_iterator,end_iterator);  
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string>  fruit{"mango","apple","strawbery","kiwi","banana"};  

    cout<<"fruit names are: \t";  
    for(int i=0; i<fruit.size(); i++)  
        cout<<fruit[i]<<" ";  

    cout << "\n";  

    fruit.erase(fruit.begin() + 1, fruit.begin() + 3);  
    cout << "After removing apple and strawbery fruits: \t";  
    for(int i=0; i<fruit.size(); i++)  
        cout<<fruit[i]<<" ";  


    return 0;  
}  
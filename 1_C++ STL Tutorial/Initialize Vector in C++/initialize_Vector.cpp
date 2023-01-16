
/*  There are four ways of initializing a vector in C++
    (có 4 cách để khởi tạo một vector trong c++)

        + By entering the values one-by-one
        + By using an overloaded constructor of the vector class
        + By the help of arrays
        + By using another initialized vector

    
*/


//! C1: By entering the values one-by-one: 
#include <iostream>  
#include <vector>  
using namespace std;  
int main()   
{  
    vector<int> vec;    
    vec.push_back(1);   
    vec.push_back(2);   
    vec.push_back(3);  
    vec.push_back(4);   
    vec.push_back(5);  
    vec.push_back(6);   
    vec.push_back(7);   
    vec.push_back(8);  
    vec.push_back(9);   
    vec.push_back(101);  
    for (int i = 0; i < vec.size(); i++)  
    {  
        cout << vec[i] << " ";   
    }  
    return 0;   
}  



//! C2: Using an overloaded constructor:
#include <iostream>  
#include <vector>  
using namespace std;  
int main()  
{  
    int elements = 12;   
    vector<int> vec(elements, 8);   
    for (int i = 0; i < vec.size(); i++)  
    {  
        cout << vec[i] << " \n";   
    }  
    return 0;   
}    



//! C3: By the help of arrays:
#include <iostream>  
#include <vector>  
using namespace std;  
int main()   
{  
    vector<int> vectr{9,8,7,6,5,4,3,2,1,0};   
    for (int i = 0; i < vectr.size(); i++)  
    {  
        cout << vectr[i] << " \n";   
    }  
    return 0;  
}  


//! C4: Using another initialized vector:
#include <iostream>  
#include <vector>  
using namespace std;  
int main()   
{  
    vector<int> vec_1{1,2,3,4,5,6,7,8};  
    vector<int> vec_2(vec_1.begin(), vec_1.end());  
    for (int i = 0; i < vec_2.size(); i++)  
    {  
        cout << vec_2[i] << " \n";   
    }  
    return 0;   
}  

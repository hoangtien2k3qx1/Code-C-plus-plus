
/*  C++ Vector rbegin(): The rbegin() stands for 'reverse beginning' and is used to point the last element of the vector.
    ( hàm này nó sẽ đảo phần tử đầu tiên xuống cuối dãy )
    Syntax: Consider a vector 'v' and syntax would be :

                reverse_iterator ritr=v.rbegin(); 




    Parameter:
    It does not contain any parameter.

    Return value:
    It returns a reverse iterator pointing to the last element of the vector.


*/


#include <iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<char> v{'j','a','v','a'};  

    vector<char>::reverse_iterator rtr;  
    for(rtr=v.rbegin(); rtr!=v.rend(); rtr++)  
        std::cout<< *rtr;  




    return 0;  
}  
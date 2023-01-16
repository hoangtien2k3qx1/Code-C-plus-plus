
/*  C++ Vector operator=():

    This function assigns new values to the vector container and replacing old ones.
    ( hàm này nhiệm vụ gán giái trị mới cho vector chứa giá trị cũ ) => hiểu đơn giản là gán giá trị vector 1 sang vector 2

    !Syntax: Consider two vectors 'v' and 'v1'. Syntax would be :
            v.operator = (v1);  

    
    Parameter:
    v1:v1 is a vector object.


    Return value:
    It returns *this.


*/


// #include<iostream>  
// #include<vector>  
// using namespace std;  
// int main()  
// {  
//     vector<char> v {'C','#'};  
//     vector<char> v1;  

//     v1.operator=(v);  
//     for(int i=0; i<v.size(); i++)  
//         std::cout << v[i] << " ";  



//     return 0;  
// }  






//! ////////////////////////////
#include<iostream>  
#include<vector>  
using namespace std;  
int main()  
{  
    vector<string> v{"java"};  
    vector<string> v1{".NET"};  

    cout<<"initially,value of v1 is :";  
    for(int i=0;i<v1.size();i++)  
        std::cout << v1[i];  
    
    cout<<'\n';  

    cout<<"Now, the value of vector v1 is :";  
    v1.operator=(v);  
    for(int i=0;i<v1.size();i++)  
        std::cout<<v1[i];  




    return 0;  
}  
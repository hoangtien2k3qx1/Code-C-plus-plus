
/*
    Syntax:

            iterator begin();                            //until C++ 11  
            iterator begin() const;                //until C++ 11  
            iterator begin() noexcept;              //since C++ 11  
            iterator begin() const noexcept;  //since C++ 11  


*/

#include <iostream>  
#include <set>  
  
using namespace std;  
  
int main ()  
{  
    set<string> myset= {"Java", "C++", "SQL"};  
    
    // show content:  
    cout<<"Contents of myset are: "<<endl;  
    for (set<string>::iterator it=myset.begin(); it!=myset.end(); ++it)  
        cout << *it<< '\n';  
  
    return 0;  
}  
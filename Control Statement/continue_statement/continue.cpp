
#include <iostream>  
using namespace std;  
int main()  
{  
     for(int i=1;i<=10;i++){      
            if(i==5){      
                continue;      // gặp lệnh continue thì bỏ qua giá trị đó và không xét giá trị đó tiếp
            }      
            cout<<i<<"\n";      
        }        
}  
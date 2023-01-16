
/*  C++ map at() Function:

    C++ map at() function is used to access the elements in the map with the given key value


*/

#include <iostream>  
#include <string>  
#include <map>  
  
using namespace std;  
  
int main ()  
{  
    map<int, string> mymap = {  
                    { 101, "" },  
                    { 102, "" },  
                    { 103, "" } };  
    
    mymap.at(101) = "Java";   
    mymap.at(102) = "Tien";  
    mymap.at(103) = "Point";  

    
        // prints value associated with key 101, i.e. Java  
    cout<<mymap.at(101) << endl;   
            // prints value associated with key 102, i.e T  
    cout<<mymap.at(102) << endl;  
            // prints value associated with key 103, i.e Point      
    cout<<mymap.at(103) << endl; 

    cout << endl; 

    for(map<int, string>::iterator itr = mymap.begin(); itr != mymap.end(); ++itr) {
        cout << itr->first << " " << itr->second << endl; 
    }
    

    cout << endl;
    
    for(auto x : mymap) {
        cout << x.first << " " << x.second << endl;
    }


    return 0;  
}  


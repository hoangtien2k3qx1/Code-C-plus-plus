
//! copy dữ liệu từ mảng sang vector thông dụng nhất:
/*
    syntax:

    !        vector<datatype> name_ (arr , arr + size);



    ### 5 methods copy the array to the vector:
   create: vector<int> vt;
               int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
               int size= sizeof(array) / sizeof(int);
               
+ // Method 1: Copy the array to the vector using back_inserter.
{
        copy(&array[0], &array[size], back_inserter(vt);
}
+ // Method 2: Same as 1 but pre-extend the vector by the size of the array using reserve
{
        vt.reserve(vt.size() + array);
        copy(&array[0], &array[size], back_inserter(vt));
}
+ // Method 3: Memcpy
{
        vt.resize(vt.size() + array);
        memcpy(&vt[vt.size() - array], &array[0], size* sizeof(int));
}
+ // Method 4: vector::insert
{
        vt.insert(vt.end(), &array[0], &array[size]);
}
+ // Method 5: vector + vector
{
        vector<int> v1(&array[0], &array[size]);
        vt.insert(vt.end(), v1.begin(), v1.end());
}
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr)/sizeof(arr[0]);

    // c1
    vector<int> vt (arr , arr + size);

    for(auto x : vt) {
        cout << x << " ";
    }

    cout << "\n_________________________________\n";

    // C2
    vector<int> vec;
    vector<int> q (&arr[0], &arr[size]);
    vec.insert(vec.end(), q.begin(), q.end());

    for(auto x : vec) {
        cout << x << " ";
    }
    

    return 0;
}
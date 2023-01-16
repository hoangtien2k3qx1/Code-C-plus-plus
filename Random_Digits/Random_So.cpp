
/*  https://nguyenvanhieu.vn/sinh-so-ngau-nhien-trong-c-cpp/#:~:text=2.-,Sinh%20s%E1%BB%91%20ng%E1%BA%ABu%20nhi%C3%AAn%20trong%20C%2FC%2B%2B%20v%E1%BB%9Bi%20srand(),ra%20c%C3%A1c%20s%E1%BB%91%20kh%C3%A1c%20nhau.
    
    Tuy nhiên, hàm rand() này sẽ không hề random ra các số mới khi bạn chạy code ở các lần sau. 
    Nghĩa là, kết quả của code trên ở mọi lần chạy sẽ đều random ra 5 số giống nhau. 
    Bạn có thể thử chạy đoạn code trên nhiều lần để kiếm chứng.

*/

#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int r;
    for(int i = 0; i < 5; i++){
        r = rand();
        printf("Rand %d is %d\n", i, r);
    }    
}
 




//!  Số ngẫu nhiên trong C++ với hàm:    srand()
/*
    Để tạo ra các số ngẫu nhiên khác nhau tại mọi thời điểm chạy code, chúng ta sẽ thêm hàm srand() và truyền vào một tham số seed kiểu int. 
    Tham số này thay đổi thì hàm srand() sẽ sinh ra các số khác nhau.    

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(){
    int r;
    srand((int)time(0));
    for(int i = 0; i < 5; ++i){
        r = rand();
        printf("Rand %d is %d\n",i, r);
    }    
}




// Sinh số ngẫu nhiên trong đoạn từ [a, b]: 
/*
    Có thể các bạn thừa biết, phép toán chia dư (%) của mọi số bất kỳ(a) cho một số b cố định: a % b sẽ cho ra giá trị thuộc đoạn [0, b-1]. 
    Ta sẽ lợi dụng tính chất này để sinh số ngẫu nhiên trong đoạn [minN, maxN] như sau:

    syntax:     int r = minN + rand() % (maxN + 1 - minN)

    Ex:  
        int r = 5 + rand() % (10 + 1 - 5)
        ! Hay viết gọn hơn
        int r = 5 + rand() % 6

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
 
int main(){
    srand((int)time(0));
    int r;
    for(int i = 0; i < 1000; ++i){
        r = random(1,100);
        printf("%d\t",r);
    }    
}



// Sinh số thực ngẫu nhiên trong đoạn [min, max]

 
float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}



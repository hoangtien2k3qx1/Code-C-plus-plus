
/*  syntax: 

    switch(expression){      
    case value1:      
    //code to be executed;      
    break;    
    case value2:      
    //code to be executed;      
    break;    
    ......      
        
    default:       
    //code to be executed if all cases are not matched;      
    break;    
    }    

*/


// Nhập vào month và year. Kiểm tra xem tháng đó có bao nhiêu ngày.

#include<stdio.h>
#include<stdbool.h>

bool CheckNamNhuan(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int ngay(int month, int year) {
    int NgayTrongNam;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            NgayTrongNam = 31;
            break;
        case 4: case 6: case 9: case 11:
            NgayTrongNam = 30;
            break;
        default:
            return (CheckNamNhuan(year))?(NgayTrongNam = 29):(NgayTrongNam = 28);
    }
    return NgayTrongNam;
}

int main(){
    int month, year;
    printf ("Nhap vao month = ");
    scanf ("%d", &month);
    printf ("Nhap vao year = ");
    scanf ("%d", &year);
    printf ("Co %d ngay!", ngay(month, year));
    return 0;
}
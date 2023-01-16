
/*
    Hàm memset() trong C++ được sử dụng để sao chép một ký tự đơn lẻ trong một 
    khoảng nhất định vào một đối tượng.

    syntax:
            void * memset(void * ptr, int value, size_t num);

*/

#include <stdio.h>
#include <string.h>
struct {
  char name[40];
  int age;
} person, person_copy;
int main ()
{
    char myname[] = "Nguyen Hoang Nam";
    /* su dung ham memcpy de sao chep chuoi: */
    memcpy ( person.name, myname, strlen(myname)+1 );
    person.age = 46;
    /* su dung ham memcpy de sao chep struct: */
    memcpy ( &person_copy, &person, sizeof(person) );
    printf ("person_copy = %s, %d \n", person_copy.name, person_copy.age );
    return 0;
}
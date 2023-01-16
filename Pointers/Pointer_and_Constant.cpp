


#include <iostream>
#include <cstring>
using namespace std;

int main() {

	char str[] = "Le Tran Dat";
	const char *p_str = str;
	
	// for(int i = 0; i < strlen(str); i++)
	// {
	// 	*(p_str + i) = ' ';
	// }
	
	cout << p_str << endl;

	return 0;
}

/*
	Sau đó bạn hãy nhập từ bàn phím mảng n phần tử các SinhVien (mảng này được cấp phát động) 
	và hiển thị ra màn hình thông tin của sinh viên có điểm cao nhất

*/

#include<iostream>
using namespace std;

typedef struct Student {
	string name;
	int age;
	int score;
} Student;

Student *alloc_arr_integer(int len) {
    Student *students = new Student[len];
}

Student Information(int n, Student *students) {
    Student s = students[0];
	for (int i = 1; i < n; i++) {
		if ((students->score + i) > s.score)
			s = *(students + i);
	}
	delete[] students;
	cout << "STT" << "\t\t" << "Name" << "\t\t\t" << "Age" << "\t\t\t" << "Score" << endl;
	for(int i = 0; i < n; i++) {
		cout << i + 1 << "\t\t" << s.name << "\t\t\t" << s.age << "\t\t\t" << s.score << endl;
	}
}

int main() {
	int n; cout << "Enter the elements: "; cin >> n;
    Student *students = alloc_arr_integer(100);
	for (int i = 0; i < n; i++) {
		cout << "Enter the Name, Age, Score " << "["<<i + 1<<"]" << endl;
		cin.ignore();
		cin >> (students[i].name) >> (students[i].age) >> (students[i].score);
	}
    Information(n, &*students);
	return 0;
}
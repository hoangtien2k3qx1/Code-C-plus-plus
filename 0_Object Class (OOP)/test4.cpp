
#include <iostream>
#include <vector>
using namespace std;

class Student
{
	private:
		string name; 
		double math; 
		double physic; 
		double chemistry; 
		public:
			Student(){}
			Student(string name, double math, double physic, double chemistry): name(name), math(math), physic(physic), chemistry(chemistry){} 
			
			double getMath(){ return math; } 

			double getPhysic(){ return physic; }

			double getChemistry(){ return chemistry; }
			
			void display()
			{
				cout << "Name: "            << name << endl;
				cout << "Point math: "      << math << endl;
				cout << "Point physic: "    << physic << endl;
				cout << "Point chemistry: " << chemistry << endl;
				cout << "Average: "         << avgPoint() << endl;
			}
			
			
			double avgPoint()
			{
				return (math + physic + chemistry) /3;
			}
			
			
			static vector<Student> getStudentMaxAvg(vector<Student> vt)
			{
				vector<Student> student;
				student.push_back(vt[0]);
				
				for(int i=1; i< vt.size(); i++)
				{
					if(vt[i].avgPoint() > student[0].avgPoint())
					{
						student.clear();
						student.push_back(vt[i]);
					}
					else if(vt[i].avgPoint() == student[0].avgPoint())
					{
						student.push_back(vt[i]);
					}
				}
				return student;
			}
			
			
			static vector<Student> getStudentMaxMath(vector<Student> vt)
			{
				vector<Student> student;
				student.push_back(vt[0]);
				
				for(int i=1; i< vt.size(); i++)
				{
					if(vt[i].getMath() > student[0].getMath())
					{
						student.clear();
						student.push_back(vt[i]);
					}
					else if(vt[i].getMath() == student[0].getMath())
					{
						student.push_back(vt[i]);
					}
				}
				return student;
			}
			
			
			static vector<Student> getStudentMaxPhysic(vector<Student> vt)
			{
				vector<Student> student;
				student.push_back(vt[0]);
				
				for(int i=1; i< vt.size(); i++)
				{
					if(vt[i].getPhysic() > student[0].getPhysic())
					{
						student.clear();
						student.push_back(vt[i]);
					}
					else if(vt[i].getPhysic() == student[0].getPhysic())
					{
						student.push_back(vt[i]);
					}
				}
				return student;
			}
			
			
			static vector<Student> getStudentMaxChemistry(vector<Student> vt)
			{
				vector<Student> student;
				student.push_back(vt[0]);
				
				for(int i=1; i< vt.size(); i++)
				{
					if(vt[i].getChemistry() > student[0].getChemistry())
					{
						student.clear();
						student.push_back(vt[i]);
					}
					else if(vt[i].getChemistry() == student[0].getChemistry())
					{
						student.push_back(vt[i]);
					}
				}
				return student;
			}
};

int main()
{
    vector<Student>vt1;
    
    vt1.push_back(Student("Mr.The", 2, 3, 1));  
    vt1.push_back(Student("Mr.End", 4, 6, 8));  

    vector<Student> vt2 = Student::getStudentMaxAvg(vt1); // gọi hàm getStudentMaxAvg() của vector vt1 và gán cho vector vt2
    

    /*for(int i=0;i<Student::getStudentMaxAvg(vt1).size();i++)
    {
        Student::getStudentMaxAvg(vt1)[i].display(); // cách viết này gọi hàm nhiều lần mỗi vòng lặp
                                                     // làm chậm chương trình, hạn chế dùng
    }*/


    for(int i=0;i<vt2.size();i++)
    {
        vt2[i].display();
    }


    return 0;
}
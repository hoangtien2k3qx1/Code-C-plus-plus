
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
	string name;
	int age;
	string add;
	string tel;
	string sex;
public:
	Person(string name, int age, string add, string tel, string sex) 
    : name(name), age(age), add(add), tel(tel), sex(sex) {}
	string getName() {return name;}
    int getAge() {return age;}
    string getAdd() {return add;}
    string getSex() {return sex;}
    string getTel() {return tel;}
	virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Add: " << add << endl;
        cout << "Tel: " << tel << endl;
    }
	virtual long salary() = 0;
	static vector<Person*> findPerson(vector<Person*> p) {
        vector<Person*> v;
        for(int i=0; i<p.size(); i++) {
            if (p[i]->add == "HN") {
                v.push_back(p[i]);
            }
        }
        return v;
    }
};

class EmployeePT : public Person {
private:
    int hour;
    long money;
public:
    EmployeePT(string name, int age, string add, string tel, string sex, int hour, long money)
    : Person(name, age, add, tel, sex), hour(hour), money(money) {}
    int getHour() {return hour;}
    long getMoney() {return money;}
    long salary() {return long(hour) * money;}
    void display() {
        cout << "Employee Part Time" << endl;
        Person::display();
        cout << "Hour: " << hour << endl;
		cout << "Money: " << money << endl;
		cout << "Salary: " << salary() << endl;
    }
    static vector<EmployeePT> getMaxSalary(vector<EmployeePT> pt) {
		long max = pt[0].salary();
		for (int i = 1; i < pt.size(); i++) {
			if (pt[i].salary() > max) {
				max = pt[i].salary();
			}
		}
		vector<EmployeePT> v;
		for (int i = 0; i < pt.size(); i++) {
			if (pt[i].salary() == max) {
				v.push_back(pt[i]);
			}
		}
		return v;
	}
};

class EmployeeFT : public Person {
private:
	int day;
	long money;
public:
	EmployeeFT(string name, int age, string add, string tel, string sex, int day, long money) : Person(name, age, add, tel, sex), day(day), money(money) {}
	int getDay()
	{
		return day;
	}
	long getMoney()
	{
		return money;
	}
	long salary()
	{
		return long(day) * money;
	}
	void display()
	{
		cout << "Employee Full Time" << endl;
		Person::display();
		cout << "Day: " << day << endl;
		cout << "Money: " << money << endl;
		cout << "Salary: " << salary() << endl;
	}
	static vector<EmployeeFT> getMaxSalary(vector<EmployeeFT> ft)
	{
		long max = ft[0].salary();
		for (int i = 1; i < ft.size(); i++)
		{
			if (ft[i].salary() > max)
			{
				max = ft[i].salary();
			}
		}
		vector<EmployeeFT> v;
		for (int i = 0; i < ft.size(); i++)
		{
			if (ft[i].salary() == max)
			{
				v.push_back(ft[i]);
			}
		}
		return v;
	}
};

int main()
{
    Person * person[4];
    person[0] = new EmployeePT("Tien", 19, "HN", "082800", "Male", 3, 18000);
    person[1] = new EmployeeFT("Chung", 25, "HCM", "09842", "Female", 7, 15000);
    person[2] = new EmployeePT("John", 30, "TH", "01234", "Male", 6, 3000);
    person[3] = new EmployeeFT("sasha", 18, "HCM", "09842", "Female", 9, 1200);

    vector<Person*> p;

    for(int i=0; i<4; i++) {
        p.push_back(person[i]);
    }

    vector<Person*> per = Person::findPerson(p); // vector<Person*>per(Person::findPerson(p)); viết như thế này cũng được
    for(int i=0; i<per.size(); i++) {
        per[i]->display();
        cout << "_______________________" << endl;
    }

// this part belong EmployeePT
    vector<EmployeePT> pt;
    pt.push_back(EmployeePT("Tien", 19, "HN", "082800", "Male", 3, 18000));
    pt.push_back(EmployeePT("John", 30, "TH", "01234", "Male", 6, 3000));

    vector<EmployeePT> runpt = EmployeePT::getMaxSalary(pt);

    for(int i=0; i<runpt.size(); i++) {
        runpt[i].display();
        cout << "__________________________________________________" << endl;
    }

    vector<EmployeeFT> ft;
    
    ft.push_back(EmployeeFT("Chung", 25, "HCM", "09842", "Female", 7, 15000));
    ft.push_back(EmployeeFT("sasha", 18, "HCM", "09842", "Female", 9, 1200));

    vector<EmployeeFT> runft = EmployeeFT::getMaxSalary(ft);

    for(int i=0; i<runft.size(); i++) {
        runft[i].display();
        cout << endl;
    }

    return 0;
}
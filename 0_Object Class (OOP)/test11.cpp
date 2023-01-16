
#include<bits/stdc++.h>
using namespace std;

class Book {
private:
	string nameBook;
	string nameAuthor;
	int numberBook;
public:
	Book() {}
	Book(string nameBook, string nameAuthor, int numberBook) {
		this->nameBook = nameBook;
		this->nameAuthor = nameAuthor;
		this->numberBook = numberBook;
	}

	void display() {
		cout << "Name Book: " << this->nameBook << endl;
		cout << "Name Author: " << this->nameAuthor << endl;
		cout << "Number Book: " << this->numberBook << endl;
	}
	int getNumberBook() {
		return this->numberBook;
	}
	string getNameBook() {
		return this->nameBook;
	}
	string getNameAuthor() {
		return this->nameAuthor;
	}
};

class Person {
private:
	string name;
	int age;
	string add;
	vector<Book> vb;
public:
	Person() {}
	Person(string name, int age, string add, vector<Book> vb) : name(name), age(age), add(add), vb(vb) {}
	string getName() {
		return name;
	}
	int getAge(){
		return age;
	}
	string getAdd() {
		return add;
	}
	vector<Book> getVB() {
		return vb;
	}
	virtual long moneyPay() = 0;
	virtual void display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Add: " << add << endl;
		cout << "List Book Borrowed:" << endl;
		for (int i = 0; i < vb.size(); i++) {
			vb[i].display();
		}
		cout << "Money Pay: " << moneyPay() << endl;
	}
	static void sortPersonAge(vector<Person*> &vt) {
		for (int i = 0; i < vt.size() - 1; i++) {
			for (int j = i + 1; j < vt.size(); j++) {
				if (vt[i]->getAge() > vt[j]->getAge()) {
					swap(vt[i], vt[j]);
				}
			}
		}
	}
	static vector<int> getListAge(vector<Person*> vt) {
		vector<int> str;
		for (int i = 0; i < vt.size(); i++) {
			if (!(find(str.begin(), str.end(), vt[i]->getAge()) != str.end())) {
				str.push_back(vt[i]->getAge());
			}
		}
		return str;
	}
	static vector<Book> getMaxBookBorrowed(vector<Person*> vp, vector<Book> vB) {
		vector<int> count(vB.size(), 0);
		for (int i = 0; i < vB.size(); i++) {
			for (int j = 0; j < vp.size(); j++) {
				vector<Book> b(vp[j]->getVB());
				for (int k = 0; k < b.size(); k++) {
					if (vB[i].getNameBook() == b[k].getNameBook()) {
						count[i]++;
					}
				}
			}
		}
		int max = *max_element(count.begin(), count.end());
		vector<Book> res;
		for (int i = 0; i < vB.size(); i++) {
			if (count[i] == max) {
				res.push_back(vB[i]);
			}
		}
		return res;
	}
};

class Children : public Person {
public:
	Children() {}
	Children(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
	long moneyPay() {
		return this->getVB().size() * 5000;
	}
	void display() {
		cout << "Children!" << endl;
		Person::display();
	}
};

class Adult : public Person {
public:
	Adult() {}
	Adult(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
	long moneyPay() {
		return this->getVB().size() * 10000;
	}
	void display() {
		cout << "Adult!" << endl;
		Person::display();
	}
};

int main() {
	Book a("Pride and Prejudice", "Jane Austen", 100);
	Book b("Crime and Punishment", "Fyodor Dostoyevsky", 1000);

	vector<Book> all;
	all.push_back(a);
	all.push_back(b);

	vector<Book> vb, v;
	v.push_back(b);
	v.push_back(a);
	vb.push_back(a);

	Person* x[4];
	x[0] = new Children("a", 9, "HN", vb);
	x[1] = new Adult("b", 20, "NM", vb);
	x[2] = new Children("c", 8, "HN", v);
	x[3] = new Children("d", 9, "NB", v);

	vector<Person*> p;
	p.push_back(x[0]);
	p.push_back(x[1]);
	p.push_back(x[2]);
	p.push_back(x[3]);

	for (int i = 0; i < p.size(); i++) {
		p[i]->display();
	}

	Person::sortPersonAge(p);
	
	vector<int> str(Person::getListAge(p));

	vector<Book> res(Person::getMaxBookBorrowed(p, all));

	return 0;
}
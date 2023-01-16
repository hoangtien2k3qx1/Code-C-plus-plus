
#include<iostream>
#include<vector>
using namespace std;

class Subject {
    private:
        string nameSub;
        double point;
        int numberCredit;
        long money;
    public:
        Subject(string nameSub, double point, int numberCredit, long money) 
        : nameSub(nameSub), point(point), numberCredit(numberCredit), money(money) {}
        string getNameSub() {
            return nameSub;
        }
        double getPoint() {
            return point;
        }
        int getNumberCredit()  {
            return numberCredit;
        }
        long getMoney() {
            return money;
        }
        void display() {
            cout << "Name Subject: " << nameSub << endl;
            cout << "Number Credit: " << numberCredit << endl;
            cout << "Money Of One Credit: " << money << endl;
        }
};

class Student {
    private:
        string id;
        string name;
        vector<Subject> s;
    public:
        Student(string id, string name, vector<Subject> s) : id(id), name(name), s(s) {}
        string getId() {
            return id;
        }
        string getName() {
            return name;
        }
        vector<Subject> getS() {
            return s;
        }
        long getSumMoney() {
            long sum = 0;
            for(int i=0; i<s.size(); i++) {
                sum += s[i].getNumberCredit() * s[i].getMoney();
            }
            return sum;
        }
        double avgPoint() {
            double point = 0;
            int sum = 0;
            for(int i=0; i<s.size(); i++) {
                point += s[i].getNumberCredit() * s[i].getPoint();
                sum += s[i].getNumberCredit();
            }
            return point/sum;
        }
        void display() {
            cout << "Id: " << id << endl;
            cout << "Name Student: " << name << endl;
            cout << "List Subject" << endl;
            for (int i=0; i<s.size(); i++) {
                s[i].display();
            }
            cout << "Sum Money Have To Pay: " << getSumMoney() << endl;
            cout << "Average Point: " << avgPoint() << endl;
        }
};

int main() {
    vector<Subject> v;
    v.push_back(Subject("Hoang Anh Tien", 2, 5, 30));
    v.push_back(Subject("Tien Anh Hoang", 4, 1, 14));
    v.push_back(Subject("Tien Dai Ca", 12, 4, 2003));

    vector<Student> s;
    s.push_back(Student("72DCHT21", "Tien Dai Ca", v));
    
    for(int i=0; i<v.size(); i++) {
        s[i].display();
    }

    return 0;
}
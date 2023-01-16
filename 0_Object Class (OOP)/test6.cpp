
#include<iostream>
#include<vector>
using namespace std;

class Transport {
private:
    string manufacturer;
    string name;
    int year;
    int speed;
public:
    Transport() {}
    Transport(string m, string n, int y, int s) : manufacturer(m), name(n), year(y), speed(s) {}
    string getManufacturer() {
        return manufacturer;
    }
    string getName() {
        return name;
    }
    int getYear() {
        return year;
    }
    int getSpeed() {
        return speed;
    }
    void display() {
        cout << "Manufacturer: " << manufacturer  << endl;
        cout << "Name: " << name << endl;
        cout << "Year Of Manufacturer: " << year << endl;
        cout << "Speed: " << speed << endl;
    }
};

class Car : public Transport {
private:
    int numberSeat;
    string engineType;
public:
    Car() {}
    Car(string manufacturer, string name, int year, int speed, int numberSeat, string engineType) 
    : Transport(manufacturer, name, year, speed), numberSeat(numberSeat), engineType(engineType) {}
    int getNumberSeat() {
        return numberSeat;
    }
    string getEngineType() {
        return engineType;
    }
    double getSpeedBasic() {
        return this->getSpeed()/numberSeat;
    }
    void display() {
        Transport::display();
        cout << "Number Seat: " << numberSeat << endl;
        cout << "Engine Type: " << engineType << endl;
        cout << "Speed Basic: " << getSpeedBasic() << endl;
    }

    static vector<Car> getCarHaveMaxSpeedBasic(vector<Car> vt) {
        vector<Car> v;
        double max = vt[0].getSpeedBasic();
        for(int i=1; i<vt.size(); i++) {
            if (vt[i].getSpeedBasic() > max) {
                v.clear();
                max = vt[i].getSpeedBasic();
                v.push_back(vt[i]);
            }
        }
        return v;
    }
    
    static vector<Car> getCarHaveMaxSeat(vector<Car> vt)
	{
		vector<Car> v;
		double max = vt[0].getNumberSeat();
		for (int i = 0; i < vt.size(); i++) {
			if (vt[i].getNumberSeat() > max) {
			    v.clear();
				max = vt[i].getNumberSeat();
				v.push_back(vt[i]);
			}
		}
		return v;
	}
};

int main()
{
    system("cls");

    vector<Car> vt;

    vt.push_back(Car("Viet Nam", "VinFast1", 2021, 300, 4, "diesel"));
    vt.push_back(Car("Viet Nam", "VinFast2", 2022, 400, 2, "diesel"));

    for(int i = 0; i < vt.size(); i++)
    {
        vt[i].display();
        cout << "=============================================" << endl;
    }


    for(int i = 0; i<Car::getCarHaveMaxSpeedBasic(vt).size(); i++)
    {
        Car::getCarHaveMaxSpeedBasic(vt)[i].display();
    }

    cout << "__________________________________________________" << endl;

    for(int i = 0; i < Car::getCarHaveMaxSeat(vt).size(); i++)
    {
        Car::getCarHaveMaxSeat(vt)[i].display();
    }

    cout << endl;
    system("pause");
}
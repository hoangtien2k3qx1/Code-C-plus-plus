
#include <iostream>
#include<vector>
using namespace std;

class Food {
private:
	string name;
	double price;
public:
	Food(){}
	Food(string name, double price)
	{
		this->name = name;
		this->price = price;
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
	void setPrice(double price)
	{
		this->price = price;
	}
	double getPrice()
	{
		return price;

	}
    void display()
	{
		cout << "Name: " << name << endl;
		cout << "Price: " << price << endl;
	}
};

class CannedFood : public Food {
private:
	int numberBox;
public:
	CannedFood() {}
	CannedFood(string name, double price, int numberBox) : Food(name, price)
	{
		this->numberBox = numberBox;
	}
	int getNumberBox()
	{
		return numberBox;
	}
	void display()
	{
		cout << "Name: " << Food::getName() << endl;
		cout << "Price: " << Food::getPrice() << endl;
		cout << "Number box: " << this->numberBox << endl;
	}
	static void sortNumberBox(vector<CannedFood> &vt)
	{
		for (int i = 0; i < vt.size() - 1; i++)
		{
			for (int j = i + 1; j < vt.size(); j++)
			{
				if (vt[j].numberBox < vt[i].numberBox)
				{
					swap(vt[j], vt[i]);
				}
			}
		}
	}
};

class NonCFood : public Food {
private:
	double weight;
public:
	NonCFood() {}
	NonCFood(string name, double price, double weight) : Food(name, price)
	{
		this->weight = weight;
	}
	void display()
	{
		cout << "Name: " << Food::getName() << endl;
		cout << "Price: " << Food::getPrice() << endl;
		cout << "Weight: " << this->weight << endl;
	}
	double getWeight()
	{
		return weight;
	}
	static void sortWeight(vector<NonCFood>& vt)
	{
		for (int i = 0; i < vt.size() - 1; i++)
		{
			for (int j = i + 1; j < vt.size(); j++)
			{
				if (vt[j].weight < vt[i].weight)
				{
					swap(vt[j], vt[i]);
				}
			}
		}
	}
};

int main()
{
	Food f("Ca", 15);
	f.display();

	cout << endl;
	
	vector<CannedFood> c;
	c.push_back(CannedFood("Ca1", 16, 11));
	c.push_back(CannedFood("Ca1", 16, 12));
	c.push_back(CannedFood("Ca1", 16, 10));
	
	CannedFood::sortNumberBox(c);
	for(int i=0; i< c.size(); i++)
	{
		c[i].display();
		cout << endl;
	}
	cout << endl;
	
	vector<NonCFood> n;
	n.push_back(NonCFood("Ca2", 17, 5));
	n.push_back(NonCFood("Ca2", 17, 7));
	n.push_back(NonCFood("Ca2", 17, 6));
	
	NonCFood::sortWeight(n);
	for(int i=0; i< n.size(); i++)
	{
		n[i].display();
		cout << endl;
	}
}
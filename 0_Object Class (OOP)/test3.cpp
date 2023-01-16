
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Card {
private:
    string nameBook;
    string nameAuthor;
    int numberBook;
public:
    Card() {}

    Card(string nameBook, string nameAuthor, int numberBook) {
        this->nameBook = nameBook;
        this->nameAuthor = nameAuthor;
        this->numberBook = numberBook;
    }

    void display() {
        cout << "Name Book: " << this->nameBook << endl;
        cout << "Name Author: " << this->nameAuthor << endl;
        cout << "Number Book: " << this->numberBook << endl;
    }

    int getNumBook() {
        return this->numberBook;
    }

    static void sortCards(vector<Card> &cards) {
        for(int i = 0; i < cards.size() - 1; i++) {
            for(int j = i + 1; j < cards.size(); j++) {
                if (cards[i].getNumBook() > cards[j].getNumBook()) {
                    swap(cards[i], cards[j]);
                }
            }
        }
    }

};


int main() {
    system("cls");

    vector<Card> cards;
	cards.push_back(Card("Cuu Am Chan Kinh", "Duong Qua", 1)); // truyền dữ liệu vào Constructor
	cards.push_back(Card("Kinh phat", "Hong dao ", 4));
	cards.push_back(Card("Kinh ta dao", "Hong hong ", 2));
	cards.push_back(Card("Kinh kong", "Hong hi ", 3));

	Card::sortCards(cards);

	for(auto x : cards) {
		x.display();
	}
    
    cin.get();
    return 0;
}

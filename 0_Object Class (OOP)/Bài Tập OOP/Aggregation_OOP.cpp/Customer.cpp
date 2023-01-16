
#include<iostream>
#pragma once
using namespace std;

class Customer {
private:
    int id;
    string name;
    int discount;
public:
    Customer() {
        
    }
    Customer(int id, string name, int discount) {
        this->id = id;
        this->name = name;
        this->discount = discount;
    }
    int getId() {
        return id;
    }
    void setName(string name) {
        this->name = name;
    } 
    string getName() {
        return this->name;
    }
    void setDiscount(int discount) {
        this->discount = discount;
    }
    int getDiscount() {
        return discount;
    }
};
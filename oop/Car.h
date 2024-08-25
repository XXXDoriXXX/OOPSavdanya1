#pragma once

#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    string marka;
    int power;
    float price;

public:
    Car();
    Car(string m, int p, float pr);
    Car(const Car& other);
    ~Car();
    string getMarka();
    int getPower();
    float getPrice();
    void setMarka(string m);
    void setPower(int p);
    void setPrice(float pr);
    void printcar();
    Car& init();
};

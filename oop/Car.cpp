#include "Car.h"
Car::Car() : marka("Unknown"), power(0), price(0.0f) {
    cout << "��������� ����������� ��� ��������� ��� ��'���� " << this << endl;
}
Car::Car(string m, int p, float pr) : marka(m), power(p), price(pr) {
    cout << "��������� ����������� � ����������� ��� ��'���� " << this << endl;
}
Car::Car(const Car& other) : marka(other.marka), power(other.power), price(other.price) {
    cout << "��������� ����������� ��������� ��� ��'���� " << this << endl;
}
Car::~Car() {
    cout << "��������� ���������� ��� ��'���� " << this << endl;
}
string Car::getMarka()  { return marka; }
int Car::getPower() { return power; }
float Car::getPrice()  { return price; }
void Car::setMarka(string m) { marka = m; }
void Car::setPower(int p) { power = p; }
void Car::setPrice(float pr) { price = pr; }
void Car::printcar()  {
    cout << "Marka: " << marka << endl;
    cout << "Power: " << power << endl;
    cout << "Price: " << price << endl;
}
Car& Car::init() {
    cout << "������ ����� ���������: ";
    cin.ignore();
    getline(cin, marka);
    cout << "������ ��������� ���������: ";
    cin >> power;
    cout << "������ ���� ���������: ";
    cin >> price;
    return *this;
}
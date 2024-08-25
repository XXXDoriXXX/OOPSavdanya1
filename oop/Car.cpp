#include "Car.h"
Car::Car() : marka("Unknown"), power(0), price(0.0f) {
    cout << "Викликано конструктор без параметрів для об'єкта " << this << endl;
}
Car::Car(string m, int p, float pr) : marka(m), power(p), price(pr) {
    cout << "Викликано конструктор з параметрами для об'єкта " << this << endl;
}
Car::Car(const Car& other) : marka(other.marka), power(other.power), price(other.price) {
    cout << "Викликано конструктор копіювання для об'єкта " << this << endl;
}
Car::~Car() {
    cout << "Викликано деструктор для об'єкта " << this << endl;
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
    cout << "Введіть марку автомобіля: ";
    cin.ignore();
    getline(cin, marka);
    cout << "Введіть потужність автомобіля: ";
    cin >> power;
    cout << "Введіть ціну автомобіля: ";
    cin >> price;
    return *this;
}
#include <iostream>
#include <Windows.h>
#include "Car.h"

using namespace std;

void showMenu() {
    cout << "Меню:" << endl;
    cout << "1. Додати автомобіль" << endl;
    cout << "2. Показати всі автомобілі" << endl;
    cout << "3. Редагувати автомобіль" << endl;
    cout << "4. Видалити автомобіль" << endl;
    cout << "5. Вийти" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int maxCars = 5;  
    Car cars[maxCars]; 
    int carCount = 0;  
    int choice;

    do {
        showMenu();
        cout << "Виберіть опцію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (carCount < maxCars) {
                string marka;
                int power;
                float price;

                

                cars[carCount].init();  
                carCount++;
               
                cout << "Автомобіль додано!" << endl;
            }
            else {
                cout << "Масив автомобілів заповнений!" << endl;
            }
            break;
        }
        case 2: {
            if (carCount > 0) {
                for (int i = 0; i < carCount; i++) {
                    cout << "Автомобіль #" << (i + 1) << ":" << endl;
                    cars[i].printcar();
                }
            }
            else {
                cout << "Немає доданих автомобілів." << endl;
            }
            break;
        }
        case 3: {
            int carIndex;
            cout << "Введіть номер автомобіля для редагування (1-" << carCount << "): ";
            cin >> carIndex;

            if (carIndex >= 1 && carIndex <= carCount) {
                string marka;
                int power;
                float price;

                cout << "Введіть нову марку (або '-' для пропуску): ";
                getline(cin, marka);
                if (marka != "-") cars[carIndex - 1].setMarka(marka);

                cout << "Введіть нову потужність (або -1 для пропуску): ";
                cin >> power;
                if (power != -1) cars[carIndex - 1].setPower(power);

                cout << "Введіть нову ціну (або -1 для пропуску): ";
                cin >> price;
                if (price != -1) cars[carIndex - 1].setPrice(price);

                cout << "Автомобіль відредаговано!" << endl;
            }
            else {
                cout << "Неправильний номер автомобіля." << endl;
            }
            break;
        }
        case 4: {
            int carIndex;
            cout << "Введіть номер автомобіля для видалення (1-" << carCount << "): ";
            cin >> carIndex;

            if (carIndex >= 1 && carIndex <= carCount) {
                for (int i = carIndex - 1; i < carCount - 1; i++) {
                    cars[i] = cars[i + 1]; cars[i + 1].~Car();
                }
                carCount--;
                cout << "Автомобіль видалено!" << endl;
            }
            else {
                cout << "Неправильний номер автомобіля." << endl;
            }
            break;
        }
        case 5:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 5);

    return 0;
}

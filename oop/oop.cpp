#include <iostream>
#include <Windows.h>
#include "Car.h"

using namespace std;

void showMenu() {
    cout << "����:" << endl;
    cout << "1. ������ ���������" << endl;
    cout << "2. �������� �� ��������" << endl;
    cout << "3. ���������� ���������" << endl;
    cout << "4. �������� ���������" << endl;
    cout << "5. �����" << endl;
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
        cout << "������� �����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (carCount < maxCars) {
                string marka;
                int power;
                float price;

                

                cars[carCount].init();  
                carCount++;
               
                cout << "��������� ������!" << endl;
            }
            else {
                cout << "����� ��������� ����������!" << endl;
            }
            break;
        }
        case 2: {
            if (carCount > 0) {
                for (int i = 0; i < carCount; i++) {
                    cout << "��������� #" << (i + 1) << ":" << endl;
                    cars[i].printcar();
                }
            }
            else {
                cout << "���� ������� ���������." << endl;
            }
            break;
        }
        case 3: {
            int carIndex;
            cout << "������ ����� ��������� ��� ����������� (1-" << carCount << "): ";
            cin >> carIndex;

            if (carIndex >= 1 && carIndex <= carCount) {
                string marka;
                int power;
                float price;

                cout << "������ ���� ����� (��� '-' ��� ��������): ";
                getline(cin, marka);
                if (marka != "-") cars[carIndex - 1].setMarka(marka);

                cout << "������ ���� ��������� (��� -1 ��� ��������): ";
                cin >> power;
                if (power != -1) cars[carIndex - 1].setPower(power);

                cout << "������ ���� ���� (��� -1 ��� ��������): ";
                cin >> price;
                if (price != -1) cars[carIndex - 1].setPrice(price);

                cout << "��������� ������������!" << endl;
            }
            else {
                cout << "������������ ����� ���������." << endl;
            }
            break;
        }
        case 4: {
            int carIndex;
            cout << "������ ����� ��������� ��� ��������� (1-" << carCount << "): ";
            cin >> carIndex;

            if (carIndex >= 1 && carIndex <= carCount) {
                for (int i = carIndex - 1; i < carCount - 1; i++) {
                    cars[i] = cars[i + 1]; cars[i + 1].~Car();
                }
                carCount--;
                cout << "��������� ��������!" << endl;
            }
            else {
                cout << "������������ ����� ���������." << endl;
            }
            break;
        }
        case 5:
            cout << "����� � ��������." << endl;
            break;
        default:
            cout << "������������ ����. ��������� �� ���." << endl;
        }
    } while (choice != 5);

    return 0;
}

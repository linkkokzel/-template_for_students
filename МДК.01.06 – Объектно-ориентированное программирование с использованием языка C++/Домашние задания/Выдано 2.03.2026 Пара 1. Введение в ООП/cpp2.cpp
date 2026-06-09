#include <iostream>
using namespace std;

class Car {
private:
    string model; 
    int fuel;     

public:
    Car(string model, int fuel) {
        this->model = model;
        this->fuel = fuel;
    }

    void drive(int distance) {
        if (fuel >= distance) {
            fuel -= distance;
            cout << model << " проехал "
                << distance << " км." << endl;
        }
        else {
            cout << model
                << ": недостаточно топлива!" << endl;
        }
    }

    void refuel(int amount) {
        fuel += amount;
        cout << model << " заправлен на "
            << amount << " л." << endl;
    }

    int getFuel() {
        return fuel;
    }

    void showInfo() {
        cout << "Модель: " << model
            << ", Топливо: " << fuel << " л."
            << endl;
    }
};

int main() {

    Car car1("Toyota", 50);
    Car car2("BMW", 30);

    cout << "Начальное состояние:\n";
    car1.showInfo();
    car2.showInfo();

    cout << "\nПоездка:\n";
    car1.drive(20);
    car2.drive(15);

    cout << "\nПосле поездки:\n";
    car1.showInfo();
    car2.showInfo();

    cout << "\nЗаправка:\n";
    car1.refuel(10);
    car2.refuel(25);

    cout << "\nИтоговое состояние:\n";
    car1.showInfo();
    car2.showInfo();

    return 0;
}
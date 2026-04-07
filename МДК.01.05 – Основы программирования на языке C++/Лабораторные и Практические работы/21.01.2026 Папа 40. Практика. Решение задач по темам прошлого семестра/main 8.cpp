#include <iostream>
#include <string>
using namespace std;

struct Dish {
    string name;
    double price;
};

int main() {
    Dish menu[5] = {
        {"Пицца", 450.0},
        {"Бургер", 300.0},
        {"Салат", 200.0},
        {"Суп", 180.0},
        {"Чай", 80.0}
    };

    int order[5] = {0};
    int choice;
    double total = 0;

    do {
        cout << "\n=== МЕНЮ РЕСТОРАНА ===\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << menu[i].name << " - " << menu[i].price << " руб.\n";
        }
        cout << "6. Завершить заказ\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            order[choice - 1]++;
            cout << menu[choice - 1].name << " добавлен в заказ!\n";
        } else if (choice != 6) {
            cout << "Неверный выбор!\n";
        }
    } while (choice != 6);

    cout << "\n=== ВАШ ЗАКАЗ ===\n";
    for (int i = 0; i < 5; i++) {
        if (order[i] > 0) {
            double cost = menu[i].price * order[i];
            cout << menu[i].name << " x" << order[i] << " = " << cost << " руб.\n";
            total += cost;
        }
    }
    cout << "ИТОГО: " << total << " руб.\n";

    return 0;
}
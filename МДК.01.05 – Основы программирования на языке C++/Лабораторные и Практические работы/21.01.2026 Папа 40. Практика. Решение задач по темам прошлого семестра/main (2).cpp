#include <iostream>
using namespace std;

int main() {
    double* balance = new double(0.0); // динамическое хранение баланса
    int choice;
    double amount;

    do {
        cout << "\n=== БАНКОМАТ ===\n";
        cout << "1. Пополнить баланс\n";
        cout << "2. Снять наличные\n";
        cout << "3. Проверить баланс\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите сумму для пополнения: ";
                cin >> amount;
                if (amount > 0) {
                    *balance += amount;
                    cout << "Баланс пополнен!\n";
                } else {
                    cout << "Ошибка: сумма должна быть положительной!\n";
                }
                break;
            case 2:
                cout << "Введите сумму для снятия: ";
                cin >> amount;
                if (amount > 0 && amount <= *balance) {
                    *balance -= amount;
                    cout << "Возьмите деньги!\n";
                } else if (amount <= 0) {
                    cout << "Ошибка: сумма должна быть положительной!\n";
                } else {
                    cout << "Ошибка: недостаточно средств!\n";
                }
                break;
            case 3:
                cout << "Ваш баланс: " << *balance << " руб.\n";
                break;
            case 4:
                cout << "До свидания!\n";
                break;
            default:
                cout << "Неверный выбор!\n";
        }
    } while (choice != 4);

    delete balance;
    return 0;
}
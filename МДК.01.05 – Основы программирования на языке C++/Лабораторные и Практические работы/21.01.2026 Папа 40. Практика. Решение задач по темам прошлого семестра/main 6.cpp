#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    srand(time(0));
    string moves[] = {"камень", "ножницы", "бумага"};
    int wins = 0, losses = 0, draws = 0;
    int choice, computer;
    string results[100];
    int resultCount = 0;

    do {
        cout << "\n=== КАМЕНЬ-НОЖНИЦЫ-БУМАГА ===\n";
        cout << "1. Камень\n";
        cout << "2. Ножницы\n";
        cout << "3. Бумага\n";
        cout << "4. Выход и статистика\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            computer = rand() % 3 + 1;
            cout << "Вы: " << moves[choice - 1] << " | Компьютер: " << moves[computer - 1] << endl;

            if (choice == computer) {
                cout << "НИЧЬЯ!\n";
                draws++;
                results[resultCount++] = "Ничья";
            } else if ((choice == 1 && computer == 2) ||
                       (choice == 2 && computer == 3) ||
                       (choice == 3 && computer == 1)) {
                cout << "ВЫ ПОБЕДИЛИ!\n";
                wins++;
                results[resultCount++] = "Победа";
            } else {
                cout << "ВЫ ПРОИГРАЛИ!\n";
                losses++;
                results[resultCount++] = "Поражение";
            }
        } else if (choice != 4) {
            cout << "Неверный выбор!\n";
        }
    } while (choice != 4);

    cout << "\n=== СТАТИСТИКА ===\n";
    cout << "Побед: " << wins << endl;
    cout << "Поражений: " << losses << endl;
    cout << "Ничьих: " << draws << endl;
    cout << "\nИстория:\n";
    for (int i = 0; i < resultCount; i++) {
        cout << i + 1 << ". " << results[i] << endl;
    }

    return 0;
}
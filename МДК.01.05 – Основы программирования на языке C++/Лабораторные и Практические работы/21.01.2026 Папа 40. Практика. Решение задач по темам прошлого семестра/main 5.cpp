#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> floors;
    int currentFloor = 1;
    int floor;
    char more;

    cout << "Лифт на 1 этаже.\n";
    cout << "Сколько человек в лифте? ";
    int people;
    cin >> people;

    for (int i = 0; i < people; i++) {
        cout << "Человек " << i + 1 << ", на какой этаж едете? ";
        cin >> floor;
        while (floor < 1 || floor > 20) {
            cout << "Ошибка! Этажи от 1 до 20. Повторите: ";
            cin >> floor;
        }
        floors.push_back(floor);
    }

    int totalPath = 0;
    int stops = 0;
    vector<int> visited;

    for (int target : floors) {
        if (target != currentFloor) {
            totalPath += abs(target - currentFloor);
            currentFloor = target;
            bool alreadyStopped = false;
            for (int v : visited) {
                if (v == target) alreadyStopped = true;
            }
            if (!alreadyStopped) {
                stops++;
                visited.push_back(target);
            }
            cout << "Остановка на " << target << " этаже\n";
        }
    }

    cout << "\n=== ИТОГ ===\n";
    cout << "Общий путь: " << totalPath << " этажей\n";
    cout << "Количество остановок: " << stops << endl;

    return 0;
}
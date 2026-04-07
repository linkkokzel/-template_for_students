#include <iostream>
#include <string>
using namespace std;

int main() {
    const string days[] = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    int steps[7];
    int maxSteps = 0, minSteps = 0, maxDay = 0, minDay = 0, total = 0;

    cout << "Введите количество шагов за каждый день недели:\n";
    for (int i = 0; i < 7; i++) {
        cout << days[i] << ": ";
        cin >> steps[i];
        if (steps[i] < 0) {
            cout << "Ошибка: шаги не могут быть отрицательными!\n";
            i--;
            continue;
        }
        if (i == 0) {
            maxSteps = minSteps = steps[i];
            maxDay = minDay = i;
        } else {
            if (steps[i] > maxSteps) {
                maxSteps = steps[i];
                maxDay = i;
            }
            if (steps[i] < minSteps) {
                minSteps = steps[i];
                minDay = i;
            }
        }
        total += steps[i];
    }

    double average = total / 7.0;
    cout << "\n=== РЕЗУЛЬТАТЫ ===\n";
    cout << "День с максимумом: " << days[maxDay] << " (" << maxSteps << " шагов)\n";
    cout << "День с минимумом: " << days[minDay] << " (" << minSteps << " шагов)\n";
    cout << "Среднее за неделю: " << average << " шагов\n";

    return 0;
}
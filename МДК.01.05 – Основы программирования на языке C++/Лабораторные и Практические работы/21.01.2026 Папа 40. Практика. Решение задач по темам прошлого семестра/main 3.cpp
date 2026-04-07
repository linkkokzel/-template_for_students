#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    int* grades = new int[n];
    int* ptr = grades;
    int sum = 0, passed = 0, failed = 0;

    cout << "Введите оценки (0-100):\n";
    for (int i = 0; i < n; i++) {
        cout << "Студент " << i + 1 << ": ";
        cin >> *(ptr + i);
        while (*(ptr + i) < 0 || *(ptr + i) > 100) {
            cout << "Ошибка! Оценка от 0 до 100: ";
            cin >> *(ptr + i);
        }
        sum += *(ptr + i);
        if (*(ptr + i) >= 60) passed++;
        else failed++;
    }

    double average = (double)sum / n;
    double passPercent = (double)passed / n * 100;
    double failPercent = (double)failed / n * 100;

    cout << "\n=== СТАТИСТИКА ===\n";
    cout << "Средний балл: " << average << endl;
    cout << "Сдавших: " << passed << " (" << passPercent << "%)\n";
    cout << "Пересдавших: " << failed << " (" << failPercent << "%)\n";

    delete[] grades;
    return 0;
}
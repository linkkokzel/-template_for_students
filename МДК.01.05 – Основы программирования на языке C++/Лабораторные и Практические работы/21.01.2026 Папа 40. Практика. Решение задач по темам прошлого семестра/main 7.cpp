#include <iostream>
#include <string>
using namespace std;

struct Subject {
    string name;
    int grades[100];
    int gradeCount;
};

int main() {
    Subject subjects[50];
    int subjectCount;

    cout << "Введите количество предметов: ";
    cin >> subjectCount;

    for (int i = 0; i < subjectCount; i++) {
        cout << "\nНазвание предмета " << i + 1 << ": ";
        cin >> subjects[i].name;
        cout << "Сколько оценок? ";
        cin >> subjects[i].gradeCount;

        cout << "Введите оценки (2-5):\n";
        for (int j = 0; j < subjects[i].gradeCount; j++) {
            cout << "Оценка " << j + 1 << ": ";
            cin >> subjects[i].grades[j];
            while (subjects[i].grades[j] < 2 || subjects[i].grades[j] > 5) {
                cout << "Ошибка! Оценка от 2 до 5: ";
                cin >> subjects[i].grades[j];
            }
        }
    }

    string worstSubject;
    double minAverage = 6;
    double totalAverage = 0;

    cout << "\n=== СРЕДНИЕ БАЛЛЫ ===\n";
    for (int i = 0; i < subjectCount; i++) {
        int sum = 0;
        for (int j = 0; j < subjects[i].gradeCount; j++) {
            sum += subjects[i].grades[j];
        }
        double avg = (double)sum / subjects[i].gradeCount;
        totalAverage += avg;
        cout << subjects[i].name << ": " << avg << endl;

        if (avg < minAverage) {
            minAverage = avg;
            worstSubject = subjects[i].name;
        }
    }

    cout << "\nОбщий средний балл: " << totalAverage / subjectCount << endl;
    cout << "Худший предмет: " << worstSubject << " (" << minAverage << ")\n";

    return 0;
}
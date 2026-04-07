#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    bool isPalindrome = true;
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Массив является палиндромом!\n";
    } else {
        cout << "Массив НЕ является палиндромом.\n";
    }

    delete[] arr;
    return 0;
}
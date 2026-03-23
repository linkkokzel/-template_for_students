#include <iostream>
using namespace std;

class CurrencyConverter {
private:
    static double usdToRubRate;
    
public:
    static void SetRate(double rate) {
        if (rate > 0) {
            usdToRubRate = rate;
            cout << "Курс установлен: 1 USD = " << usdToRubRate << " RUB" << endl;
        } else {
            cout << "Ошибка: курс должен быть положительным числом!" << endl;
        }
    }
    static double ConvertUsdToRub(double usd) {
        if (usd < 0) {
            cout << "Ошибка: сумма не может быть отрицательной!" << endl;
            return 0;
        }
        return usd * usdToRubRate;
    }
    static double ConvertRubToUsd(double rub) {
        if (rub < 0) {
            cout << "Ошибка: сумма не может быть отрицательной!" << endl;
            return 0;
        }
        if (usdToRubRate == 0) {
            cout << "Ошибка: курс не установлен!" << endl;
            return 0;
        }
        return rub / usdToRubRate;
    }
    
    static double GetRate() {
        return usdToRubRate;
    }
};
double CurrencyConverter::usdToRubRate = 0.0;

int main() {
    setlocale(LC_ALL, "Russian"); 
    
    cout << "=== Конвертер валют ===" << endl << endl;
    
    cout << "1. Устанавливаем курс доллара к рублю:" << endl;
    CurrencyConverter::SetRate(91.50);     
    cout << endl << "2. Конвертируем доллары в рубли:" << endl;
    double dollars = 100.0;
    double rubles = CurrencyConverter::ConvertUsdToRub(dollars);
    cout << dollars << " USD = " << rubles << " RUB" << endl;
    
    dollars = 50.0;
    rubles = CurrencyConverter::ConvertUsdToRub(dollars);
    cout << dollars << " USD = " << rubles << " RUB" << endl;
    
    cout << endl << "3. Конвертируем рубли в доллары:" << endl;
    rubles = 5000.0;
    dollars = CurrencyConverter::ConvertRubToUsd(rubles);
    cout << rubles << " RUB = " << dollars << " USD" << endl;
    
    cout << endl << "4. Меняем курс:" << endl;
    CurrencyConverter::SetRate(92.75); // Новый курс
    
    cout << endl << "5. Снова конвертируем с новым курсом:" << endl;
    dollars = 100.0;
    rubles = CurrencyConverter::ConvertUsdToRub(dollars);
    cout << dollars << " USD = " << rubles << " RUB (по новому курсу)" << endl;
    
    cout << endl << "6. Показываем текущий курс:" << endl;
    cout << "Текущий курс: 1 USD = " << CurrencyConverter::GetRate() << " RUB" << endl;
    
    cout << endl << "7. Проверяем обработку ошибок:" << endl;
    CurrencyConverter::ConvertUsdToRub(-50); 
    CurrencyConverter::SetRate(-10); 
    
    return 0;
}
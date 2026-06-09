#include <iostream>
#include <string>

enum class ClothingType {
    T_SHIRT,
    SHIRT,
    PANTS,
    JACKET,
    DRESS,
    SKIRT
};

std::string typeToString(ClothingType type) {
    switch (type) {
    case ClothingType::T_SHIRT: return "Футболка";
    case ClothingType::SHIRT:   return "Рубашка";
    case ClothingType::PANTS:   return "Штаны";
    case ClothingType::JACKET:  return "Куртка";
    case ClothingType::DRESS:   return "Платье";
    case ClothingType::SKIRT:   return "Юбка";
    default: return "Неизвестно";
    }
}

class Clothes {
private:
    ClothingType category;   
    std::string name;        
    double price;           
    std::string size;       
    std::string color;       

public:
    Clothes()
        : category(ClothingType::T_SHIRT), name(""), price(0.0), size(""), color("") {
    }

    Clothes(ClothingType cat, const std::string& name, double price,
        const std::string& size, const std::string& color)
        : category(cat), name(name), price(price), size(size), color(color) {
    }

    ClothingType getCategory() const {
        return category;
    }

    void setCategory(ClothingType newCategory) {
        category = newCategory;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
        else {
            std::cout << "Ошибка: название не может быть пустым!\n";
        }
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double newPrice) {
        if (newPrice >= 0.0) {
            price = newPrice;
        }
        else {
            std::cout << "Ошибка: цена не может быть отрицательной!\n";
        }
    }

    std::string getSize() const {
        return size;
    }

    void setSize(const std::string& newSize) {
        if (newSize == "S" || newSize == "M" || newSize == "L" ||
            newSize == "XL" || newSize == "XXL") {
            size = newSize;
        }
        else {
            std::cout << "Ошибка: недопустимый размер!\n";
        }
    }

    std::string getColor() const {
        return color;
    }

    void setColor(const std::string& newColor) {
        if (!newColor.empty()) {
            color = newColor;
        }
        else {
            std::cout << "Ошибка: цвет не может быть пустым!\n";
        }
    }

    void printInfo() const {
        std::cout << "Одежда: " << typeToString(category)
            << "\nНазвание: " << name
            << "\nЦена: " << price << " руб."
            << "\nРазмер: " << size
            << "\nЦвет: " << color << std::endl;
    }
};
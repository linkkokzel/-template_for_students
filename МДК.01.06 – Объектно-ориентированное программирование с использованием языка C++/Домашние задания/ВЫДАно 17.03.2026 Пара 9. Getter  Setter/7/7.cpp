// задание 1

#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int age;
    static int count; 

public:
    Student(const std::string& name, int age) : name(name), age(age) {
        count++;  
    }

    ~Student() {
        count--;  
    }

    static int getCount() {
        return count;
    }

    void print() const {
        std::cout << "Student: " << name << ", " << age << " years old\n";
    }
};

int Student::count = 0;

int main() {
    std::cout << "Initial count: " << Student::getCount() << std::endl;

    Student a("Alice", 20);
    Student b("Bob", 21);
    Student c("Charlie", 22);

    std::cout << "After creating 3 students: " << Student::getCount() << std::endl;

    a.print();
    b.print();
    c.print();

    {
        Student d("Diana", 19);
        std::cout << "Inside block, count = " << Student::getCount() << std::endl;
    } 

    std::cout << "After leaving block, count = " << Student::getCount() << std::endl;

    return 0;
}

// задание 2


#include <iostream>

class MathUtils {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static int sub(int a, int b) {
        return a - b;
    }

    static int mul(int a, int b) {
        return a * b;
    }
};

int main() {
    int x = 10, y = 5;

    std::cout << "MathUtils::add(10,5) = " << MathUtils::add(x, y) << std::endl;
    std::cout << "MathUtils::sub(10,5) = " << MathUtils::sub(x, y) << std::endl;
    std::cout << "MathUtils::mul(10,5) = " << MathUtils::mul(x, y) << std::endl;


    return 0;
}


// задание 3

#include <iostream>
#include <string>

class Product {
private:
    std::string name;
    double price;
    static int productCount; 
public:
    Product() : name("Unknown"), price(0.0) {
        productCount++;
    }

    Product(const std::string& name, double price) : name(name), price(price) {
        productCount++;
    }

    ~Product() {
        productCount--;
    }

    static int getProductCount() {
        return productCount;
    }

    void print() const {
        std::cout << "Product: " << name << ", price: " << price << " руб.\n";
    }

    void setPrice(double newPrice) { price = newPrice; }
    double getPrice() const { return price; }
};

int Product::productCount = 0;

int main() {
    std::cout << "Current products count: " << Product::getProductCount() << std::endl;

    Product p1("Laptop", 1200.0);
    Product p2("Mouse", 25.5);
    Product p3("Keyboard", 45.0);

    std::cout << "After creating 3 products: " << Product::getProductCount() << std::endl;

    p1.print();
    p2.print();
    p3.print();

    Product* p4 = new Product("Monitor", 300.0);
    std::cout << "After creating 4th product: " << Product::getProductCount() << std::endl;

    delete p4;  
    std::cout << "After deleting 4th product: " << Product::getProductCount() << std::endl;

    return 0;
}
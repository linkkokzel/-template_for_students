// задание 1

#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;

public:
    String(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    String& operator=(const String& other) {
        if (this != &other) { 
            delete[] data;    
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;         
    }

    ~String() {
        delete[] data;
    }

    void print() const {
        std::cout << data << std::endl;
    }

    size_t getLength() const {
        return length;
    }
};


// задание 2

#include <iostream>

class Buffer {
private:
    int* arr;
    size_t size;

public:
    Buffer(size_t n = 0) : size(n) {
        arr = (n > 0) ? new int[n] : nullptr;
        for (size_t i = 0; i < size; ++i)
            arr[i] = 0;
    }

    Buffer(const Buffer& other) : size(other.size) {
        arr = new int[size];
        for (size_t i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (size_t i = 0; i < size; ++i)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    ~Buffer() {
        delete[] arr;
    }

    void fill(int value) {
        for (size_t i = 0; i < size; ++i)
            arr[i] = value;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

    void set(size_t index, int value) {
        if (index < size)
            arr[index] = value;
    }

    size_t getSize() const { return size; }
};
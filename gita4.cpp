#include <iostream>

class Array {
private:
    int* data;
    size_t size;

public:
    Array() : data(nullptr), size(0) {}

    Array(size_t newSize) : size(newSize) {
        data = new int[size];
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    void allocateAndInitialize(size_t newSize, int minValue, int maxValue) {
        delete[] data;
        size = newSize;
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = minValue + rand() % (maxValue - minValue + 1);
        }
    }

    void initialize(int minValue, int maxValue) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = minValue + rand() % (maxValue - minValue + 1);
        }
    }

    void initialize(int minValue, int maxValue, int (*randomFunc)()) {
        for (size_t i = 0; i < size; ++i) {
            int randomValue = randomFunc();
            data[i] = minValue + randomValue % (maxValue - minValue + 1);
        }
    }

    ~Array() {
        delete[] data;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int customRandom() {
    return rand();
}

int main() {
    srand(time(0));

    Array arr1;
    arr1.allocateAndInitialize(10, 1, 100);
    arr1.print();

    Array arr2 = arr1;
    arr2.print();

    arr2.initialize(50, 150);
    arr2.print();

    arr2.initialize(100, 200, customRandom);
    arr2.print();

    return 0;
}

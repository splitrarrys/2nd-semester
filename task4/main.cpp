#include <iostream>
#include "DynamicArray.h"

void demonstrate_collection() {
    // Создание коллекции разными способами
    DynamicArray arr1;
    DynamicArray arr2{1, 2, 3, 4, 5};
    DynamicArray arr3(10);
    
    // Добавление элементов
    for (int i = 0; i < 5; ++i) {
        arr1.push_back(i * 10);
    }
    
    // Демонстрация операторов
    DynamicArray shifted_left = arr2 << 2;
    DynamicArray shifted_right = arr2 >> 1;
    
    // Вывод информации
    std::cout << "arr1: " << arr1.to_string() << std::endl;
    std::cout << "arr2: " << arr2.to_string() << std::endl;
    std::cout << "arr2 << 2: " << shifted_left.to_string() << std::endl;
    std::cout << "arr2 >> 1: " << shifted_right.to_string() << std::endl;
    
    // Проверка на пустоту
    std::cout << "Is arr1 empty? " << (arr1.is_empty() ? "Yes" : "No") << std::endl;
    
    // Копирование и перемещение
    DynamicArray arr4 = arr2;
    DynamicArray arr5 = std::move(arr3);
    
    std::cout << "Copied array: " << arr4.to_string() << std::endl;
    std::cout << "Moved array size: " << arr5.get_size() << std::endl;
}

int main() {
    try {
        demonstrate_collection();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
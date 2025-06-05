#pragma once

#include <initializer_list>
#include <string>

class DynamicArray {
private:
    int* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    // Конструкторы и деструктор
    DynamicArray();
    explicit DynamicArray(size_t initial_capacity);
    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray(std::initializer_list<int> init_list);
    ~DynamicArray();

    // Операторы присваивания
    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    // Операторы сдвига
    DynamicArray operator<<(int shift) const;
    DynamicArray operator>>(int shift) const;

    // Методы доступа
    void push_back(int value);
    int at(size_t index) const;
    size_t get_size() const;
    bool is_empty() const;

    // Преобразование в строку
    std::string to_string() const;
};
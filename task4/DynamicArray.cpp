#include "DynamicArray.h"
#include <stdexcept>
#include <algorithm>
#include <sstream>

DynamicArray::DynamicArray() : data(nullptr), capacity(0), size(0) {}

DynamicArray::DynamicArray(size_t initial_capacity) : 
    data(new int[initial_capacity]), capacity(initial_capacity), size(0) {}

DynamicArray::DynamicArray(const DynamicArray& other) : 
    data(new int[other.capacity]), capacity(other.capacity), size(other.size) {
    std::copy(other.data, other.data + other.size, data);
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept : 
    data(other.data), capacity(other.capacity), size(other.size) {
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

DynamicArray::DynamicArray(std::initializer_list<int> init_list) : 
    data(new int[init_list.size()]), capacity(init_list.size()), size(init_list.size()) {
    std::copy(init_list.begin(), init_list.end(), data);
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::resize(size_t new_capacity) {
    int* new_data = new int[new_capacity];
    std::copy(data, data + size, new_data);
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data;
        data = new int[other.capacity];
        capacity = other.capacity;
        size = other.size;
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        size = other.size;
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

DynamicArray DynamicArray::operator<<(int shift) const {
    DynamicArray result(*this);
    if (size > 0 && shift > 0) {
        shift %= size;
        std::rotate(result.data, result.data + shift, result.data + size);
    }
    return result;
}

DynamicArray DynamicArray::operator>>(int shift) const {
    DynamicArray result(*this);
    if (size > 0 && shift > 0) {
        shift %= size;
        std::rotate(result.data, result.data + (size - shift), result.data + size);
    }
    return result;
}

void DynamicArray::push_back(int value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

int DynamicArray::at(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

size_t DynamicArray::get_size() const {
    return size;
}

bool DynamicArray::is_empty() const {
    return size == 0;
}

std::string DynamicArray::to_string() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < size; ++i) {
        if (i != 0) oss << ", ";
        oss << data[i];
    }
    oss << "]";
    return oss.str();
}
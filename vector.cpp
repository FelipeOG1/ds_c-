#include "vector.h"
#include <algorithm>
#include <iostream>

void Vector::expandCapacity() {
    int newCapacity = capacity * 2;
    auto newValues = std::make_unique<float []>(capacity);
    std::copy(values.get(), values.get() + size, newValues.get());
    
    capacity = newCapacity;
    values = std::move(newValues);
}

void Vector::add(float value) {
    if (static_cast<int>(size) == capacity) expandCapacity();
    values[size] = value;
    size++;
}



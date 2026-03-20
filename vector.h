#pragma once
#include <memory>



class Vector {
private:
    void expandCapacity();
    int capacity;
    size_t size;
    std::unique_ptr<float []> values;

public:
      Vector() : capacity(20), size(0), values(std::make_unique<float []>(20)) {}
    

    void add(float value);
    
    int getCapacity() const { return capacity;}
    size_t getSize() const { return size; }
};

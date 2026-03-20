#pragma once
#include <memory>



class Vector {
    

public:
    int capacity;
    size_t size;
    std::unique_ptr<float []> values;
    Vector() : capacity(20), size(0), values(std::make_unique<float []>(20)) {}
    
};

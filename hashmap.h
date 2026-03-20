#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Node {
    std::string value;
    std::unique_ptr<Node> next;
};

class LinkedList {
private:
    std::unique_ptr<Node> head = nullptr;

public:
    void add(std::string value);
    Node* get(std::string& value);
    void traverse();
    void removeValue(std::string value);
};

class HashMap {
private:
    std::vector<LinkedList> buckets;
    size_t getHash(const std::string& s);

public:
    HashMap(size_t size = 100);
    void put(std::string value);
    std::string* get(std::string s);
};

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
    void add(std::string value) {
        auto newNode = std::make_unique<Node>();
        newNode->value = value;
        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    Node* get(std::string& value) {
        Node* current = head.get();
        while (current != nullptr) {
            if (current->value == value){
                return current;
            }
            current = current->next.get();
        }

        return nullptr;
    }

    void traverse() {
        for (Node* currentNode = head.get(); currentNode != nullptr; currentNode = currentNode->next.get()) {
            std::cout << currentNode->value << std::endl;
        }
    }


    void removeValue(std::string value) {
        if (!head) return;
        if (head->value == value) {
            head = std::move(head->next);
            return;
        }


        Node *previous = head.get();
        Node *current = head->next.get();

        while (current != nullptr) {
            if (current->value == value) {
                previous->next = std::move(current->next);
                return;
            }
            previous = current;
            current = current->next.get();    
        }

    }

};


class HashMap {
private:
    std::vector<LinkedList> buckets; 

    size_t getHash(const std::string& s) { 
        size_t hash = 0;
        const size_t p = 31;
        for (char c : s) {
            hash = hash * p + c;
        }
        return hash;
    }

public:
    HashMap(size_t size = 100) { 
        buckets.resize(size); 
    }

    void put(std::string value) {
        size_t index = getHash(value) % buckets.size();
        if (buckets[index].get(value) == nullptr) {
            buckets[index].add(value);
        }
    }

    std::string* get(std::string s) {
        size_t index = getHash(s) % buckets.size();
        Node* node = buckets[index].get(s);
        
        if (node != nullptr) {
            return &(node->value); 
        }
        return nullptr; 
    }
};


int main() {
    
    
    return 0;
}


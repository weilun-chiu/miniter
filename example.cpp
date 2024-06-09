#include <iostream>

struct Node {
    void* data;
    Node* next;

    Node(void* data) : data(data), next(nullptr) {}
};

class SimpleList {
private:
    Node* head;
    Node* tail;

public:
    SimpleList() : head(nullptr), tail(nullptr) {}

    void insertAtBack(void* data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}

        void* operator*() const {
            return current->data;
        }

        void* operator*() {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ~SimpleList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    SimpleList list;
    int a = 1, b = 2, c = 3;

    list.insertAtBack(&a);
    list.insertAtBack(&b);
    list.insertAtBack(&c);

    // Print addresses stored in the list
    for (void* data : list) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    // Print values stored in the list
    for (void* data : list) {
        std::cout << *static_cast<int*>(data) << " ";
    }
    std::cout << std::endl;

    // Modify values stored in the list
    for (void* data : list) {
        *static_cast<int*>(data) *= 2;
    }

    // Print modified values stored in the list
    for (void* data : list) {
        std::cout << *static_cast<int*>(data) << " ";
    }
    std::cout << std::endl;

    return 0;
}

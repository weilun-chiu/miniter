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

    Iterator end() const {
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

    for (void* data : list) {
        std::cout << data << " ";  // Prints addresses of a, b, c
    }
    std::cout << std::endl;

    for (void* data : list) {
        std::cout << *static_cast<int*>(data) << " ";  // Prints values: 1 2 3
    }
    std::cout << std::endl;

    return 0;
}

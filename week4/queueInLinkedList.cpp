#include <iostream>
#include <string>

using namespace std;

struct node {
    int data;
    node *next;

    node() {
        data = 0;
        next = NULL;
    }
};

class linkedList {
private:
    node *head;
    node *tail;
    int size;

public:
    linkedList();

    void append(int data);

    void deletion();

    bool isEmpty();

    int front() {
        if (isEmpty()) return -1;
        return head->data;
    }

    int rear() {
        if (isEmpty()) return -1;
        return tail->data;
    }

    int getSize() {
        return size;
    }

    void print();
};


int main() {}

linkedList::linkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void linkedList::append(int data) {
    node *newNode = new node;
    newNode->data = data;
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
    print();
}

void linkedList::deletion() {
    if (isEmpty()) return;
    node *oldNode = head;
    if (size == 1) {
        head = tail = NULL;
    } else {
        head = head->next;
    }
    int deleteValue = oldNode->data;
    size--;
    delete oldNode;
    print();
}

bool linkedList::isEmpty() {
    return (size == 0);
}

void linkedList::print() {
    if (isEmpty()) return;
    node *current = head;
    for (int i = 0; i < size; i++) {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << endl;
}
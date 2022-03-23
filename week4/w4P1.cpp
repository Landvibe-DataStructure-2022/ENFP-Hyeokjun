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

    void empty();

    void print();
};


int main() {
    int n;
    string s;
    linkedList q;
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "enqueue") {
            int data;
            cin >> data;
            q.append(data);
        } else if (s == "dequeue") {
            q.deletion();
        } else if (s == "isEmpty") {
            q.empty();
        } else if (s == "size") {
            cout << q.getSize() << endl;
        } else if (s == "front") {
            if(q.front() == -1) cout << "Empty" << endl;
            else cout << q.front() << endl;
        } else if (s == "rear") {
            if(q.rear() == -1) cout << "Empty" << endl;
            else cout << q.rear() << endl;
        }
    }
}

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
}

void linkedList::deletion() {
    if (isEmpty()) {
        cout << "Empty" << endl;
        return;
    }
    node *oldNode = head;
    int deleteValue = oldNode->data;

    if (size == 1) {
        head = tail = NULL;
    } else {
        head = head->next;
    }
    size--;
    delete oldNode;
    cout << deleteValue << endl;
}

bool linkedList::isEmpty() {
    return (size == 0);
}

void linkedList::empty() {
    if (isEmpty()) cout << "True" << endl;
    else cout << "False" << endl;
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
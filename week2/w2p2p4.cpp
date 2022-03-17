#include <iostream>
#include <string>

using namespace std;

int max_(int a, int b) {
    return a > b ? a : b;
}

struct node {
    int data;
    node *prev;
    node *next;

    node() {
        data = 0;
        prev = NULL;
        next = NULL;
    };
};

class doublyLinkedList {
private:
    node *header;
    node *trailer;
    int size;
public:
    doublyLinkedList() {
        header = NULL;
        trailer = NULL;
        size = 0;
    }

    void print();

    void append(int);

    int deletion(int);

    void print_reverse();

    void max();

    bool empty() {
        if (size == 0) return true;
        else return false;
    }

    void update(int from, int to) {
        if (empty()) {
            cout << "empty" << endl;
            return;
        }
        int cnt = 0;
        node *current = header;
        while (current != NULL) {
            if (current->data == from) {
                current->data = to;
                cnt++;
            }
            current = current->next;
        }
        if (cnt == 0) {
            cout << "Not found" << endl;
        } else {
            print();
        }
    }
};

int main() {
    int n;
    doublyLinkedList dLL;
    string query;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> query;
        if (query == "Print") {
            dLL.print();
        } else if (query == "Append") {
            int n;
            cin >> n;
            dLL.append(n);
        } else if (query == "Delete") {
            int n;
            cin >> n;
            cout << dLL.deletion(n) << endl;
        } else if (query == "Print_reverse") {
            dLL.print_reverse();
        } else if (query == "Max") {
            dLL.max();
        } else if (query == "Update") {
            int n, m;
            cin >> n >> m;
            dLL.update(n, m);
        }
    }
}

void doublyLinkedList::print() {
    if (empty()) {
        cout << "empty" << endl;
        return;
    }

    node *current = header;
    while (current != NULL) {
        cout << current->data << ' ';
        current = current->next;
    }
    cout << endl;
}

void doublyLinkedList::append(int data) {
    node *newNode = new node;
    newNode->data = data;
    if (empty()) {
        header = trailer = newNode;
    } else {
        trailer->next = newNode;
        newNode->prev = trailer;
        trailer = newNode;
    }
    size++;
    print();
}

int doublyLinkedList::deletion(int index) {
    if (empty() || index >= size) {
        return -1;
    }
    node *deleteNode = header;
    if (index == 0) {
        if (size == 1) {
            header = NULL;
            trailer = NULL;
        } else {
            header->next->prev = NULL;
            header = header->next;
        }
    } else {
        node *prevNode = header;
        for (int i = 0; i < index; i++) {
            prevNode = deleteNode;
            deleteNode = deleteNode->next;
        }
        prevNode->next = deleteNode->next;
        if (deleteNode == trailer) {
            trailer = prevNode;
        } else {
            deleteNode->next->prev = prevNode;
        }
    }
    int deleteValue = deleteNode->data;
    delete deleteNode;
    size--;
    return deleteValue;
}

void doublyLinkedList::print_reverse() {
    if (empty()) {
        cout << "empty" << endl;
        return;
    }

    node *current = trailer;
    while (current != NULL) {
        cout << current->data << ' ';
        current = current->prev;
    }
    cout << endl;
}

void doublyLinkedList::max() {
    if (empty()) {
        cout << "empty" << endl;
        return;
    }
    int cnt = 0;
    node *current = header;
    while (current != NULL) {
        cnt = max_(cnt, current->data);
        current = current->next;
    }
    cout << cnt << endl;
}
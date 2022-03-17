//
// Created by ±««ı¡ÿ on 2022/03/17.
//
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

    ~node() {
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

    friend class stack;

    linkedList() {
        head = tail = NULL;
        size = 0;
    }

    bool empty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void append(int data) {
        node *newNode = new node;
        newNode->data = data;
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }


    int deletion() {
        if (empty()) {
            return -1;
        }
        node *oldNode = head;
        if (size == 1) {
            head = tail = NULL;
        } else {
            node *prevNode = head;
            for (int i = 1; i < size; i++) {
                prevNode = oldNode;
                oldNode = oldNode->next;
            }
            prevNode->next = NULL;
            tail = prevNode;
        }
        int oldValue = oldNode->data;
        delete oldNode;
        size--;
        return oldValue;
    }


};

class stack {
private:
    linkedList ll;
public:

    void empty() {
        if (ll.empty()) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    void Top() {
        if (ll.empty()) {
            cout << -1 << endl;
        } else {
            cout << ll.tail->data << endl;
        }
    }

    void push(int data) {
        ll.append(data);
    }

    int pop() {
        return ll.deletion();
    }
};

int main() {
    string query;
    int n;
    cin >> n;
    stack st;
    while (n--) {
        cin >> query;
        if (query == "empty") {
            st.empty();
        } else if (query == "push") {
            int data;
            cin >> data;
            st.push(data);
        } else if (query == "pop") {
            cout << st.pop() << endl;
        } else if (query == "top") {
            st.Top();
        }
    }
}

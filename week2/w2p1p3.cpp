#include <iostream>
#include <string>

using namespace std;
#define MAX 10001

int min_(int a, int b) {
    return a < b ? a : b;
}

struct node {
    int data;
    node *next;

    node() {
        data = 0;
        next = NULL;
    }
};

class singlyLinkedList {
private:
    node *head;
    node *tail;
    int size;
public:
    singlyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool empty() {
        if (size == 0) return true;
        else return false;
    }

    void print() {
        if (empty()) {
            cout << "empty" << endl;
            return;
        }
        node *current = head;
        while (current != NULL) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
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
        print();
    }

    int deletion(int index) {
        if (empty() || index >= size) {
            return -1;
        }
        int deleteData = 0;
        node *deleteNode = head;

        if (index == 0) {
            if (size == 1) {
                head = tail = NULL;
            } else {
                head = head->next;
            }
        } else {
            node *prevNode = head;
            for (int i = 0; i < index; i++) {
                prevNode = deleteNode;
                deleteNode = deleteNode->next;
            }
            prevNode->next = deleteNode->next;
            if (deleteNode == tail) {
                tail = prevNode;
            }
        }
        deleteData = deleteNode->data;
        delete deleteNode;
        size--;
        return deleteData;
    }

    void insertion(int index, int data) {
        if (index > size) {
            cout << "Index Error" << endl;
        } else if (index == size) {
            append(data);
        } else if (index == 0) {
            node *newNode = new node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            size++;
            print();
        } else {
            node *newNode = new node;
            newNode->data = data;
            node *current = head;

            for (int i = 1; i < index; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
            print();
        }
    }

    void sum() {
        if (empty()) {
            cout << 0 << endl;
        } else {
            node *current = head;
            int cnt = 0;
            while (current != NULL) {
                cnt += current->data;
                current = current->next;
            }
            cout << cnt << endl;
        }
    }

    void min() {
        if (empty()) {
            cout << "empty" << endl;
            return;
        }
        node *current = head;
        int cnt = MAX;
        while (current != NULL) {
            cnt = min_(cnt, current->data);
            current = current->next;
        }
        cout << cnt << endl;
    }
};

int main() {
    string query;
    int n;

    singlyLinkedList sLL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> query;

        if (query == "Print") {
            sLL.print();
        } else if (query == "Append") {
            int m;
            cin >> m;
            sLL.append(m);
        } else if (query == "Delete") {
            int m;
            cin >> m;
            cout << sLL.deletion(m) << endl;
        } else if (query == "Insert") {
            int m, n;
            cin >> m >> n;
            sLL.insertion(m, n);
        } else if (query == "Sum") {
            sLL.sum();
        } else if (query == "Min") {
            sLL.min();
        }
    }
}


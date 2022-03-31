#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    ~Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }
};

struct Iterator {
    Node *node;

    Iterator(Node *node) {
        this->node = node;
    }

    Iterator *operator++() {
        node = node->next;
        return this;
    }

    Iterator *operator--() {
        node = node->prev;
        return this;
    }

};

class Sequence {
private:
    int size;
    Node *head;
    Node *tail;
public:
    Sequence() {
        size = 0;
        head = new Node;
        head->data = 0;
        tail = new Node;
        tail->data = 0;
        head->next = tail;
        tail->prev = head;
    }

    Node *begin() {
        return head->next;
    }

    Node *end() {
        return tail;
    }

    void insert(Iterator &p, int data) {
        Node *newNode = new Node;
        newNode->data = data;

        p.node->prev->next = newNode;
        newNode->prev = p.node->prev;

        p.node->prev = newNode;
        newNode->next = p.node;

        size++;
    }

    int conv(Iterator p) {
        return p.node->prev->data + p.node->next->data + 3 * (p.node->data);
    }

};

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        Sequence sequence;
        Iterator iterator = Iterator(sequence.begin());
        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            sequence.insert(iterator, k);
        }
        iterator = Iterator(sequence.begin());
        for (int i = 0; i < m; i++) {
            cout << sequence.conv(iterator) << ' ';
            ++iterator;
        }
        cout << endl;
    }
}
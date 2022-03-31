#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;

    Node() {
        data = 0;
        prev = NULL;
        next = NULL;
    }

    ~Node() {
        data = 0;
        prev = NULL;
        next = NULL;
    }

};

struct Iterator {
    Node *node;

    Iterator(Node *p) {
        node = p;
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
    Node *head;
    Node *tail;
    int size;
public:
    Sequence() {
        head = new Node();
        tail = new Node();
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    Node *begin() {
        return head->next;
    }

    Node *end() {
        return tail;
    }

    void insert(Iterator &p, int data);

    void deletion(Iterator &p);

    void reversePrint();

    void find(int data);

    bool empty();
};

int main() {


    int tc;
    string query;
    cin >> tc;
    Sequence sequence;
    Iterator p(sequence.begin());

    while (tc--) {
        cin >> query;
        if (query == "begin") {
            p = sequence.begin();
        } else if (query == "end") {
            p = sequence.end();
        } else if (query == "insert") {
            int n;
            cin >> n;
            sequence.insert(p, n);
        } else if (query == "erase") {
            sequence.deletion(p);
        } else if (query == "++") {
            ++p;
        } else if (query == "--") {
            --p;
        } else if (query == "reversePrint") {
            sequence.reversePrint();
        } else if (query == "find") {
            int n;
            cin >> n;
            sequence.find(n);
        }
    }
}

void Sequence::insert(Iterator &p, int data) {
    Node *newNode = new Node;
    newNode->data = data;

    p.node->prev->next = newNode;
    newNode->prev = p.node->prev;

    newNode->next = p.node;
    p.node->prev = newNode;

    size++;
}

void Sequence::deletion(Iterator &p) {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    Node *oldNode = p.node;
    p.node->prev->next = p.node->next;
    p.node->next->prev = p.node->prev;
    delete oldNode;
    size--;
    p.node = begin();
}

void Sequence::reversePrint() {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    Node *cur = end();
    while (cur->prev != head) {
        cur = cur->prev;
        cout << cur->data << ' ';
    }
    cout << endl;
}

void Sequence::find(int data) {
    if (empty()) {
        cout << "Empty" << endl;
        return;
    }
    Node *cur = begin();
    for (int i = 0; i <= size; i++) {
        if (cur == tail) {
            cout << -1 << endl;
            return;
        }
        if (cur->data == data) {
            cout << i << endl;
            return;
        }
        cur = cur->next;
    }
}

bool Sequence::empty() {
    return (size == 0);
}
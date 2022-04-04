#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *parent;
    vector<Node *> child;

    Node(int data) {
        parent = NULL;
        this->data = data;
    }

    Node(Node *node, int data) {
        parent = node;
        this->data = data;
    }
};

class Tree {
private:
    Node *root;
    vector<Node *> nodelist;
public:
    Tree() {
        root = new Node(1);
        nodelist.push_back(root);
    }

    Node *findNode(int data) {
        for (int i = 0; i < nodelist.size(); i++) {
            if (nodelist[i]->data == data) {
                return nodelist[i];
            }
        }
        return NULL;
    }

    void insertNode(int parentData, int childData) {
        Node *cur = findNode(parentData);
        if (cur == NULL) {
            cout << -1 << endl;
            return;
        }
        Node *newNode = new Node(cur, childData);
        cur->child.push_back(newNode);
        nodelist.push_back(newNode);
    }

    void deleteNode(int data) {
        if (nodelist.size() == 1) {
            cout << -1 << endl;
            return;
        }
        Node *cur = findNode(data);
        if (cur == NULL) {
            cout << -1 << endl;
            return;
        }
        Node *parent = cur->parent;
        for (int i = 0; i < cur->child.size(); i++) {
            cur->child[i]->parent = parent;
            parent->child.push_back(cur->child[i]);
        }
        for (int i = 0; i < parent->child.size(); i++) {
            if (parent->child[i] == cur) {
                parent->child.erase(parent->child.begin() + i);
                break;
            }
        }
        for (int i = 0; i < nodelist.size(); i++) {
            if (nodelist[i] == cur) {
                nodelist.erase(nodelist.begin() + i);
                break;
            }
        }
        delete cur;
    }

    void print(int data) {
        if (nodelist.size() == 1) {
            cout << -1 << endl;
            return;
        }
        Node *cur = findNode(data);
        if (cur == NULL || cur == root) {
            cout << -1 << endl;
            return;
        }
        cout << cur->parent->data << endl;
    }
};

int main() {
    int tc;
    cin >> tc;
    Tree tree;
    string query;
    while (tc--) {
        cin >> query;
        if (query == "insert") {
            int n, m;
            cin >> n >> m;
            tree.insertNode(n, m);
        } else if (query == "print") {
            int n;
            cin >> n;
            tree.print(n);
        } else if (query == "delete") {
            int n;
            cin >> n;
            tree.deleteNode(n);
        }
    }
}
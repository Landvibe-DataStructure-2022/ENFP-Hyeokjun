#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *parent;
    vector<Node *> child;

    Node(int data) {
        this->data = data;
        parent = NULL;
    }

    Node(Node *node, int data) {
        this->data = data;
        parent = node;
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
    Node* getRoot(){
        return root;
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
        Node *newNode = new Node(cur, childData);
        cur->child.push_back(newNode);
        nodelist.push_back(newNode);
    }

    void dfs(Node *cur) {
        cout << cur->data << ' ';
        for (int i = 0; i < cur->child.size(); i++) {
            dfs(cur->child[i]);
        }

    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int cnt;
        cin >> cnt;
        Tree tree;
        for (int i = 0; i < cnt; i++) {
            int n, m;
            cin >> n >> m;
            tree.insertNode(n, m);
        }
        tree.dfs(tree.getRoot());
        cout << endl;
    }
}
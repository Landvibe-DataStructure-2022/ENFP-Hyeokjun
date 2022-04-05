#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    int depth;
    Node *parent;
    vector<Node *> child;

    Node(int data) {
        this->data = data;
        parent = NULL;
        depth = 0;
    }

    Node(Node *node, int data) {
        this->data = data;
        parent = node;
        depth = 0;
    }

    Node(Node *node, int data, int depth) {
        this->data = data;
        parent = node;
        this->depth = depth;
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

    Node *getRoot() {
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

    Node* findByDepth(int depth){
        Node* tmp;
        for (int i = 0; i < nodelist.size(); i++) {
            if (nodelist[i]->depth == depth) {
                tmp = nodelist[i];
            }
        }
        return tmp;
    }
    void insertNode(int parentData, int childData, int depth) {
        Node *cur = findNode(parentData);
        Node *newNode = new Node(cur, childData, depth);
        cur->child.push_back(newNode);
        nodelist.push_back(newNode);
    }

    void traverse(Node *cur) {

        for (int i = 0; i < cur->child.size(); i++) {
            traverse(cur->child[i]);
        }
        if(cur == root) cout << 1 << ' ';
        else cout << cur->data << ' ';
    }


};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int cnt;
        cin >> cnt;
        int traverseResult[cnt];
        int traverseDepth[cnt];
        Tree tree;
        for (int i = 0; i < cnt; i++) {
            cin >> traverseResult[i];
        }
        for (int i = 0; i < cnt; i++) {
            cin >> traverseDepth[i];
        }

        for(int i = 1; i < cnt; i++){
            if(traverseDepth[i] > traverseDepth[i-1]){
                tree.insertNode(traverseResult[i-1], traverseResult[i], traverseDepth[i]);
            }
            if(traverseDepth[i] == traverseDepth[i-1]){
                Node* tmp = tree.findNode(traverseResult[i-1]);
                tree.insertNode(tmp->parent->data, traverseResult[i], traverseDepth[i]);
            }
            if(traverseDepth[i] < traverseDepth[i-1]) {
                Node* tmp = tree.findByDepth(traverseDepth[i] - 1);
                tree.insertNode(tmp->data, traverseResult[i], traverseDepth[i]);
            }
        }
        tree.traverse(tree.getRoot());
        cout << endl;
    }

}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node *parent;
    vector<Node *> child;
    int data;
    int depth;

    Node(int data) {
        parent = NULL;
        this->data = data;
        depth = 0;
    }

    Node(Node *node, int data) {
        parent = node;
        this->data = data;
        depth = 0;
    }
    Node(Node *node, int data, int depth) {
        parent = node;
        this->data = data;
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

    Node *findNode(int data) {
        for (int i = 0; i < nodelist.size(); i++) {
            if (nodelist[i]->data == data) {
                return nodelist[i];
            }
        }
        return NULL;
    }

    void insertNode(int parentData, int childData) {
        int cnt = 1;
        Node* parNode = findNode(parentData);
        while(parNode != root){
            cnt++;
            parNode = parNode->parent;
        }
        parNode = findNode(parentData);
        Node *newNode = new Node(parNode, childData, cnt + 1);
        parNode->child.push_back(newNode);
        nodelist.push_back(newNode);
    }

    void deleteNode(int data) {
        if (nodelist.size() == 1) {
            cout << -1 << endl;
            return;
        }
        Node *oldNode = findNode(data);
        if (oldNode == NULL) {
            cout << -1 << endl;
            return;
        }
        Node* parent = oldNode->parent;

        for(int i = 0; i < oldNode->child.size(); i++){
            oldNode->child[i]->parent = parent;
            parent->child.push_back(oldNode->child[i]);
        }
        for(int i = 0; i < parent->child.size(); i++){
            if(parent->child[i] == oldNode){
                parent->child.erase(parent->child.begin() + i);
                break;
            }
        }
        for(int i = 0; i < nodelist.size(); i++){
            if(nodelist[i] == oldNode){
                nodelist.erase(nodelist.begin() + i);
                break;
            }
        }
        delete oldNode;
    }

    void print(int data) {
        Node* node = findNode(data);
        if(node == NULL){
            cout << -1 << endl;
            return;
        }
        if(node == root){
            cout << 1 << endl;
            return;
        }
        cout << node->depth << endl;
    }
};

int main() {
    int nodeCount;
    int tc;
    cin >> nodeCount >> tc;
    Tree tree;
    for(int i = 0; i < nodeCount; i++){
        int n,m;
        cin >> n >> m;
        tree.insertNode(n,m);
    }
    while(tc--){
        int n;
        cin >> n;
        tree.print(n);
    }
}

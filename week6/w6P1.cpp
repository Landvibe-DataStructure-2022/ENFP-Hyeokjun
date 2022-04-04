#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node *parent;
    vector<Node *> child;
    int data;

    Node() {
        parent = NULL;
        data = 0;
    }

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
        Node *parNode = findNode(parentData);
        if (parNode == NULL) {
            cout << -1 << endl;
            return;
        }
        Node *newNode = new Node(parNode, childData);
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
        if(node->child.size() == 0 || node == NULL) {
            cout << -1 << endl;
            return;
        }
        for(int i = 0; i < node->child.size(); i++){
            cout << node->child[i]->data << ' ';
        }
        cout << endl;
    }
};

int main() {
    int tc;
    cin >> tc;
    Tree tree;
    string query;
    while(tc--){
        cin >> query;
        if(query == "insert"){
            int n, m;
            cin >> n >> m;
            tree.insertNode(n,m);
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

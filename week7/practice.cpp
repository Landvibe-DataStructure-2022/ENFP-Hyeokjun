//W7P4 2nd sol

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    int depth;
    Node *parent;
    vector<Node *> children;

    Node() {
        data = 0;
        parent = NULL;
    }

    Node(int data, int depth) {
        parent = NULL;
        this->data = data;
        this->depth = depth;
    }

};

class Tree {
public:
    Node *root;
    vector<Node *> nodeList;

    Node *findNode(int data) {
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i]->data == data) {
                return nodeList[i];
            }
        }
        return NULL;
    }

    Node *findDepth(int depth) {
        Node *tmp;
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i]->depth == depth) {
                tmp = nodeList[i];
            }
        }
        return tmp;
    }

    void insertNode(int parent, int data, int depth) {
        Node *parNode = findNode(parent);
        Node *newNode = new Node(data, depth);
        newNode->parent = parNode;
        parNode->children.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void preTrav(Node* cur){
        cout << cur->data << ' ';
        for(int i = cur->children.size() - 1; i >= 0; i--){
            preTrav(cur->children[i]);
        }
    }

    void postTrav(Node* cur){

        for(int i = cur->children.size() - 1; i >= 0; i--){
            postTrav(cur->children[i]);
        }
        cout << cur->data << ' ';
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        Tree tree;
        int n;
        cin >> n;
        int data[n];
        int depth[n];
        for (int i = n - 1; i >= 0; i--) {
            cin >> data[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            cin >> depth[i];
        }
        Node *rootNode = new Node(data[0], depth[0]);
        tree.root = rootNode;
        tree.nodeList.push_back(rootNode);
        for (int i = 1; i < n; i++) {
            if (depth[i] > depth[i - 1]) {
                Node* parNode = tree.findDepth(depth[i] - 1);
                tree.insertNode(parNode->data, data[i], depth[i]);
            } else if (depth[i] == depth[i - 1]) {
                Node* parNode = tree.findNode(data[i-1])->parent;
                tree.insertNode(parNode->data, data[i], depth[i]);
            } else if (depth[i] < depth[i - 1]) {
                tree.insertNode(data[i - 1], data[i], depth[i]);
            }
        }
        tree.postTrav(tree.root);
        cout << endl;
        tree.preTrav(tree.root);
        cout << endl;
    }
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    int depth;
    Node *parent;
    vector<Node *> child;

    Node(int data, int depth) {
        this->data = data;
        this->depth = depth;
    }

    Node(Node *parent, int data) {
        this->parent = parent;
        this->data = data;
    }
};

class Tree {
public:
    Node *root;
    vector<Node *> nodelist;

    Node *findNode(int data) {
        for (int i = 0; i < nodelist.size(); i++) {
            if (nodelist[i]->data == data) {
                return nodelist[i];
            }
        }
        return NULL;
    }

    void insertNode(int parentData, int childData, int depth) {
        Node *cur = findNode(parentData);
        Node *newNode = new Node(cur, childData);
        cur->child.push_back(newNode);
        nodelist.push_back(newNode);
    }
    void dfs(Node *cur) {
        cout << cur->data << ' ';

        for(int i = cur->child.size() - 1; i >= 0; i--){
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

        int traverseData[cnt];
        int traverseDepth[cnt];
        Tree tree;
        vector<Node *> tmpNode;
        for (int i = 0; i < cnt; i++) {
            cin >> traverseData[i];
        }
        for (int i = 0; i < cnt; i++) {
            cin >> traverseDepth[i];
        }

        for (int i = 0; i < cnt; i++) {
            Node *newNode = new Node(traverseData[i], traverseDepth[i]);
            if (traverseData[i] == 1) {
                tree.root = newNode;
            }
            if (traverseDepth[i] < traverseDepth[i - 1]) {
                while (tmpNode.size() != 0 && tmpNode.back()->depth > newNode->depth) {
                    tmpNode.back()->parent = newNode;
                    newNode->child.push_back(tmpNode.back());
                    tmpNode.pop_back();
                }

            }

            tmpNode.push_back(newNode);

        }
        tree.dfs(tree.root);
        cout << endl;
    }
}
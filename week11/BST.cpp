#include <iostream>
#include <string>

using namespace std;
int cnt = 0;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *par;

    Node() {
        key = 0;
        left = NULL;
        right = NULL;
        par = NULL;
    }

};

class BST {
private:
    Node *root;
    int size;
public:
    BST() {
        root = NULL;
        size = 0;
    }

    void insert(int key) {
        Node *newNode = new Node();
        newNode->key = key;

        if (root == NULL) {
            root = newNode;
        } else {
            Node *cur = root;
            while (true) {
                if (key < cur->key) {
                    if (cur->left != NULL) {
                        cur = cur->left;
                    } else {
                        newNode->par = cur;
                        cur->left = newNode;
                        break;
                    }
                } else if (key > cur->key) {
                    if (cur->right != NULL) {
                        cur = cur->right;
                    } else {
                        newNode->par = cur;
                        cur->right = newNode;
                        break;
                    }
                }
            }
        }

    }

    void deletion(int key) {
        Node *cur = search(key);

        bool isLeft = false;

        if (cur != root) {
            if (cur == cur->par->left) {
                isLeft = true;
            } else if (cur == cur->par->right) {
                isLeft = false;
            }
        }

        if (cur->left == NULL && cur->right == NULL) {
            if (cur == root) {
                root = NULL;
                delete cur;
            } else {
                if (isLeft) {
                    cur->par->left = NULL;
                    delete cur;
                } else {
                    cur->par->right = NULL;
                    delete cur;
                }
            }
        } else if (cur->left != NULL && cur->right == NULL) {
            if (cur == root) {
                root = cur->left;
            } else {
                if (isLeft) {
                    cur->par->left = cur->left;
                    cur->left->par = cur->par;
                } else {
                    cur->par->right = cur->left;
                    cur->left->par = cur->par;
                }
            }
            delete cur;
        } else if (cur->left == NULL && cur->right != NULL) {
            if (cur == root) {
                root = cur->right;
            } else {
                if (isLeft) {
                    cur->par->left = cur->right;
                    cur->right->par = cur->par;
                } else {
                    cur->par->right = cur->right;
                    cur->right->par = cur->par;
                }
            }
            delete cur;
        } else {
            Node *tmp = cur->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            int trash = tmp->key;
            deletion(trash);
            cur->key = trash;

        }
    }

    void sub(Node *cur) {
        if (cur == NULL) {
            return;
        }
        sub(cur->left);
        cnt++;
        sub(cur->right);
    }

    Node *search(int key) {

        Node *cur = root;
        while (cur != NULL) {
            if (key < cur->key) {
                cur = cur->left;
            } else if (key > cur->key) {
                cur = cur->right;
            } else if (cur->key == key) {
                return cur;
            }
        }
        return NULL;
    }
};

int main() {
    int tc;
    cin >> tc;
    BST bst;
    string q;
    while (tc--) {
        cin >> q;
        if (q == "insert") {
            int n;
            cin >> n;
            bst.insert(n);
        } else if (q == "delete") {
            int n;
            cin >> n;
            bst.deletion(n);
        } else if (q == "sub") {
            int n;
            cin >> n;
            bst.sub(bst.search(n));
            cout << cnt << endl;
            cnt = 0;
        }
    }
}
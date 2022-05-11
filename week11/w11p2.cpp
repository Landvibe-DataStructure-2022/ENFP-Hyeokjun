#include <iostream>
#include <string>

using namespace std;
int cnt = 0;

struct Node {
    Node *par;
    Node *left;
    Node *right;
    int elem;

    Node(int elem) {
        this->elem = elem;
        par = left = right = NULL;
    }
};

class BST {
private:
public:
    Node *root;
    int size;

    BST() {
        root = NULL;
        size = 0;
    }

    void insert(int elem) {
        Node *newNode = new Node(elem);

        if (size == 0) {
            root = newNode;
        } else {
            Node *cur = root;
            while (true) {
                if (elem > cur->elem) {
                    if (cur->right == NULL) {
                        cur->right = newNode;
                        newNode->par = cur;
                        break;
                    } else {
                        cur = cur->right;
                    }
                } else {
                    if (cur->left == NULL) {
                        cur->left = newNode;
                        newNode->par = cur;
                        break;
                    } else {
                        cur = cur->left;
                    }
                }
            }
        }
        size++;
    }

    void deletion(int elem) {

        Node *cur = search(elem);
        bool isLeft = false;
        if (cur != root) {
            if (cur->par->left == cur) {
                isLeft = true;
            } else {
                isLeft = false;
            }
        }

        if (cur->left == NULL && cur->right == NULL) {
            if (cur == root) {
                root = NULL;
            } else {
                if (isLeft) {
                    cur->par->left = NULL;
                } else {
                    cur->par->right = NULL;
                }
            }
            delete cur;
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
        } else {
            Node *tmp = cur->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            int trash = tmp->elem;
            deletion(trash);
            cur->elem = trash;
        }
    }

    Node *search(int elem) {
        Node *cur = root;
        while (cur != NULL) {

            if (elem > cur->elem) {
                cur = cur->right;
            } else if (elem < cur->elem) {
                cur = cur->left;
            } else {
                break;
            }
        }
        return cur;
    }

    void sub(int elem) {
        Node *cur = search(elem);
        if (cur == NULL) {
            cout << 0 << endl;
            return;
        }
        cnt = 0;
        inOrder(cur);
        cout << cnt << endl;
    }

    void inOrder(Node *p) {
        if (p->left != NULL) {
            inOrder(p->left);
        }
        cnt++;
        if (p->right != NULL) {
            inOrder(p->right);
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    BST bst;
    while (tc--) {
        string q;
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
            bst.sub(n);
        }
    }
}
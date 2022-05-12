//이진 탐색트리 구조
//1. 각 노드에 중복되지 않는 키(key)가 있다.
//2. 루트노드의 왼쪽 서브 트리는 해당 노드의 키보다 작은 키를 갖는 노드들로 이루어져 있다.
//3. 루트노드의 오른쪽 서브 트리는 해당 노드의 키보다 큰 키를 갖는 노드들로 이루어져 있다.
//4. 좌우 서브 트리도 모두 이진 탐색 트리여야 한다.


#include <iostream>
#include <string>

using namespace std;
int cnt = 0;

struct Node {

    int elem;
    Node *par;
    Node *left;
    Node *right;

    Node(int elem) {
        this->elem = elem;
        par = NULL;
        left = right = NULL;
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

    void insert(int e) {
        Node *newNode = new Node(e);
        if (size == 0) {
            root = newNode;
        } else {
            Node *cur = root;
            while (true) {
                if (e > cur->elem) {
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

    void traversal(Node* cur){
        if(cur == NULL){
            return;
        }

        traversal(cur->left);
        cout << cur->elem << ' ';
        traversal(cur->right);
    }

};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cnt = 0;
        BST bst;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            bst.insert(k);
        }

        bst.traversal(bst.root);
        cout << endl;
    }
}
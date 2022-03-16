//
// Created by ±««ı¡ÿ on 2022/03/16.
//

#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int top, maxSize;
    int *stack;
public:
    Stack(int size) {
        top = -1;
        maxSize = size;
        stack = new int[size];
    }

    ~Stack() {
        delete[] stack;
    }

    bool isFull() {
        if (top == maxSize - 1) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() {
        if (top == -1) return true;
        else return false;
    }

    void empty() {
        if (isEmpty()) cout << "1" << endl;
        else cout << "0" << endl;
    }

    void push(int data) {
        if (isFull()) {
            cout << "FULL" << endl;
            return;
        } else {
            stack[++top] = data;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << -1 << endl;
        } else {
            cout << stack[top--] << endl;
        }
    }

    void Top() {
        if (isEmpty()) {
            cout << "-1" << endl;
        } else cout << stack[top] << endl;

    }
};

int main() {
    int n;
    int t;
    string query;
    cin >> n >> t;
    Stack st(n);

    while (t--) {
        cin >> query;
        if (query == "empty") {
            st.empty();
        } else if (query == "pop") {
            st.pop();
        } else if (query == "push") {
            int n;
            cin >> n;
            st.push(n);
        } else if (query == "top") {
            st.Top();
        }
    }
}
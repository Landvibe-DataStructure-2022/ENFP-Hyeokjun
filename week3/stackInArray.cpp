//
// Created by ±««ı¡ÿ on 2022/03/16.
//

#include <iostream>
#include <string>

using namespace std;


class Stack {
private:
    int size, maxSize;
    int *arr;
public:
    Stack(int sz) {
        size = 0;
        maxSize = sz;
        arr = new int[sz];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        if (size == maxSize) {
            return true;
        } else return false;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        } else return false;
    }

    void empty() {
        if (isEmpty()) cout << 1 << endl;
        else cout << 0 << endl;
    }

    void top() {
        if (isEmpty()) {
            cout << -1 << endl;
            return;
        } else cout << arr[size - 1] << endl;
    }

    void push(int data) {
        if (isFull()) {
            cout << "FULL" << endl;
            return;
        }
        arr[size] = data;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << -1 << endl;
            return;
        }
        cout << arr[size - 1] << endl;
        size--;
    }
};

int main() {
    int n, t;
    cin >> n >> t;
    string query;
    Stack st(n);
    while (t--) {
        cin >> query;
        if (query == "empty") {
            st.empty();
        } else if (query == "pop") {
            st.pop();
        } else if (query == "push") {
            int x;
            cin >> x;
            st.push(x);
        } else if (query == "top") {
            st.top();
        }
    }
}
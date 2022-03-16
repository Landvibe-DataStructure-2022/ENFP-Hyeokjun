
//
// Created by ±««ı¡ÿ on 2022/03/16.
//

#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int top, maxSize;
    int *elem;
public:
    Stack(int size) {
        top = -1;
        maxSize = size;
        elem = new int[maxSize];
    }

    ~Stack() {
        delete[] elem;
    }

    void push(int i) {
        elem[++top] = i;
    }

    int pop() {
        return elem[top--];
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            cout << elem[i] << ' ';
        }
    }

    int Top(){
        return elem[top];
    }
};

int main() {
    int t;
    cin >> t;
    int a, b;

    while (t--) {
        string s;
        cin >> s;

        Stack st(s.length());
        for (int i = 0; i < s.length(); i++) {
            if ('0' < s[i] && s[i] <= '9') {
                int x = (int) (s[i] - '0');
                st.push(x);
            } else if (s[i] == '+') {
                a = st.pop();
                b = st.pop();
                st.push(a + b);
            } else if (s[i] == '-') {
                a = st.pop();
                b = st.pop();
                st.push(b - a);
            } else if (s[i] == '*') {
                a = st.pop();
                b = st.pop();
                st.push(a * b);
            }

        }
        cout << st.pop()<< endl;

    }
}
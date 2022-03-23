#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    int maxSize;
    int queueSize;
    int index;
    int *arr;
public:
    Queue(int size) {
        maxSize = size;
        queueSize = 0;
        arr = new int[size];
    }
    bool isFull() {
        return (maxSize == queueSize);
    }
    bool isEmpty() {
        return (queueSize == 0);
    }
    void dequeue() {
        if(isEmpty()) return;
        int dequeueValue = arr[0];
        cout << arr << endl;
        cout << &arr[0] << endl;
        arr = arr + 1;
        cout << arr << endl;
        cout << &arr[0] << endl;
        queueSize--;
        print();
    }
    void enqueue(int value) {
        if(isFull()) return;
        arr[queueSize] = value;
        queueSize++;
        print();
    }

    void print() {
        if(isEmpty()) return;
        for(int i = 0; i < queueSize; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    int size;
    string key;
    cin >> size;
    Queue q(size);

    while(1){
        cin >> key;
        if(key == "print"){
            q.print();
        } else if (key == "enqueue") {
            int n;
            cin >> n;
            q.enqueue(n);
        } else if (key == "dequeue") {
            q.dequeue();
        }
    }
}
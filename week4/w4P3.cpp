#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
    int frontIndex;
    int rearIndex;
    int maxSize;
    int queueSize;
    int *arr;
public:
    Queue(int);

    ~Queue();

    bool isEmpty();

    bool isFull();

    void enqueue(int);

    void dequeue();

    int size();

    int rear();

    int front();

    void print();
};

int main() {
    int n, t;
    string query;
    cin >> n >> t;
    Queue q(n);
    while (t--) {
        cin >> query;
        if (query == "enqueue") {
            int data;
            cin >> data;
            q.enqueue(data);
        } else if (query == "dequeue") {
            q.dequeue();
        } else if (query == "isEmpty") {
            if (q.isEmpty()) cout << "True" << endl;
            else cout << "False" << endl;
        } else if (query == "size") {
            cout << q.size() << endl;
        } else if (query == "front") {
            if (q.front() == -1) cout << "Empty" << endl;
            else cout << q.front() << endl;
        } else if (query == "rear") {
            if (q.rear() == -1) cout << "Empty" << endl;
            else cout << q.rear() << endl;
        }
    }
}

Queue::Queue(int size) {
    frontIndex = 0;
    rearIndex = -1;
    maxSize = size;
    queueSize = 0;
    arr = new int[size];
}

Queue::~Queue() {
    delete[] arr;
}

bool Queue::isEmpty() {
    return (queueSize == 0);
}

bool Queue::isFull() {
    return (queueSize == maxSize);
}

int Queue::size() {
    return queueSize;
}

int Queue::front() {
    if (isEmpty()) return -1;
    return arr[frontIndex];
}

int Queue::rear() {
    if (isEmpty()) return -1;
    return arr[rearIndex];
}

void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Full" << endl;
        return;
    }
    rearIndex++;
    rearIndex %= maxSize;
    arr[rearIndex] = value;
    queueSize++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Empty" << endl;
        return;
    }
    cout << arr[frontIndex] << endl;
    frontIndex++;
    frontIndex %= maxSize;
    queueSize--;
}

void Queue::print() {
    if (isEmpty()) return;
    int index = frontIndex;
    for (int i = 0; i < queueSize; i++) {
        cout << arr[index] << ' ';
        index++;
        index %= maxSize;
    }

}

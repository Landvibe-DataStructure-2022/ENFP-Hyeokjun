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
    int front();
    void print();
};

int main() {

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
    if (isEmpty()) return NULL;
    return arr[frontIndex];
}

void Queue::enqueue(int value) {
    if (isFull()) return;
    rearIndex++;
    rearIndex %= maxSize;
    arr[rearIndex] = value;
    queueSize++;
    print();
}

void Queue::dequeue() {
    if (isEmpty()) return;
    cout << arr[frontIndex] << endl;
    frontIndex++;
    frontIndex %= maxSize;
    queueSize--;
    print();
}

void Queue::print() {
    if (isEmpty()) return;
    for (int i = frontIndex; i <= rearIndex; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
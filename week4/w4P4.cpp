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

    int dequeue();

    int size();

    int front();

    void print();
};

int main() {
    int tc;


    cin >> tc;
    while (tc--) {
        int scoreP1 = 0, scoreP2 = 0;
        int cardRound;
        int cardEach;
        int bonus;
        int winner = 0;

        cin >> cardRound;
        Queue P1(cardRound);
        Queue P2(cardRound);
        for (int i = 0; i < cardRound; i++) {
            cin >> cardEach;
            P1.enqueue(cardEach);
        }
        for (int i = 0; i < cardRound; i++) {
            cin >> cardEach;
            P2.enqueue(cardEach);
        }


        for (int i = 0; i < cardRound; i++) {
            int p1 = P1.dequeue();
            int p2 = P2.dequeue();
            if (winner == 1) {
                p2 += bonus;
            } else if (winner == 2) {
                p1 += bonus;
            }
            if (p1 > p2) {
                scoreP1++;
                bonus = (p1 - p2);
                winner = 1;
            } else if (p2 > p1) {
                scoreP2++;
                bonus = (p2 - p1);
                winner = 2;
            } else {
                winner = 0;
            }

        }

        if (scoreP1 > scoreP2) cout << scoreP1 << endl;
        else if (scoreP2 > scoreP1) cout << scoreP2 << endl;
        else cout << scoreP1 << endl;
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
    if (isEmpty()) return NULL;
    return arr[frontIndex];
}

void Queue::enqueue(int value) {
    if (isFull()) return;
    rearIndex++;
    rearIndex %= maxSize;
    arr[rearIndex] = value;
    queueSize++;
}

int Queue::dequeue() {
    if (isEmpty()) return -1;
    int i = arr[frontIndex];
    frontIndex++;
    frontIndex %= maxSize;
    queueSize--;
    return i;
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
#include <iostream>
#include <string>

using namespace std;

struct Entry {
    int key;
    bool available;

    Entry() {
        key = 0;
        available = true;
    }

};

class HashTable {
public:
    Entry *table;
    int maxSizeA;
    int maxSizeB;
    int curA;
    int curB;
    bool doubleRotate;

    HashTable(int maxSizeA, int maxSizeB) {
        this->maxSizeA = maxSizeA;
        this->maxSizeB = maxSizeB;
        curA = curB = 0;
        table = new Entry[maxSizeA + 1];
        doubleRotate = false;
    }

    int hashFunction(int laps, bool clock, bool isA) {

        if (isA) {
            if (!clock) {
                return (curA + (laps % maxSizeA)) % maxSizeA;
            } else {
                if (curA >= (laps % maxSizeA)) {
                    return curA - (laps % maxSizeA);
                } else {
                    return maxSizeA + (curA - (laps % maxSizeA));
                }
            }
        } else {
            if (!clock) {
                return (curB + (laps % maxSizeB)) % maxSizeB;
            } else {
                if (curB >= (laps % maxSizeB)) {
                    return curB - (laps % maxSizeB);
                } else {
                    return maxSizeB + (curB - (laps % maxSizeB));
                }
            }
        }
    }

    void rotateA(int laps) {
        // 반시계 -> 양의 방향

//        cout << "해쉬 전 curA : " << curA + 1 << " curB : " << curB + 1 << endl;
        curA = hashFunction(laps, false, true);
        curB = hashFunction(laps, true, false);
//        cout << "해쉬 후 curA : " << curA + 1 << " curB : " << curB + 1 << endl;
        if (table[curA].available) {

            table[curA].available = false;
            cout << curA + 1 << ' ';
            if (doubleRotate) {
//                cout << "2번에서 해결 ";
//                cout << "curA : " << curA + 1 << " curB : " << curB + 1 << endl;
            } else {
//                cout << "1번에서 해결 ";
//                cout << "curA : " << curA + 1 << " curB : " << curB + 1 << endl;
            }
            doubleRotate = false;
            return;
        } else {
            if (doubleRotate) {
                rotateB();
            } else {
                doubleRotate = true;
                rotateA(curB + 1);

            }
        }
    }

    void rotateB() {
//        cout << "B해쉬 전 curA : " << curA + 1 << " curB : " << curB + 1 << endl;
        while (!table[curA].available) {
            curA = hashFunction(1, true, true);
            curB = hashFunction(1, false, false);
        }

        table[curA].available = false;
        cout << curA + 1 << ' ';
//        cout << "3번에서 해결 ";
//        cout << "B 해쉬 후 curA : " << curA + 1 << " curB : " << curB + 1 << endl;
        doubleRotate = false;
    }


};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, cnt;
        cin >> n >> m >> cnt;
        HashTable hst(n, m);
        for (int i = 0; i < cnt; i++) {
            int k;
            cin >> k;
            hst.rotateA(k);
        }
        cout << '\n';
    }
}


#include <iostream>
#include <string>

using namespace std;

struct Entry {
    bool available;

    Entry() {
        available = true;
    }
};

class HashTable {
public:
    Entry *table;
    int maxSizeA, maxSizeB;
    int curA, curB;
    bool doubleRotate;

    HashTable(int maxSizeA, int maxSizeB) {
        this->maxSizeA = maxSizeA;
        this->maxSizeB = maxSizeB;
        curA = curB = 0;
        doubleRotate = false;
        table = new Entry[maxSizeA];
    }

    int hash(int key, bool isClock, bool isA) {
        if (isA) {
            if (isClock) {
                if (curA >= (key % maxSizeA)) {
                    return curA - key % maxSizeA;
                } else {
                    return (maxSizeA + (curA - key % maxSizeA));
                }
            } else {
                return (curA + key % maxSizeA) % maxSizeA;
            }
        } else { // 반시계 -> 양의방향 시계 -> 음의방향
            if (isClock) {
                if (curB >= (key % maxSizeB)) {
                    return curB - key % maxSizeB;
                } else {
                    return (maxSizeB + (curB - key % maxSizeB));
                }
            } else {
                return (curB + key % maxSizeB) % maxSizeB;
            }
        }
    }

    void rotateA(int laps){
        if(!doubleRotate) {
            curA = hash(laps, false, true);
            curB = hash(laps, true, false);
        }
        else {
            curA = hash(laps, true, true);
            curB = hash(laps, false, false);
        }
        if(table[curA].available == true){
            table[curA].available = false;
            cout << curA + 1 << ' ';
            doubleRotate = false;
            return;
        } else{
            if(doubleRotate){
                rotateB();
            } else {
                doubleRotate = true;
                rotateA(curB + 1);
            }
        }
    }

    void rotateB(){
        while(!table[curA].available){
            curA = hash(1, false, true);
            curB = hash(1, true, false);
        }
        table[curA].available = false;
        cout << curA + 1 << ' ';
        doubleRotate = false;
    }

};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m, cnt;
        cin >> n >> m >> cnt;
        HashTable hst(n, m);
        while(cnt--){
            int k;
            cin >> k;
            hst.rotateA(k);
        }
        cout << '\n';
    }
}
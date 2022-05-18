#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    bool available;

    Node() {
        key = 0;
        available = true;
    }

    Node(int key) {
        this->key = key;
        available = true;
    }
};

class hashTable {
public:

   int maxSizeA, maxSizeB;
   int curA, curB;
   bool doubleRotate;
   Node* table;

   hashTable(int maxSizeA, int maxSizeB){
       this->maxSizeA = maxSizeA + 1;
       this->maxSizeB = maxSizeB + 1;
       table = new Node[this->maxSizeA];
       curA = curB = 1;
       doubleRotate = false;
       init();
   }

   void init(){

       for(int i = 0; i < maxSizeA; i++){
           table[i] = Node();
       }
       table[0].available = false;
   }

   int hashingA(int key){
       if(key == maxSizeA){
           key = 1;
       }
       if(key == 0){
           key = maxSizeA - 1;
       }
       return key % maxSizeA;
   }
   int hashingB(int key){
       if(key == maxSizeB){
           key = 1;
       }
       if(key == 0){
           key = maxSizeB - 1;
       }
       return key % maxSizeB;
   }
   void rotateA(int laps){
        for(int i = 0; i < laps; i++){
            curA = hashingA(++curA);
            curB = hashingB(--curB);
        }
        if(table[curA].available){
            table[curA].available = false;
            cout << curA << ' ';
            doubleRotate = false;
            return;
        } else {
            if(doubleRotate){
                rotateB();
            } else {
                doubleRotate = true;
                hashingB(curB);
                rotateA(curB);

            }
        }
   }

   void rotateB(){
       while(!table[curA].available){
           curA = hashingA(--curA);
           curB = hashingB(++curB);
       }
       table[curA].available = false;
       cout << curA << ' ';
       doubleRotate = false;
   }

};

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        int n, m, cnt;
        cin >> n >> m >> cnt;
        hashTable hst(n, m);
        for(int i = 0; i < cnt; i++){
            int k;
            cin >> k;
            hst.rotateA(k);
        }
        cout << '\n';
    }
}
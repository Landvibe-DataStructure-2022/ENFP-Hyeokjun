#include <iostream>
#include <string>

using namespace std;

struct Entry {
    int key;
    string value;
    int available; // 0->empty 1->available 2->full

    Entry() {
        key = 0;
        value = "";
        available = 0;
    }

    Entry(int key, string value) {
        this->key = key;
        this->value = value;
        available = 2;
    }

    void deletion() {
        key = 0;
        value = "";
        available = 1;
    }
};

class HashTable {
public:
    Entry *table;
    int maxSize;
    int divisor;

    HashTable(int maxSize, int divisor) {
        this->maxSize = maxSize;
        table = new Entry[maxSize];
        this->divisor = divisor;
    }

    int LinearHash(int key) {
        return key % maxSize;
    }

    int DoubleHash(int key) {
        return divisor - (key % divisor);
    }

    void put(int key, string value) {
        int index = LinearHash(key);
        int probe = 1;

        while(true){
            if(table[index].available != 2){
                table[index] = Entry(key, value);
                cout << probe << endl;
                return;
            }

            index = LinearHash(index + DoubleHash(key));
            probe++;

            if(probe > maxSize){
                return;
            }
        }


    }

    void erase(int key) {
        int index = LinearHash(key);
        int probe = 1;
        while(true){
            if(table[index].available == 0){
                cout << "None" << endl;
                return;
            }
            if(table[index].key == key){
                table[index].deletion();
                return;
            }

            index = LinearHash(index + DoubleHash(key));
            probe++;
            if(probe > maxSize){
                cout << "None" << endl;
                return;
            }
        }
    }

    void find(int key) {
        int index = LinearHash(key);
        int probe = 1;
        while(true){
            if(table[index].available == 0){
                cout << "None" << endl;
                return;
            }
            if(table[index].key == key){
                cout << table[index].value << endl;
                return;
            }

            index = LinearHash(index + DoubleHash(key));
            probe++;
            if(probe > maxSize){
                cout << "None" << endl;
                return;
            }
        }
    }
};

int main() {
    int tc, size, divisor;
    cin >> tc >> size >> divisor;
    HashTable hst(size, divisor);
    while (tc--) {
        string q;
        cin >> q;

        if (q == "put") {
            int k; string v;
            cin >> k >> v;

            hst.put(k,v);
        } else if (q == "erase") {
            int k;
            cin >> k;
            hst.erase(k);
        } else if (q == "find") {
            int k;
            cin >> k;
            hst.find(k);
        }
    }
}

// 처리할 부분 : valid가 noitem인지
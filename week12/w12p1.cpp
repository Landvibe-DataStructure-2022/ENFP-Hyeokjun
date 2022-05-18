#include <iostream>
#include <string>

using namespace std;

struct Entry {
    int key;
    string value;
    int available; // 0->empty 1->avilable 2->full

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

    HashTable(int maxSize) {
        this->maxSize = maxSize;
        table = new Entry[maxSize];
    }

    int hash(int key) {
        return key % maxSize;
    }

    void put(int key, string value) {
        int index = hash(key);
        int probe = 1;
        while (true) {
            if (table[index].available != 2) {
                table[index] = Entry(key, value);
                cout << probe << endl;
                return;
            }

            index = hash(++index);
            probe++;

            if (index == hash(key)) {
                return;
            }
        }

    }

    void erase(int key) {
        int index = hash(key);

        while (true) {
            if (table[index].available == 0) {
                cout << "None" << endl;
                return;
            }
            if (table[index].key == key) {
                table[index].deletion();
                return;
            }
            index = hash(++index);

            if (index == hash(key)) {
                cout << "None" << endl;
                return;
            }
        }
    }

    void find(int key) {
        int index = hash(key);

        while (true) {
            if (table[index].available == 0) {
                cout << "None" << endl;
                return;
            }
            if (table[index].key == key) {
                cout << table[index].value << endl;
                return;
            }
            index = hash(++index);

            if (index == hash(key)) {
                cout << "None" << endl;
                return;
            }
        }
    }
};

int main() {
    int tc, size;
    cin >> tc >> size;
    HashTable hst(size);
    while (tc--) {
        string q;
        cin >> q;

        if (q == "put") {
            int k;
            string v;
            cin >> k >> v;
            hst.put(k, v);
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
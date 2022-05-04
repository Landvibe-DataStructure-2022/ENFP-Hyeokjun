#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Heap {
private:
    vector<int> arr;

    void swap(int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    void upHeap(int idx) {
        if (idx == 1) return;

        int parent = idx / 2;
        if (arr[idx] < arr[parent]) {
            swap(idx, parent);
            upHeap(parent);
        }
    }

    void downHeap(int idx) {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int child;

        if (left > size()) {
            return;
        } else if (left == size()) {
            child = left;
        } else {
            if (arr[left] <= arr[right]) {
                child = left;
            } else child = right;
        }
        if (arr[child] < arr[idx]) {
            swap(child, idx);
            downHeap(child);
        }
    }

public:
    Heap() {
        arr.push_back(0);
    }

    void insert(int e) {
        arr.push_back(e);
        upHeap(size());
    }

    int size() {
        return arr.size() - 1;
    }

    bool empty() {
        return arr.size() == 1;
    }

    int min() {
        if (empty()) {
            return -1;
        }
        return arr[1];
    }

    void removeMin() {
        if (empty()) return;
        swap(1, size());
        arr.pop_back();
        downHeap(1);
    }

    void print() {
        for (int i = 1; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }


};

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        Heap h;
        int count, maxTemp;
        int tempNow = 0;
        cin >> count >> maxTemp;
        for (int i = 0; i < count; i++) {
            int n;
            cin >> n;
            h.insert(n);
        }

        while (h.min() < maxTemp) {
            if(h.size() == 1) {
                cout << "False" << endl;
                tempNow = -1;
                break;
            }
            int v1 = h.min();
            h.removeMin();
            int v2 = h.min();
            h.removeMin();
            tempNow = (v1 + v2) / 2;
            h.insert(tempNow);
        }

        if(tempNow != -1) {
            cout << "True" << endl;
            h.print();
        }
    }
}
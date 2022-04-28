#include <iostream>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const int &e1, const int &e2) const {
        return e1 < e2;
    }
};

class unsortedSeqPQ {
public:
    int size() { return seq.size(); }

    bool empty() { return seq.size() == 0; }

    void insert(int e) { seq.push_back(e); }

    int min() {
        if (empty()) return -1;

        int minVal = seq[0];

        for (int i = 0; i < seq.size(); i++) {
            if (C(seq[i], minVal)) {
                minVal = seq[i];
            }
        }
        return minVal;
    }

    void removeMin() {
        if (empty()) return;
        int minIdx = 0;

        for (int i = 0; i < seq.size(); i++) {
            if (C(seq[i], seq[minIdx])) {
                minIdx = i;
            }
        }

        seq.erase(seq.begin() + minIdx);
    }

private:
    vector<int> seq;
    compare C;
};

class sortedSeqPQ {
private:
    vector<int> seq;
    compare C;
public:
    int size() { return seq.size(); }

    bool empty() { return seq.size() == 0; }

    void insert(int e) {
        int idx;
        for (int i = 0; i < seq.size(); i++) {
            if (C(seq[i], e)) {
                idx = i;
                break;
            }
        }
        seq.insert(seq.begin() + idx, e);
    }

    int min() {
        if (empty()) return -1;
        return seq.back();
    }

    void removeMin() {
        if(empty()) return;
        seq.pop_back();
    }
};

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

//        int idx = 0;
//        for (int i = 0; i < seq.size(); i++) {
//            if (C(seq[idx], e)) {
//                idx = i;
//                cout << idx << ' ';
//                break;
//            }
//        }
//
        int idx = 0;
        for (idx = 0; idx < seq.size(); idx++) {
            if (C(seq[idx], e)) {
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

int main() {
    int tc;
    cin >> tc;

    while(tc--){
        sortedSeqPQ spq;
        vector<int> seq;
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            seq.push_back(m);
        }
        while(!seq.empty()){
            spq.insert(seq.back());
            seq.pop_back();
        }
        while(!spq.empty()){
            seq.push_back(spq.min());
            spq.removeMin();
        }
        for(int i = 0; i < seq.size(); i++){
            cout << seq[i] << ' ';
        }
        cout << endl;
    }
}
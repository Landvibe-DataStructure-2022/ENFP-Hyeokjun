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

//    int min() {
//        if (empty()) return -1;
//
//        int minVal = seq[0];
//
//        for (int i = 0; i < seq.size(); i++) {
//            if (C(seq[i], minVal)) {
//                minVal = seq[i];
//            }
//        }
//        return minVal;
//    }
    int max() {
        if(empty()) return -1;

        int maxVal = seq[0];

        for(int i = 0; i < seq.size(); i++){
            if(C(maxVal, seq[i])){
                maxVal = seq[i];
            }
        }
        return maxVal;
    }

    void removeMax(){
        if(empty()){
            return;
        }
        int maxIdx = 0;

        for(int i = 0; i < seq.size(); i++){
            if(C(seq[maxIdx], seq[i])){
                maxIdx = i;
            }
        }
        seq.erase(seq.begin() + maxIdx);
    }
//    void removeMin() {
//        if (empty()) return;
//        int minIdx = 0;
//
//        for (int i = 0; i < seq.size(); i++) {
//            if (C(seq[i], seq[minIdx])) {
//                minIdx = i;
//            }
//        }
//
//        seq.erase(seq.begin() + minIdx);
//    }

private:
    vector<int> seq;
    compare C;
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> seq;
        unsortedSeqPQ upq;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            seq.push_back(m);
        }

        for(int i = 0; i < n; i++){
            upq.insert(seq.back());
            seq.pop_back();
        }

        for(int i = 0; i < n; i++){
            seq.push_back(upq.max());
            upq.removeMax();
        }

        for(int i = 0; i < n; i++){
            cout << seq[i] << ' ';
        }
        cout << endl;
    }
}
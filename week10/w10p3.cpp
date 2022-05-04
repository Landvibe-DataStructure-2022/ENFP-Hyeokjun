#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Compare {
    bool operator()(const int &i1, const int &i2) {
        return i1 < i2;
    }
};

class Heap { // 최소 heap
public:
    Heap() {
        arr.push_back(0);
    } // vector 기반 힙은 0번 인덱스를 사용하지 않기 때문에 생성할 때 미사용 값을 넣어준다
    int size() {
        return arr.size() - 1;
    }

    bool empty() {
        return arr.size() == 1;
    }

    void insert(int e) { // 힙의 마지막에 원소를 삽입하고 마지막에서부터 업힙을 수행한다.
        arr.push_back(e);
        upHeap(size());
    }

    int min() { // 최소기반 힙이기 때문에 arr[1]에 힙의 최소값이 담겨있다.
        if (empty()) return -1;
        return arr[1];
    }

    void removeMin() { // 최소값인 arr[1]을 힙의 마지막 노드로 보내서 삭제함. 그리고 idx=1 에서부터 다운힙 수행
        if (empty()) return;
        swap(1, size());
        arr.pop_back();
        downHeap(1);
    }

    void isEmpty(){
        if(empty()){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    void print(){
        if(empty()){
            cout << -1 << endl;
            return;
        }
        for(int i = 1; i < arr.size(); i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
private:
    vector<int> arr;
    Compare C;

    void swap(int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    void upHeap(int idx) {
        if (idx == 1) return;

        int parentIDX = idx / 2;
        if (C(arr[idx], arr[parentIDX])) {
            swap(idx, parentIDX);
            upHeap(parentIDX);
        }
    }

    void downHeap(int idx) {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int child;

        // 완전 이진 트리의 조건 이용
        if (left > size()) { // 자식이 없는 노드
            return;
        } else if (left == size()) { // 왼쪽 자식만 있는 노드
            child = left;
        } else { // 두 자식이 모두 존재할 때에는 두 자식중 더 작은 자식의 인덱스를 child에 대입
            if (arr[left] <= arr[right]) { child = left; }
            else child = right;
        }

        if(C(arr[child], arr[idx])){
            swap(child, idx);
            downHeap(child);
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    Heap h;
    while(tc--){
        string query;
        cin >> query;

        if(query == "insert"){
            int n;
            cin >> n;
            h.insert(n);
        } else if (query == "size"){
            cout << h.size() << endl;
        } else if (query == "isEmpty"){
            h.isEmpty();
        } else if (query == "pop"){
            cout << h.min() << endl;
            h.removeMin();
        } else if (query == "top"){
            cout << h.min() << endl;
        } else if (query == "print"){
            h.print();
        }
    }
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
queue<int> q;
vector<int> graph[101];
bool visited[101];


void dfs(int idx, int dest, int cnt) {
    visited[idx] = true;
    if (idx == dest) {
        cout << cnt << endl;
    }
    for (auto i: graph[idx]) {
        if (!visited[i]) {
            dfs(i, dest, cnt + 1);
        }
    }

}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 0; i < k; i++) {

            int a, b;
            cin >> a >> b;
            dfs(a, b, 0);
            if (!visited[b]) cout << 0 << endl;
            for (int i = 0; i < 101; i++) {
                visited[i] = false;
            }
        }
        for (int i = 0; i < 101; i++) {
            graph[i].clear();
        }
    }
}
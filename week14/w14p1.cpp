#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];

void dfs(int idx) {
    visited[idx] = true;
    cout << idx << ' ';
    for (auto i: graph[idx]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1);
        for(int i = 0; i < 101; i++){
            graph[i].clear();
            visited[i] = false;
        }
    }
}
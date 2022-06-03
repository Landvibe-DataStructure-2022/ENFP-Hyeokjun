#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
bool visited[101];

int bfs(int idx) {
    int cnt = 0;
    queue<int> q;
    q.push(idx);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (visited[front]) continue;
        visited[front] = true;
        cnt++;
        for (auto i: graph[front]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }
    return cnt;

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
            int a;
            cin >> a;
            cout << bfs(a) << endl;
            for (int j = 0; j < 101; j++) {
                visited[j] = false;
            }
        }

        for (int i = 0; i < 101; i++) {
            graph[i].clear();
        }
    }
}
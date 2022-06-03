#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool visited[101];
vector<int> graph[101];

void bfs(int idx) {
    queue<int> q;
    q.push(idx);
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (visited[front])continue;
        visited[front] = true;
        cout << front << ' ';
        for (auto i: graph[front]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs(1);
        for(int i = 0; i < 101; i++){
            graph[i].clear();
            visited[i] = false;
        }
    }
}
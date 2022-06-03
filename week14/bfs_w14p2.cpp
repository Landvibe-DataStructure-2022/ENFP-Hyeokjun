#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> graph[101];
bool visited[101];

int bfs(int idx, int dest){
    queue<pair<int, int>> q;
    q.push({idx, 0});

    while(!q.empty()){
        int index = q.front().first;
        int count = q.front().second;
        q.pop();
        if(visited[index]) continue;
        visited[index] = true;
        if(index == dest){
            return count;
        }
        for(auto i : graph[index]){
            if(!visited[i]){
                q.push({i, count + 1});
            }
        }
    }
    return 0;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 0; i < k; i++){
            int a, b;
            cin >> a >> b;
            cout << bfs(a, b) << endl;
            for(int i = 0; i < 101; i++){
                visited[i] = false;
            }
        }
        for(int i = 0; i < 101; i++){
            graph[i].clear();
        }
    }
}
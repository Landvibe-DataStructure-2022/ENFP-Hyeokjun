#include <iostream>
#include <string>

using namespace std;

int main() {
    int tc, n;
    int vId;
    int size = 0;
    cin >> tc >> n;

    for (int i = 0; i < n; i++) {
        cin >> vId;
    }

    bool graph[2000][2000];

    while (tc--) {
        string q;
        cin >> q;
        int u, v;
        cin >> u >> v;

        if (q == "insertEdge") {
            if(graph[u][v]){
                cout << "Exist" << endl;
            } else {
                graph[u][v] = graph[v][u] = true;
            }
        } else if (q == "eraseEdge") {
            if(!graph[u][v]){
                cout << "None" << endl;
            } else {
                graph[u][v] = graph[v][u] = false;
            }
        } else if (q == "isAdjacentTo") {
            if(graph[v][u]){
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
        }
    }
}
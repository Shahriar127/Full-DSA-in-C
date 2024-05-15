#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 123;
vector<int> g[N];
int vis[N];
int level[N];

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    vis[vertex] = 1;
    level[vertex] = 0;
    while (!q.empty()) {
        int curr_vr = q.front(); 
        q.pop();
        for (int child : g[curr_vr]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1; 
                level[child] = level[curr_vr] + 1; 
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        cout << "Read edge: " << x << " " << y << endl;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);

    
    cout << "Levels of vertices:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << ": " << level[i] << endl;
    }
    return 0;
}

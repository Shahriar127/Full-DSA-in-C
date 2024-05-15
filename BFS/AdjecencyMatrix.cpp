#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int g[N][N];

int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    // Output 
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

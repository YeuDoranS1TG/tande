#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n,q;
vector<int> g[maxn];
int h[maxn], up[maxn][17];
int sz[maxn];

void dfs(int u, int p){
    up[u][0] = p;
    sz[u] = 1;

    for (int v : g[u]){
        if (v == p) continue;
        h[v] = h[u] + 1;
        dfs(v,u);
        sz[u] += sz[v];
    }
}

int lca (int u, int v){
  if (h[u] != h[v]){
    if (h[u] < h[v]) swap(u,v);

    int k= h[u] - h[v];
    for (int j=0; (1<<j) <= k; ++j)
      if (k >> j & 1)
        u = up[u][j];
  }
  if (u == v) return u;

  int k = __lg(h[u]);
  for (int j = k; j>=0; --j){
    if (up[u][j] != up[v][j]){
      u = up[u][j];
      v = up[v][j];
    }
  }

  return up[u][0];
}

int jump (int u, int k){
    for (int j=0; j<17; ++j){
        if ( k & (1 << j)){
            u = up[u][j];
        }
    }
    return u;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0); 
  cin>>n>>q;

  for (int i=1; i<n; ++i){
    int u,v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  dfs(1,0);
  for (int j = 1; j < 17; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[ up[i][j-1] ][j-1];
        
    

  int u, v;
  while (q--){
    cin >> u >> v;
    
    if ( u == v ){
        cout << n << '\n';
        continue;
    }
    
    int p = lca (u,v);
    int d = h[u] + h[v] - 2*h[p];

    if (d & 1){
        cout << 0 << '\n';
        continue;
    }

    d = d >> 1;
    int k = d - 1;

    if (h[u] == h[v]) {
        int cu = jump(u, d - 1);
        int cv = jump(v, d - 1);
        cout << n - sz[cu] - sz[cv] << '\n';
    } 
    else {
        if (h[u] < h[v]) swap(u, v);
        int c = jump(u, d);
        int child = jump(u, d - 1);
        cout << sz[c] - sz[child] << '\n';
    }
  }
  return 0;
}

You are given a tree of n vertices
Let f(u,v) be the shortest distance between u and v. 
You are given q queries, each of the form (u,v), counting the number of vertices x that
f(u,x)=f(v,x)

Input
The first line contain 2 integers n,q.
The next n−1 lines, each line contains 2 integers u,v, there is an edge between u and v.
The next q lines, each line contains 2 integers u,v, an query.
  
Output
Print q integers, the answers to q queries.
  
Constraints
1 ≤ n, q ≤ 10^5.
1 ≤ u, v ≤ n.
  
Example
Input:
7 3
1 2
1 3
2 4
2 5
3 6
3 7
1 4
5 6
3 7
Output:
2
1
0

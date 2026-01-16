#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n,q;

struct edge{
  int v;
  long long w;
  edge(int v=0, long long w=0): v(v), w(w) {}
}; 
vector<edge>g[maxn];
long long h[maxn], dist[maxn], up[maxn][17];

void dfs(int u){
  for (edge &e : g[u]){
    int v = e.v;
    long long w = e.w;
    if (v == up[u][0])
      continue;

    h[v] = h[u] + 1;
    dist[v] = dist[u] + w;
    
    up[v][0] = u;
    for (int j=1; j<17; ++j)
      up[v][j] = up[up[v][j-1]][j-1];

    dfs(v);
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

long long finddis (int u, int v){
  int p = lca(u , v);
  return dist[u] + dist[v] -2*dist[p];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0); 
  cin>>n>>q;

  for (int i=1; i<n; ++i){
    int u,v;
    long long w;
    cin >> u >> v >> w;
    g[u].emplace_back(v , w);
    g[v].emplace_back(u , w);
  }

  dfs(1);
  int u,v;
  while (q--){
    cin >> u >> v;
    cout << finddis(u , v) << '\n';
  }
  return 0;
}

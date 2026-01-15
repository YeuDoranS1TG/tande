#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>g[maxn];
int par[maxn];
int h[maxn];

void dfs(int u){
  for (int v:g[u]){
    if (v==par[u]) continue;
    h[v]=h[u]+1;
    par[v]=u;
    dfs(v);
  }
}

int lca(int u, int v){
  if (h[u] < h[v]) swap(u,v);
  while (h[u] > h[v]){
    u=par[u];
  }

  while (u != v){
    u=par[u];
    v=par[v];
  }
  return u;
}
int main(){
  int n,q;
  cin>>n>>q;

  for (int i=1;i<n;++i){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  while(q--){
    int x,y;
    cin>>x>>y;
    cout<<lca(x,y)<<'\n';
  }
  return 0;
}

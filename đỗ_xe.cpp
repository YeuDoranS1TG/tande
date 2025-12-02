#include <bits/stdc++.h>
using namespace std;
#define maxN 100000+5
int n;
int g[maxN];
bool vis[maxN]={0};
vector<int>next,ans;
int findnext(int x){
  if (x>n) x=1;
  if (next[x]==x) return x;
  return next[x]=findnext(next[x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0); 
  cin>>n;
  for (int i=1;i<=n;++i){
    int p;
    cin>>p;
    g[i]=p;
  }
  next.resize(n+1); 
  ans.resize(n+1);
  for (int i=1;i<=n;++i){
    next[i]=i;
  }
  int i=1;
  while (i<=n){
    int p=g[i];
    if (!vis[p]){
      ans[i]=p;
      vis[p]=true;
      ++i;
      continue;
    }
    int rp=findnext(p+1);
    ans[i]=rp;
    next[p]=rp;
    vis[rp]=true;
    ++i;
  }
	return 0;
}

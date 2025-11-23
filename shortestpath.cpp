https://open.kattis.com/submissions/18755612
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
#define pii pair<int,int>
int n,m,q,s;
vector<int> dijkstra(int ss,vector<pii>v[]){
    vector<int>d(n+1,1e9);
    d[ss]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,ss});
    while (!pq.empty()){
        pii top=pq.top(); pq.pop();
        int u=top.second;
        int kc=top.first;
        if (kc>d[u]) continue;
        
        for (auto it:v[u]){
            int x=it.first;
            int w=it.second;
            if (d[x]>d[u]+w){
                d[x]=d[u]+w;
                pq.push({d[x],x});
            }
        }
    }
    return d;
}
int main() {
	while (cin>>n>>m>>q>>s){
        vector<pii>v[maxN];
        for (int i=0;i<m;++i){
            int u,y,w;
            cin>>u>>y>>w;
            v[u].push_back({y,w});
        }
        vector<int>a=dijkstra(s,v);
        int t;
        while (q--){
            cin>>t;
            if (a[t]==1e9){
                cout<<"IMPOSSIBLE"<<'\n';
            }
            else{
                cout<<a[t]<<'\n';
            }
        }
        cout<<'\n';
    }
}

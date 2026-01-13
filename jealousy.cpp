#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int mod=1e9+7;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    long long a[maxn],b[maxn];

    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        cin>>b[i];
    }

    long long val[5][maxn];
    // for (int i=1;i<=n;++i){
    //     val[1][i]=0;
    //     val[2][i]=0;
    //     val[3][i]=0;
    //     val[4][i]=0;
    // }

    val[1][1]=a[1];
    val[2][1]=0;
    val[3][1]=b[1];
    val[4][1]=0;
    for (int i=2;i<=n;++i){
        long long u=a[i], v=b[i];
        val[1][i]=max(val[3][i-1]+u, val[4][i-1]+u)%mod;
        val[2][i]=(val[1][i-1]+u)%mod;
        val[3][i]=max(val[1][i-1]+v, val[2][i-1]+v)%mod;
        val[4][i]=(val[3][i-1]+v)%mod;
    }
    long long maxval=0;
    int q=4;
    for (int i=1;i<=q;++i){
        maxval=max(maxval, val[i][n]);
    }
    cout<<maxval%mod;
	return 0;
}

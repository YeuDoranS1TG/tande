#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v;
int main()
{
    ll n,x,ans=0;
    ll prefix[100005]={0};
    map<ll, int> mp;
    cin>>n>>x;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin>>temp;
        prefix[i]=prefix[i-1]+temp;
        mp[prefix[i]]++;
        ans += mp[prefix[i]-x];
        if(prefix[i]==x && prefix[i]-x!=prefix[i]) ans++; 
    }
    cout<<ans;
    return 0;
}

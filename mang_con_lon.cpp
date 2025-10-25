* CÁCH 1 *
  
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
typedef long long ll;
ll k, n;
vector<ll> a;
int main(){
	cin>>n>>k;
	a.push_back(0);
	ll ans=0;
	for (ll i=0;i<n;++i){
		ll x;
		cin>>x;
		a.push_back( a.back()+x );
	}
	for (ll i=1;i<=n;++i){
		ll num=a[i]-k;
		int it=upper_bound(a.begin(),a.begin()+i,num) - a.begin();
		if (it==(int)a.size()) continue;
		ans+= it;
	}	
	cout<<ans<<'\n';
	return 0;
}

* CÁCH 2 *
  
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
typedef long long ll;
ll k, n, minid=LLONG_MAX;
ll a[maxN+5];
int main(){
	cin>>n>>k;
	a[0]=0;
	ll ans=0;
	for (ll i=0;i<n;++i){
		ll x;
		cin>>x;
		a[i+1]=a[i]+x;
		if (a[i+1]>=k) {
			++ans;
			minid=min(minid,i+1);
		}
	}
	ll j=1;
	while (minid<=n && j<=minid){
		if (a[minid]-a[j]>=k) {ans+= (n-minid+1); ++j;}
		else ++minid;
	}
	cout<<ans<<'\n';
	return 0;
}
/* 
Mảng con lớn
Cho mảng A gồm n số nguyên dương, đếm số lượng dãy con liên tiếp có tổng không nhỏ hơn k.

Input
Dòng đầu tiên gồm 2 số nguyên n,k.
Dòng tiếp theo gồm n số nguyên A[i] cách nhau bởi dấu cách.
Output
In ra một số nguyên là số lượng dãy con liên tiếp có tổng không nhỏ hơn k.

Điều kiện
1 ≤ n ≤ 10^5.
1 ≤ A[i], k ≤ 10^9.

Ví dụ
Input:
5 6
1 2 1 4 5
Output:
6
*/

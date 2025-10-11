#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull modpow(ull a, ull b, ull c){
    if (b==0) return 1LL;
    ull half=modpow(a,b/2,c)%c;
    ull res=(ull)((__int128)half*half%c);
    if (b&1) return ((__int128)res * (a%c)%c);
    return res;
}

int main(){
	ull a,b,c;
	cin>>a>>b>>c;
	a%=c;
	cout<<modpow(a,b,c)<<'\n';
	return 0;
}

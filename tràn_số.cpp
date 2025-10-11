#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull modmul(ull a, ull b, ull c){
    ull res=0;
    while (b>0){
        if (b&1){
            res=(res+a)%c;
        }
        a=(2*a)%c;
        b>>=1;
    }
    return res;
}
int main(){
	ull a,b,c;
	cin>>a>>b>>c;
	a%=c, b%=c;
	ull ans=modmul(a,b,c);
	cout<<ans;
}

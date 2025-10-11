#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull mod=1e9+7;
ull modpow(ull a, ull b){
    if (b==0) return 1LL;
    ull half=modpow(a,b/2)%mod;
    ull res=(ull)((__int128)half*half%mod);
    if (b&1) return ((__int128)res * a%mod);
    return res;
}

int main(){
	ull n;
	cin>>n;
	ull k=n/3;
	ull m=n-k;
	ull ans3=modpow(3,m)%mod;
	ull ans4=modpow(4,k)%mod;
	ull ans=(__int128)ans3*ans4%mod;
	cout<<ans<<'\n';
	return 0;
}
/*
Đếm số

Giới hạn thời gian: 1000 ms
Giới hạn bộ nhớ: 256 MB

Đếm số lượng số có n chữ số thỏa mãn điều kiện sau:
Chữ số thứ i≡i (mod3)
Chỉ số bắt đầu từ 1, từ trái sang phải.
Ví dụ, 42 là một số có 2 chữ số thỏa mãn.

Input
Dòng đầu tiên gồm số nguyên 
n.
Output
In ra số lượng số thỏa mãn điều kiện trên, modulo 10^9+7.
Điều kiện : 1≤n≤10^18.

Ví dụ
Input:
2
Output:
9
*/
VD: n=3, thứ tự sẽ là 1-2-0 (mod 3)
mà mod3 = 1 thì ta có {1,4,7}, mod3 = 2 thì ta có {2,5,8}, mod3 = 0 thì ta có {0,3,6,9}
với thứ tự 1-2-0 thì 1 là 3 cách, 2 là 3 cách và 0 là 4 cách 
suy ra: 1-2-0 = 3*3*4 = 3^2 * 4^1
từ đó ta có công thức là:
k = n/3
ans = 3^n-k * 4^k
lưu ý : thứ tự sẽ chỉ lặp lại 1-2-0-1-2-0-1-...

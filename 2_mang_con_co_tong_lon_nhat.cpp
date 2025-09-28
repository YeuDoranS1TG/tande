#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n; cin>>n;
    ll sum=0,a[100000+5];
    vector<ll>pref(n+1,LLONG_MIN), suf(n+2,LLONG_MIN);
    for (int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
        if (i>1) pref[i]=max(pref[i],pref[i-1]);
        pref[i]=max(pref[i],sum);
        if (sum<0) sum=0;
    }
    sum=0;
    ll best=LLONG_MIN;
    for (int i=n;i>=1;--i){
        sum+=a[i];
        suf[i]=max(suf[i],suf[i+1]);
        suf[i]=max(suf[i],sum);
        if (sum<0) sum=0;
        if (i+1<=n) best=max(best,pref[i]+suf[i+1]);
        //if (i>=2) best=max(best,pref[i-1]+suf[i]);
    }
    cout<<best;
    return 0;
}
/*

Mảng con có tổng lớn nhất 2
Giới hạn thời gian: 1000 ms
Giới hạn bộ nhớ: 256 MB
Cho mảng A gồm n phần tử. 
Hãy chọn ra hai mảng con khác rỗng không giao nhau của A sao cho tổng của chúng là lớn nhất. 
Nói cách khác, chọn ra bốn chỉ số 1 ≤ l ≤ r < i ≤ j ≤ n sao cho (A[l] + A[l+1] +…+ A[r]) + (A[i] + A[i+1] +…+ A[j]) lớn nhất.

Input
Dòng đầu tiên gồm số nguyên n.
Dòng thứ hai gồm n số nguyên A[i].
Output
In ra một số nguyên là tổng lớn nhất.
Điều kiện
1 ≤ n ≤ 10^5.
0 ≤ |A[i]| ≤ 10^9.
  
Ví dụ
Input:
5
3 -2 8 -1 2
Output:
12
*/

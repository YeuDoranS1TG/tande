#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
int main()
{
    int n;
    cin>>n;
    long long a[maxN+5];
    long long prefixsum[maxN+5];
    for (int i=0;i<n;++i){
        cin>>a[i];
    }
    prefixsum[0]=a[0];
    for (int i=1;i<n;++i){
        prefixsum[i]=prefixsum[i-1]+a[i];
    }
    long long min_prefixsum=0;
    long long maxval=LLONG_MIN;
    for (int i=0;i<n;++i){
        maxval=max(maxval,prefixsum[i]-min_prefixsum);
        min_prefixsum=min(min_prefixsum,prefixsum[i]);
    }
    cout<<maxval;
    return 0;
}

/*
Mảng con có tổng lớn nhất
Giới hạn thời gian: 1000 ms
Giới hạn bộ nhớ: 256 MB
Cho mảng A gồm n số nguyên. Tìm mảng con có tổng lớn nhất.
Một mảng con là một chuỗi các phần tử liên tục trong một mảng. 
Ví dụ, cho một mảng B=[1,2,3,4,5], mảng C=[2,3,4] là một mảng con của B.

Input
Dòng đầu gồm số nguyên dương n.
Dòng thứ hai gồm n số nguyên A[i].
Output
In ra một số nguyên là tổng lớn nhất của một mảng con.
Điều kiện
1≤n10^5.
|A[i]|≤10^9.

Ví dụ
Input:
5
1 3 -2 3 -5
Output:
5
*/

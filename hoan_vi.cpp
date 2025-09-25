#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>used;
void hoan_vi(unordered_map<int,int>&mp)
{
    if (used.size()==n)
    {
        for (auto x:used)
        {
            cout<<x<<" ";
        }
        cout<<'\n';
        return;
    }
    else
    {
        for (int j=1; j<=n; ++j)
        {
            if (mp[j]>=1) continue;
            ++mp[j];
            used.push_back(j);
            hoan_vi(mp);
            used.pop_back();
            --mp[j];
        }
    }
}
int main()
{
    cin>>n;
    unordered_map<int,int>v;
    hoan_vi(v);
    return 0;
}
/*
Hoán vị
Giới hạn thời gian: 1000 ms
Giới hạn bộ nhớ: 256 MB
In ra tất cả các hoán vị của tập S={1,2,...,n}.

Input
Một dòng gồm số nguyên n.
Output
In ra tất cả các hoán vị của S, theo thứ tự từ điển.
Điều kiện
1≤ n ≤9.

Ví dụ
Input:
3
Output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

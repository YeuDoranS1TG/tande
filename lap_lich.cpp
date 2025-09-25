#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long,long long>>v;
long long minval=LLONG_MAX;
vector<bool>used;
void lap_lich(long long hangcho, long long sum, int solan){
    if (solan==n){
        minval=min(minval,sum+hangcho);
        return;
    }
    for (int i=0;i<n;++i){
        if (used[i]) continue;
        used[i]=true;
        long long newsum=sum+v[i].first;
        long long newhangcho=max(0LL,hangcho-v[i].first);
        lap_lich(newhangcho+v[i].second,newsum,solan+1);
        used[i]=false;
    }
}
int main()
{
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
    }
    used.assign(n, false);
    lap_lich(0,0,0);
    cout<<minval;
    return 0;
}
/*
Lập lịch
- Giới hạn thời gian: 1000 ms
- Giới hạn bộ nhớ: 256 MB
Marisa muốn đóng chai n lọ thuốc. Mỗi lọ thuốc mất A[i] để đổ đầy và B[i] giây để dán nhãn. Một lọ thuốc cần được đổ đầy trước khi dán nhãn.
Marisa có hai chiếc máy, một để đổ thuốc vào lọ, và một để dán nhãn. 
Mỗi máy chỉ có thể xử lí tuần tự từng lọ thuốc một. 
Marisa muốn biết cần ít nhất bao nhiêu thời gian để đóng chai hết n lọ thuốc.

Input
Dòng đầu tiên gồm một số nguyên n.
n dòng tiếp theo, mỗi dòng gồm hai số nguyên A[i],B[i].
Output
In ra một số nguyên là thời gian tối thiểu.
Điều kiện
1≤ n ≤10.
1≤ A[i], B[i] ≤10^9.

Ví dụ
Input:
2
1 3
2 3
Output:
7

Input:
8
9 3
7 3
4 5
2 5
3 10
1 9
10 4
4 9
Output:
49
*/

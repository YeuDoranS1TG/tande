#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn];
int par[2*maxn];

int find(int v){
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

void unions (int a, int b){
    a = find(a);
    b = find(b);

    if (a != b){
        par[a] = b;
    }
}

void leave(int v){  // đã xài nên nhảy tới cái tiếp theo
    unions(v,v+1);
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    // freopen("CORRECTION.INP", "r", stdin); 
    // freopen("CORRECTION.OUT", "w", stdout); 
    int n;
    cin>>n;

    for (int i=0; i<n; ++i){
        cin>>a[i];
    }
    
    for (int i=0; i<2*maxn; ++i){
        par[i] = i;
    }

    for (int i=0; i<n; ++i){
        int temp = find(a[i]);
        cout<<temp<<" ";
        leave(temp);
    }

    return 0;
}
/*
SỬA ĐỔI DÃY 
Xét dãy các số nguyên 𝑎1,𝑎2,…,𝑎𝑛. Dãy số có thể tồn tại những giá trị bị lặp lại. Bờm thực hiện điều chỉnh 
để dãy không còn giá trị trùng nhau theo cách sau: 

- Bờm chọn lần lượt các phần tử theo thứ tự 𝑎2,𝑎3,…,𝑎𝑛 để điều chỉnh.
- Khi xét 𝑎𝑖, nếu giá trị này đã xuất hiện trong dãy 𝑎1, 𝑎2, … , 𝑎𝑖−1 thì tăng 𝑎𝑖 thêm 1. 
Lặp lại thao tác này cho đến khi giá trị mới của 𝑎𝑖 chưa xuất hiện trong dãy 𝑎1, 𝑎2,…,𝑎𝑖−1 thì dừng lại. 

Yêu cầu: Cho dãy 𝑎1,𝑎2,…,𝑎𝑛. Hãy xác định giá trị cuối cùng của dãy sau khi thực hiện các phép biến đổi 
của Bờm. 
Dữ liệu: Vào từ tập tin văn bản CORRECTION.INP
- - 
Dòng đầu tiên chứa số nguyên dương 𝑛(1 ≤ 𝑛 ≤ 10^6). 
Dòng tiếp theo chứa dãy số nguyên 𝑎1,𝑎2,…,𝑎𝑛(1 ≤ 𝑎𝑖 ≤ 10^6). 
Kết quả: Ghi ra tập tin văn bản CORRECTION.OUT gồm 𝑛 số nguyên là giá trị cuối cùng của dãy sau 
hiệu chỉnh. 
Ví dụ: 
CORRECTION.INP 
5 
2 1 1 3 4 
CORRECTION.OUT 
2 1 3 4 5 
  */

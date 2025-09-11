#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,a[11][11];
bool check_doc(int j){
    for (int m=0;m<n;++m){
        if (a[m][j]==1) return false;
    }
    return true;
}
bool check_cheo_trai(int i,int j){
    for (int x=i+1,y=j+1;x>=0 && y>=0;--x,--y){
        if (a[x][y]==1) return false;
    }
    return true;
}
bool check_cheo_phai(int i,int j){
    for (int x=i+1,y=j-1;x>=0 && y<=n;--x,++y){
        if (a[x][y]==1) return false;
    }
    return true;
}
void so_cach_dat_hau(int i, int j){
    if (j==n) return;
    if (i==n){
       ++cnt;
       return;
    }
    else if (check_doc(j) && check_cheo_trai(i,j) && check_cheo_phai(i,j)){
        a[i][j]=1;
        so_cach_dat_hau(i+1,0);
        a[i][j]=0;
    }
    so_cach_dat_hau(i,j+1);
}
int main()
{
    cin>>n;
    so_cach_dat_hau(0,0);
    cout<<cnt;
    return 0;
}

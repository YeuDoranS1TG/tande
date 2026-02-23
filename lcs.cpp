#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
long long val[maxn][maxn];
void print (int n){
    for (int i=0; i<=(n+1); ++i){
        for (int j=0; j<=(n+1); ++j){
            cout << val[i][j] << " "; 
        }
        cout << '\n';
    }
    cout << '\n' << '*' << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i=0; i<maxn; ++i)
		for (int j=0; j<maxn; ++j)
			val[i][j] = 0;
			
	for (int i=2; i<=(n+1); ++i){
        long long x;
        cin >> x;
		val[0][i] = x;
    }

	for (int i=2; i<=(n+1); ++i){
        long long x;
        cin >> x;
		val[i][0] = x;
    }
	
	for (int i=2; i<=(n+1); ++i){
		for (int j=2; j<=(n+1); ++j){
			if (val[i][0] == val[0][j])
				val[i][j] = val[i-1][j-1] + 1; // khúc này là lấy cái ô chéo lệch về trên trái
			
			else 
				val[i][j] = max(val[i][j-1], val[i-1][j]); // khúc này là lựa chọn giữa ô bên trên và bên trái cái nào lớn hơn. Ví dụ: val[5][4] == 2 vì nó lấy ô val[5][3] xuống
                                                  // suy ra ta bỏ ô val[4][4] vì nó bằng 1, nghĩa là ta lấy 1234 so với 34 (lấy ô trên) chứ ko lấy 123 so với 342 (lấy ô trái)
		}
        //print(n);
	}
				
	cout << val[n+1][n+1];		
	return 0;
}

0 	r	  1	  2	  3	  4
c	  0	  0	  0	  0	  0
3	  0	  0	  0	  1	  1
4	  0	  0	  0	  1	  2
2  	0	  0	  1	  1	  2
1  	0	  1	  1	  1	  2

#include <bits/stdc++.h>
using namespace std;
long long n,cnt=1,res=1;
string s;
bool check1(){
    return n<res;
}
bool check2(){
    return n>res-cnt+1;
}
long long board(string ans){
    if (ans=="ET" && check1()) return n+1;
    if (ans=="WT" && check2()) return n-1;
    if (ans=="NW" && check2()) return n-cnt;
    if (ans=="NE" && check1()) return n-cnt+1;
    if (ans=="SW") return n+cnt;
    if (ans=="SE") return n+cnt+1;
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("BOARDGAME.INP","r",stdin);
    freopen("BOARDGAME.OUT","w",stdout);
    cin>>n; cin>>s;
    long long sum=n;
    while (res<n){
        ++cnt;
        res+=cnt;
    }
    int i=0,j=1;
    while (j<=s.size()){
        string ans="";
        ans.push_back(s[i]);
        ans.push_back(s[j]);
        long long pos=board(ans);
        if (pos!=0){
            if (pos<n-1) res-=cnt,--cnt;
            else if (pos>n+1) ++cnt,res+=cnt;
            n=pos;
            sum+=n;
        }
        i+=2, j+=2;
    }
    cout<<sum;
    return 0;
}
/*
GAME 
Một Robot cảm ứng có khả năng định hướng và di chuyển 
trên bản đồ theo chuỗi các lệnh điều khiển. Bản đồ được bố 
trí thành một tháp các hình tròn có đường kính 1 đơn vị. 
Các hình tròn trên tháp được đánh thứ tự từ 1 trở đi theo 
nguyên tắc: hình tròn ở đỉnh tháp đánh thứ tự 1. Tầng 2 
đánh thứ tự 2, 3 từ trái sang tương ứng...  
Robot mỗi lần chỉ di chuyển từ một hình tròn sang một hình 
tròn khác có cạnh tiếp xúc nhau. Lệnh định hướng di 
chuyển được mã hóa bởi nhóm gồm 2 kí tự như sau: - - - - - - 
ET: di chuyển sang hình tròn liền kề theo hướng Đông. 
WT: di chuyển sang hình tròn liền kề theo hướng Tây. 
NW: di chuyển sang hình tròn liền kề theo hướng Tây Bắc. 
NE: di chuyển sang hình tròn liền kề theo hướng Đông Bắc. 
SW: di chuyển sang hình tròn liền kề theo hướng Tây Nam. 
SE: di chuyển sang hình tròn liền kề theo hướng Đông Nam. 
Nếu chuỗi điều khiển chứa mã lệnh làm cho Robot vượt ra khỏi bản đồ thì Robot sẽ tự nhận biết và bỏ qua 
lệnh đó. Ví dụ Robot đang đứng ở vị trí số 14 và được điều khiển bởi chuỗi mã lệnh ETETSWWTSE sẽ 
lần lượt di chuyển qua các hình tròn mang số thứ tự 14 15 20 19 26 tương ứng. Tổng giá trị số thứ tự 
các ô trên đường đi chính là tổng số điểm mà Robot thu được. 
Yêu cầu: Cho chuỗi mã lệnh điều khiển, hãy xác định tổng số điểm mà Robot sẽ đạt được. 
Dữ liệu: Vào từ tập tin văn bản BOARDGAME.INP - - 
Dòng đầu chứa số nguyên 𝑘(𝑘 ≤ 106) cho biết vị trí ban đầu của Robot 
Dòng tiếp theo chứa chuỗi không khoảng cách, dài không quá 2 × 105 kí tự là dãy mã lệnh điều khiển 
Kết quả: Ghi ra tập tin văn bản BOARDGAME.OUT tổng số điểm đạt được. 
Ví dụ: 
BOARDGAME.INP 
14 
ETETSWWTSE 
BOARDGAME.OUT 
94 
*/

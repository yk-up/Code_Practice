//这种思路也是由于看到标签是前缀和差分，就这样想起来了，如果考试没有的话还真不一定写出来
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2002;
int a[N][N];
int diff[N][N];
int n,m;
//转换成前缀和，一开始是 1(黑棋) 如果最后是奇数说明还是 1 否则就是 0（白棋）
//差分
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        diff[x1][y1]+=1;
        diff[x2+1][y2+1]+=1;
        diff[x2+1][y1]-=1;
        diff[x1][y2+1]-=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
            if(a[i][j]%2==0)cout<<0;
            else cout<<1;
            //cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
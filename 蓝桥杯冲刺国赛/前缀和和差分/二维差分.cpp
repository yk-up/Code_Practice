#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+11;
int a[N][N];
int diff[N][N];
int n,m,q;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            diff[i][j]=a[i][j]+a[i-1][j-1]-a[i-1][j]-a[i][j-1];//注意这里初始化。其实a[i][j]就是差分数组 diff[i][j]的前缀和
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2,d;cin>>x1>>y1>>x2>>y2>>d;
        diff[x1][y1]+=d;
        diff[x2+1][y2+1]+=d;

        diff[x2+1][y1]-=d;
        diff[x1][y2+1]-=d;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
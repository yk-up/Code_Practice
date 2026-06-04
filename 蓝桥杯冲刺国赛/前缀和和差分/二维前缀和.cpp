#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
const int N=1e3+11;
int prefix[N][N];
int a[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            prefix[i][j]=prefix[i][j-1]+prefix[i-1][j]+a[i][j]-prefix[i-1][j-1];
        }
    }
    while(q--)
    {             
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cout<<(prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2])<<endl;
    }
    return 0;
}
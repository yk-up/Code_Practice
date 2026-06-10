#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int a[N][N];
int prefix[N][N];
int n,m,q;
int main()
{  
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cout<<prefix[x2][y2]+prefix[x1-1][y1-1]-prefix[x2][y1-1]-prefix[x1-1][y2]<<endl;
    }
}

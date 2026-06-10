// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1002;
// int a[N][N];
// int diff[N][N];
// //注意二维差分数组的初始化
// void insert(int x1,int y1,int x2,int y2,int c)
// {
//     diff[x1][y1]+=c;
//     diff[x2+1][y2+1]+=c;
//     diff[x1][y2+1]-=c;
//     diff[x2+1][y1]-=c;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m,q;cin>>n>>m>>q;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             cin>>a[i][j];
//             insert(i,j,i,j,a[i][j]);
//         }
//     }
//     while(q--)
//     {
//         int x1,y1,x2,y2,c;cin>>x1>>y1>>x2>>y2>>c;
//         insert(x1,y1,x2,y2,c);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
//             cout<<a[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int a[N][N];
int diff[N][N];
int n,m,q;
void insert(int x1,int y1,int x2,int y2,int c)
{
    diff[x1][y1]+=c;
    diff[x2+1][y2+1]+=c;
    diff[x1][y2+1]-=c;
    diff[x2+1][y1]-=c;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            insert(i,j,i,j,a[i][j]);
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2,c;cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
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
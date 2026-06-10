// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int a[N],b[N];
// int main()
// {
//     int n,m;cin>>n>>m;
//     for(int i=0;i<n;i++)cin>>a[i];
//     for(int j=0;j<m;j++)cin>>b[j];
//     int i=0,j=0;
//     //b 一直往后移，a 相等才往后移动
//     while(i<n&&j<m)
//     {
//         if(a[i]==b[j])i++;
//         j++;
//     }
//     if(i==n)cout<<"Yes\n";
//     else cout<<"No\n";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int a[N],b[N];
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=1;j<=m;j++)cin>>b[j];
    
    int i=1,j=1;
    while(i<=n&&j<=m)
    {
        if(a[i]==b[j])i++;
        j++;
    }
  
    if(i==n+1)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100002;
int diff[N];
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        diff[i]=a[i]-a[i-1];
    }
    while(m--)
    {
        int l,r,c;cin>>l>>r>>c;
        //cout<<diff[r]-diff[l-1]<<" ";
        diff[l]+=c;
        diff[r+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+diff[i];
        cout<<a[i]<<" ";
    }
    return 0;
}
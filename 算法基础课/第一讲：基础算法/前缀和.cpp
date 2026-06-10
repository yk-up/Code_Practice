#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100002;
int a[N];
int prefix[N];
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    while(m--)
    {
        int l,r;cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;
    }
    return 0;
}
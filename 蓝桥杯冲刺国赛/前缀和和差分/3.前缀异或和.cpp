#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+11;
int prefix[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        //sum^=x;
        prefix[i]=prefix[i-1]^x;
    }
    while(m--)
    {
        int l,r;cin>>l>>r;
        //必须带上括号，异或的前缀。参考和前缀和
        cout<<(prefix[r]^prefix[l-1])<<endl;
    }
    return 0;
}
//有点忘了，但还是写出来了
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int quick(int base,int exp,int p)
{
    int res=1;
    base%=p;
    while(exp)
    {
        if(exp&1)
        {
            res=res*base%p;
        }
        base=base*base%p;
        exp>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--)
    {
        int a,b,p;cin>>a>>b>>p;
        cout<<quick(a,b,p)<<endl;
    }
}
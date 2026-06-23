#include<bits/stdc++.h>
using namespace std;
int __gcd(int x,int y)
{
    if(y==0)return x;
    return __gcd(y,x%y);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--)
    {
        int x,y;cin>>x>>y;
        cout<<__gcd(x,y)<<endl;
    }
    return 0;
}
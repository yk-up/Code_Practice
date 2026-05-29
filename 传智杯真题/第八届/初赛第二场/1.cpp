//这道题也关注一下，
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //本质上是 1based 取余
    // int x,n;cin>>x>>n;
    // if(x==6)cout<<1;
    // else if(x==7)cout<<2;
    // else cout<<x+2;

    int x,n;cin>>x>>n;
    cout<<(x-1+n)%7+1;
    return 0;
}
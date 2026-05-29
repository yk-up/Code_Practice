#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;

signed main()
{
    int t;cin>>t;
    while(t--){
    queue<int>A,B;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        int x;cin>>x;
        A.push(x);
    }
    for(int i=0;i<b;i++)
    {
        int x;cin>>x;
        B.push(x);
    }
    int cnt1=0,cnt2=0;
    while(A.size()&&B.size())
    {
        int x=A.front();A.pop();
        int y=B.front();B.pop();
        if(x==y)continue;
        if(x>y)
        {
            A.push(x);
            cnt1++;
        }
        else
        {
            B.push(y);
            cnt2++;
        }
    }
    if(cnt1==cnt2)
    {
        cout<<"draw\n";
    }
    else
    {
        if(cnt1>cnt2)cout<<"alice\n"; 
        else cout<<"bob\n";
    }
}
    return 0;
}
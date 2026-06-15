#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int fa[N];
int n,m;
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return ;
    fa[yy]=xx;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    while(m--)
    {
        char s;cin>>s;
        int a,b;cin>>a>>b;
        if(s=='Q')
        {
            if(find(a)==find(b))cout<<"Yes\n";
            else cout<<"No\n";
        }
        else 
        {
            merge(a,b);
        }
    }
    return 0;
}
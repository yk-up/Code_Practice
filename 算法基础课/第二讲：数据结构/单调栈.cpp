// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// int stk[N],tt;
// int n;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int x;cin>>x;
//         while(tt&&stk[tt]>=x)tt--;
//         if(tt)cout<<stk[tt]<<" ";
//         else cout<<-1<<" ";

//         stk[++tt]=x;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int tt=0;
// int stk[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         while(tt&&stk[tt]>=x)tt--;
//         if(tt)cout<<stk[tt]<<" ";
//         else cout<<"-1 ";
//         stk[++tt]=x;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=1e6+11;
int stk[N];
int tt=0;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        while(tt>0&&stk[tt]>=x)tt--;
        if(tt)cout<<stk[tt]<<" ";
        else cout<<-1<<" ";

        stk[++tt]=x;
    }
    return 0;
}
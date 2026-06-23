// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     vector<int>p(m);
//     for(int i=0;i<m;i++)cin>>p[i];
//     int res=0;
//     for(int i=1;i<1<<m;i++)
//     {
//         int t=1;
//         int cnt=0;//当前子集中质数的个数
//         for(int j=0;j<m;j++)
//         {
//             if(i>>j&1) 
//             {
//                 cnt++;

//                 if(t*p[j]>n)
//                 {
//                     t=-1;
//                     break;
//                 }
//             t*=p[j];
//             }
//         }

//         if(t!=-1)
//         {
//             if(cnt%2==1)res+=n/t;
//             else res-=n/t;
//         }
//     }
//     cout<<res<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    vector<int>p;
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        p.push_back(x);
    }
    int res=0;
    //Cm1+Cm2+Cm3+...+..=2^m-1
    for(int i=1;i<1<<m;i++)
    {
        int t=1;
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(i>>j&1)
            {
                cnt++;
                t*=p[j];
                // cnt+=n/j;
            }
            if(t>n)
            {
                t=-1;
                break;
            }
        }
        if(t!=-1)
        {
            if(cnt%2==1)res+=n/t;
            else res-=n/t;
        }
    }
    cout<<res;
    return 0;
}
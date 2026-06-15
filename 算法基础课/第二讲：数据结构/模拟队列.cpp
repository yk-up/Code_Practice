// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e6+11;
// // int m;
// // int hh=0,tt=-1;
// // int q[N];
// // void push(int x)
// // {
// //     tt++;
// //     q[tt]=x;
// // }
// // void pop()
// // {
// //     hh++;
// // }
// // void empty()
// // {
// //     if(hh<=tt)cout<<"NO\n";
// //     else cout<<"YES\n";
// // }
// // void query()
// // {
// //     cout<<q[hh]<<endl;
// // }
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>m;
// //     while(m--)
// //     {
// //         string s;cin>>s;
// //         if(s=="push")
// //         {
// //             int x;cin>>x;
// //             push(x);
// //         }
// //         else if(s=="pop")
// //         {
// //             pop();
// //         }
// //         else if(s=="empty")
// //         {
// //             empty();
// //         }
// //         else 
// //         {
// //             query();
// //         }
// //     }
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int q[N],hh=0,tt=-1;
// int m;
// void push(int x)
// {
//     ++tt;
//     q[tt]=x;
// }
// void empty()
// {
//     if(hh<=tt) cout<<"NO\n";
//     else cout<<"YES\n";
// }
// void pop()
// {
//     hh++;//这是队列
// }
// void query()
// {
//     cout<<q[hh]<<endl;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>m;
//     while(m--)
//     {
//         string s;cin>>s;
//         if(s=="push")
//         {
//             int x;cin>>x;
//             push(x);
//         }
//         else if(s=="empty")
//         {
//             empty();
//         }
//         else if(s=="pop")
//         {
//             pop();
//         }
//         else if(s=="query")
//         {
//             query();
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=100002;
int q[N];
#define int long long
int m;
int hh=0,tt=-1;
void push(int x)
{
    ++tt;
    q[tt]=x;
}
void query()
{
    cout<<q[hh]<<endl;
}
void empty()
{
    if(hh<=tt)cout<<"NO\n";
    else cout<<"YES\n";
}
void pop()
{
   hh++;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m;
    while(m--)
    {
        string s;cin>>s;
        if(s=="push")
        {
            int x;cin>>x;
            push(x);
        }
        else if(s=="pop")pop();
        else if(s=="empty")empty();
        else if(s=="query")query();
    }
    return 0;
}
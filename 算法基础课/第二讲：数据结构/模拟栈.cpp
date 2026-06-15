// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// int m;
// int tt;//定义一个尾指针
// int stk[N];
// //从下标为 1 开始存
// void push(int x)
// {
//     tt++;
//     stk[tt]=x;
// }
// void pop()
// {
//     tt--;
// }
// void empty()
// {
//     if(tt>0)cout<<"NO\n";
//     else cout<<"YES\n";
// }
// void query()
// {
//     cout<<stk[tt]<<endl;
// }
// int main()
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
//         else if(s=="pop")
//         {
//             pop();
//         }
//         else if(s=="empty")
//         {
//             empty();
//         }
//         else
//         {
//             query();
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+11;
int stk[N];
int tt=0;
void push(int x)
{
    ++tt;
    stk[tt]=x;
}
void pop()
{
    tt--;
}
void query()
{
    cout<<stk[tt]<<endl;
}
void empty()
{
    if(tt>=1)cout<<"NO\n";
    else cout<<"YES\n";
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m;cin>>m;
    while(m--)
    {
        string s;cin>>s;
        if(s=="push")
        {
            int x;cin>>x;
            push(x);
        }
        else if(s=="pop")
        {
            pop();
        }
        else if(s=="empty")
        {
            empty();
        }
        else if(s=="query")
        {
            query();
        }
    }
    return 0;
}
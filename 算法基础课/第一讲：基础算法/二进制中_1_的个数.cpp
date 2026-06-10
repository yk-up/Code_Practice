//方法 1
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int a[N];
// int n;
// int get1(int x)
// {
//     int cnt=0;
//     while(x)
//     {
//         cnt+=(x&1);
//         x>>=1;
//     }
//     return cnt;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     int ans=0;
//     // for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         cout<<get1(x)<<" ";
//     }
//     //cout<<ans;
//     return 0;
// }


#include<iostream>
using namespace std;
int lowbit(int x){
    return x&(-x);
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;

        int res=0;
        while(x) x-=lowbit(x),res++;

        cout<<res<<' ';
    }
    return 0;
}
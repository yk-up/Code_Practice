// // //好难理解！！！
// // //https://gemini.google.com/app/301b975046015e72?utm_source=deepmind.google&utm_medium=referral&utm_campaign=gdm&utm_content=
// // #include <iostream>
// // using namespace std;

// // const int N=1e5+10;
// // const int M=1e6+10;
// // int n,m;
// // char p[N],s[M];
// // int ne[N];
// // //ne[i] 的含义是：在子串 p[1...i] 中，最长的相等的前缀和后缀的长度。
// // // j 是长度 j+1 是下标
// // //反正记住 回退操作为 j=ne[j]
// // int main(){
// //     cin>>n>>p+1>>m>>s+1;
// //     //abac
// //     for(int i=2,j=0;i<=n;i++){
// //         while(j && p[i]!=p[j+1]) j=ne[j];
// //         if(p[i]==p[j+1]) j++;
// //         ne[i]=j;
// //     }
    
// //     for(int i=1,j=0;i<=m;i++){
// //         while(j && s[i]!=p[j+1]) j=ne[j];
// //         if(s[i]==p[j+1]) j++;
// //         if(j==n){
// //             printf("%d ",i-n);
// //             j=ne[j];
// //         }
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// char s[N];
// char p[N];
// int ne[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n>>p+1;
//     int m;cin>>m>>s+1;
//     //求 ne 数组
//     for(int i=2,j=0;i<=n;i++)
//     {
//         //如果不相等就一直回退直到相等
//         while(j&&p[i]!=p[j+1])j=ne[j];
//         if(p[i]==p[j+1])j++;
//         ne[i]=j;
//     }

//     //求位置
//     for(int i=1,j=0;i<=m;i++)//注意这里是m
//     {
//         while(j&&s[i]!=p[j+1])j=ne[j];
//         if(s[i]==p[j+1])j++;
//         if(j==n)
//         {
//             cout<<i-n<<" ";
//             j=ne[j];
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+11;
int n,m;
char s[N],p[N];
int ne[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>p+1>>m>>s+1;
    //求 ne 数组
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&p[i]!=p[j+1])j=ne[j];//如果不相等就一直回退，直至p[i]==p[j+1]
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }

    for(int i=1,j=0;i<=m;i++)
    {
        while(j&&s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==n)
        {
            cout<<i-n<<" ";
            j=ne[j];
        }
    }
    return 0;
}
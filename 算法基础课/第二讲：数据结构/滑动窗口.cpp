// // // //单调对列
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define int long long
// // // const int N=1e6+11;
// // // int a[N];
// // // int n;
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>n;
// // //     for(int i=1;i<=n;i++)cin>>a[i];
// // //     int l=1,r=1;
// // //     int ans=0;
// // //     //map<int,bool>mp;
// // //     int count_
// // //     // for(int r=1;r<=n;i++)
// // //     // {
// // //     //     //初始化以一个窗口
// // //     // }
// // //     int min_=a[1];
// // //     int max_=a[1];
// // //     for(int i=1;i<=k;i++)
// // //     {
// // //         min_=min(min_,a[i]);
// // //         max_=max(max_,a[i]);
// // //     }
// // //     cout<<min_<<" "<<max_<<endl;

// // //     for(int i=k+1,)

// // //     return 0;
// // // }


// // //队头永远是有效元素
// // //最小值 单调递增 后面元素如果<=队尾 删去队尾
// // //最大值 单调递减 后面元素如果>=队尾 删去队尾 
// // #include <iostream>
// // #include <algorithm>
// // using namespace std;

// // const int N=1000010;
// // int a[N],q[N];
// // int n,k;

// // int main(){
// //     scanf("%d%d",&n,&k);
// //     for(int i=0;i<n;i++){
// //         scanf("%d",&a[i]);
// //     }
    
// //     int hh=0,tt=-1;
// //     for(int i=0;i<n;i++){
// //         if(hh<=tt && q[hh]<i-k+1) hh++;
// //         //找最小值《-=
// //         while(hh<=tt && a[q[tt]]>=a[i]) tt--;
// //         tt++;
// //         q[tt]=i;
        
// //         if(i>=k-1) printf("%d ",a[q[hh]]);
// //     }
// //     printf("\n");
    
// //     hh=0,tt=-1;
// //     for(int i=0;i<n;i++){
// //         if(hh<=tt && q[hh]<i-k+1) hh++;
// //         //找最大值》=
// //         while(hh<=tt && a[q[tt]]<=a[i]) tt--;
// //         tt++;
// //         q[tt]=i;
        
// //         if(i>=k-1) printf("%d ",a[q[hh]]);
// //     }
// //     printf("\n");
// //     return 0;
    
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n;
// const int N=1e5+11;
// int q[N];//存下标
// int a[N];
// // int hh=0,tt=-1;
// int hh=1,tt=0;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,k;cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)
//     {
//         while(hh<=tt&&q[hh]<=i-k)hh++;
//         whiile(hh<=tt&&a[q[tt]]>=a[i])tt--;
//         q[++tt]=i;
//         if(i>=k)cout<<a[q[hh]]<<" ";
//     }
//     cout<<endl;
//     hh=1,tt=0;
//     for(int i=1;i<=n;i++)
//     {
//         while(hh<=tt&&q[hh]<=i-k)hh++;
//         while(hh<=tt&&a[q[tt]]<=a[i])tt--;
//         q[++tt]=i;
//         if(i>=k)cout<<a[q[hh]]<<" ";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+11;
int q[N];//窗口内的下标
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int hh=1,tt=0;
    //从下标为 1 开始存储
    int n,k;cin>>n>>k;
    //找最小值，如果当前数比队尾小那么队尾永远不可能是最小值，弹出
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        // 1 2 i-k+1  i 
        int x=a[i];
        while(hh<=tt&&q[hh]<=i-k)hh++;//判断是否在窗口内
        while(hh<=tt&&a[q[tt]]>=x)tt--;
        q[++tt]=i;
        if(i>=k)cout<<a[q[hh]]<<" ";
    }

    cout<<endl;;
    hh=1,tt=0;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        while(hh<=tt&&q[hh]<=i-k)hh++;
        while(hh<=tt&&a[q[tt]]<=x)tt--;
        q[++tt]=i;
        if(i>=k)cout<<a[q[hh]]<<" ";
    }

    return 0;
}
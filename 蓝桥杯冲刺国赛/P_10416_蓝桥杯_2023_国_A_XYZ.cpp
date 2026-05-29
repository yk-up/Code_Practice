//#pragma  GCC optimize(2,3,"inline")

//得分不难，得满分难
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int l,r;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     //x y z的大小并不能确定
//     int t;cin>>t;
    
//     while(t--)
//     {
//         cin>>l>>r;
//         int ans=0;
//         for(int x=l;x<=r;x++)
//         {
//             for(int y=l;y<=r;y++)
//             {
//                 for(int z=l;z<=r;z++)
//                 {
//                     if(x+y==z)
//                     {
//                         ans++;
//                     }
//                 }
//             }
//         }
//         cout<<ans<<endl;
//     }

// }

// //找规律
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     //z=2L   1 
//     //Z=2L+1 2
//     //Z=2L+2 3
//     //Z=2L+3 4
//     //Z=2L+4 5
//     //Zmax=R  第R-2L+1 项
//     //等差数列
//     int t;cin>>t;
    
//     while(t--)
//     {
//         int L,R;cin>>L>>R;
//         //z 最小也得是 2R
//         if(R<2*L)
//         {
//             cout<<0<<endl;
//             continue;
//         }
//         int ans=0;
//         //防止溢出
//         //2L表示long long 2 不是 2L
//         ans=(R-2*L+1ll+1)*(R-2*L+1)/2;
//         cout<<ans<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    {   
        int L,R;cin>>L>>R;
        if(R<2*L)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=(R-2*L+1ll)*(R-2*L+1+1)/2ll;
        cout<<ans<<endl;
    }
    //Z1=2L x=L,y=L 1
    //Z2=2L+1 x=L,y=L+1  2
    //Zrmax=R           R-2L+1       
    
    return 0;
}
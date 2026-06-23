// // //欧拉定理：若a与p互质，则a^phi(p) mod p =1；
// ////本质上求的就是 a^(p-2)
// // #include<cstring>
// // #include<iostream>
// // #include<algorithm>

// // using namespace std;

// // typedef long long ll;

// // ll qmi (int a,int k,int p)
// // {
// //     ll res=1%p;
    
// //     while(k)
// //     {
// //         if(k & 1) res=res*a %p;
// //         a=a*(ll)a %p;
// //         k >>=1;
// //     }
    
// //     return res;
// // }
// // int main()
// // {
// //     int n;
// //     cin >> n;
    
// //     while(n--)
// //     {
// //         int a,p;
        
// //         scanf("%d%d",&a, &p);
        
// //         if(a%p==0) puts("impossible");
// //         else printf("%lld\n",qmi(a,p-2,p));
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int qmi(int base,int exp,int p)
// {
//     int res=1;
//     base=base%p;
//     while(exp)
//     {
//         if(exp&1)res=res*base%p;
//         base=base*base%p;
//         exp>>=1;
//     }
//     return res;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     while(n--)
//     {
//         int a,p;cin>>a>>p;
//         if(a%p==0)cout<<"impossible\n";
//         else cout<<qmi(a,p-2,p)<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int qmi(int base,int exp,int p)
{
    int res=1;
    base%=p;
    while(exp)
    {
        if(exp&1)res=res*base%p;
        base=base*base%p;
        exp>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--)
    {
        int a,p;cin>>a>>p;
        if(a%p==0)cout<<"impossible\n";
        else cout<<qmi(a,p-2,p)<<endl;
    }
    return 0;
}
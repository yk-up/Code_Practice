// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// bool is_prime[N];
// int n;
// void is_ok()
// {
//     //到n/i 就可以了
//     for(int i=2;i<=n/i;i++)
//     {
//         if(is_prime[i])
//         {
//             for(int j=i*i;j<=n;j+=i)
//             is_prime[j]=0;
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     memset(is_prime,1,sizeof is_prime);
//     is_prime[0]=is_prime[1]=0;
//     is_ok();
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(is_prime[i])cnt++;
//     }
//     cout<<cnt;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
bool is_prime[N];
int main()
{
    memset(is_prime,1,sizeof is_prime);
    is_prime[0]=is_prime[1]=0;
    int n;cin>>n;
    for(int i=2;i<=n/i;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                is_prime[j]=0;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(is_prime[i])cnt++;
    cout<<cnt;
    return 0;
}
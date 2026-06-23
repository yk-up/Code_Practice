// #include<bits/stdc++.h>
// using namespace std;
// bool is_prime(int x)
// {
//     if(x<=1)return false;
//     for(int i=2;i<=x/i;i++)//注意这个细节 x/i
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     while(n--)
//     {
//         int y;cin>>y;
//         if(is_prime(y))
//         {
//             cout<<"Yes\n";
//         }
//         else cout<<"No\n";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
    if(x<=1)return false;
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    while(n--)
    {
        int x;cin>>x;
        if(is_prime(x))cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
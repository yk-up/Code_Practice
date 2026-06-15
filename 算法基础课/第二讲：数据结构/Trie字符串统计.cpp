// #include <iostream>
// using namespace std;

// const int N=100010;
// int son[N][26],cnt[N],idx;//son[p][u] 表示：编号为 p 的节点的子节点中，代表字符 u 的那个子节点的编号是多少。
// char str[N];

// void insert(char str[]){
//     int p=0;
//     for(int i=0;str[i];i++){
//         int u=str[i]-'a';
//         if(!son[p][u]) son[p][u]=++idx;
//         p=son[p][u];
//     }
//     cnt[p]++;
// }

// int query(char str[]){
//     int p=0;
//     for(int i=0;str[i];i++){
//         int u=str[i]-'a';
//         if(!son[p][u]) return 0;
//         p=son[p][u];
//     }
//     return cnt[p];
// }

// int main(){
//     int n;
//     scanf("%d",&n);
    
//     while(n--){
//         char op[2];
//         scanf("%s%s",op,str);
//         if(op[0]=='I') insert(str);
//         else printf("%d\n",query(str));
//     }
//     return 0;
// }

//先跳吧
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int idx=0;
int n;
char str[N];
int son[N][26];//son[i][j]：编号为 i 节点的子节点为 j的编号
int cnt[N];
void insert(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(son[p][u]==0)son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
int query(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(son[p][u]==0)return 0;
        p=son[p][u];
    }
    return cnt[p];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char s;cin>>s;
        cin>>str;
        if(s=='I')insert(str);
        else
        {
            cout<<query(str)<<endl;
        }
        
    }
    return 0;
}
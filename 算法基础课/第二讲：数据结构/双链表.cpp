// // // #include <iostream>
// // using namespace std;

// // const int N=100010;
// // int m;
// // int idx,e[N],l[N],r[N];

// //注意这个的理解：其实是在构造一个空双链表：，以后所有操作都在这两个哨兵之间进行，因此：

// // 不需要维护 head
// // 不需要维护 tail
// // 不需要特判头结点
// // 不需要特判尾结点
// // void init(){
// //     r[0]=1;
// //     l[1]=0;
// //     idx=2;
// // }

// // void add(int k,int x){
// //     e[idx]=x;
// //     r[idx]=r[k];
// //     l[idx]=k;
// //     l[r[k]]=idx;
// //     r[k]=idx;
// //     idx++;
// // }

// // void remove(int k){
// //     r[l[k]]=r[k];
// //     l[r[k]]=l[k];
// // }

// // int main(){
// //     cin>>m;
// //     init();
// //     while(m--){
// //         string op;
// //         cin>>op;
// //         int x,k;
// //         if(op=="L"){
// //             cin>>x;
// //             add(0,x);
// //         }else if(op=="R"){
// //             cin>>x;
// //             add(l[1],x);
// //         }else if(op=="D"){
// //             cin>>k;
// //             remove(k+1);
// //         }else if(op=="IL"){
// //             cin>>k>>x;
// //             add(l[k+1],x);
// //         }else{
// //             cin>>k>>x;
// //             add(k+1,x);
// //         }
// //     }
// //     for(int i=r[0];i!=1;i=r[i]){
// //         cout<<e[i]<<' ';
// //     }
// //     cout<<endl;
// //     return 0;
// // }

// //下标是什么
// //第几次插入产生的节点编号
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// //真实数据从 2 开始
// int r[N],l[N],e[N];
// int m;
// int idx=2;
// //往右边插入一个元素
// void add(int k,int x)
// {
//     e[idx]=x;
//     r[idx]=r[k];
//     l[r[k]]=idx;

//     r[k]=idx;
//     l[idx]=k;
//     idx++;
// }
// void remove(int k)
// {
//     r[l[k]]=r[k];
//     l[r[k]]=l[k];
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>m;
//     r[0]=1,l[1]=0;//两段
//     idx=2;
//     while(m--)
//     {
//         string op;cin>>op;
//         // if(op=="R")
//         // {
//         //     int k;cin>>k;
//         //     remove(k+1);
//         // }

//         if(op=="R")
//         {
//             int x;cin>>x;
//             add(l[1],x);
//         }
//         else if(op=="L")
//         {
//             int x;cin>>x;
//             add(0,x);
//         }
//         else if(op=="D")
//         {
//             int k;cin>>k;
//             remove(k+1);
//         }
//         else if(op=="IL")
//         {
//             int k,x;cin>>k>>x;
//             add(l[k+1],x);
//         }
//         else if(op=="IR")
//         {
//             int k,x;cin>>k>>x;
//             add(k+1,x);
//         }
//     }

//         for(int i=r[0];i!=1;i=r[i]){
//         cout<<e[i]<<' ';
//     }
//     return 0;
// }



//0--------1
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+11;
int e[N],l[N],r[N];//有效k 从 2 开始
int m;
int idx=2;
//往 k 的右边插入
void add(int k,int x)
{
    e[idx]=x;

    r[idx]=r[k];
    l[r[k]]=idx;

    r[k]=idx;
    l[idx]=k;

    idx++;
}
void remove(int k)
{
    l[r[k]]=l[k];
    r[l[k]]=r[k];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m;
    l[1]=0,r[0]=1;
    while(m--)
    {
        string s;cin>>s;
        if(s=="L")
        {
            //最左端不就是 0 的右边吗
            int x;cin>>x;
            add(0,x);
        }
        else if(s=="R")
        {
            int x;cin>>x;
            //最右端就是在l[1]的右端
            add(l[1],x);
        }
        else if(s=="D")
        {
            int k;cin>>k;
            remove(k+1);//第一个插入的会放到 2 第二个插入的元素会放到 3
        }
        else if(s=="IL")
        {
            int k,x;cin>>k>>x;
            add(l[k+1],x);
        }
        else if(s=="IR")
        {
            int k,x;cin>>k>>x;
            add(k+1,x);
        }
    }
    // for(int i=2;i!=1;i=r[i])
    // cout<<e[i];

    //注意这个循环
     for(int i=r[0];i!=1;i=r[i])
    cout<<e[i]<<' ';

    return 0;
}
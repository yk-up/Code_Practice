// // //没做出来
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define int long long
// // // const int N=50002;
// // // int fa[N];
// // // int n,k;
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>n>>k;
// // //     for(int i=1;i<=n;i++)fa[i]=i;
// // //     while(k--)
// // //     {
// // //         int d,x,y;cin>>d>>x>>y;
// // //         if(d==1)
// // //         {
// // //             merge(x,y);
// // //         }
// // //         else if(d==2)
// // //         {

// // //         }
// // //     }
// // //     return 0;
// // // }

// // //这个比讲的那个方式更清晰
// // //扩展并查集
// // #include <iostream>
// // using namespace std;

// // const int N = 150010; // 动物最多 50000，开 3 倍空间
// // int p[N];

// // // 并查集的核心：找祖宗（带路径压缩，你之前写错的地方这里要注意）
// // int find(int x) {
// //     if (p[x] != x) p[x] = find(p[x]);
// //     return p[x];
// // }

// // void merge(int x, int y) {
// //     p[find(x)] = find(y);
// // }

// // int main() {
// //     // 优化输入输出流
// //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
// //     int n, k;
// //     cin >> n >> k;
    
// //     // 初始化 3N 个元素，各自为营
// //     for (int i = 1; i <= 3 * n; i++) p[i] = i;

// //     int res = 0; // 记录假话数量
// //     while (k--) {
// //         int d, x, y;
// //         cin >> d >> x >> y;

// //         // 条件2：X 或 Y 比 N 大，假话
// //         if (x > n || y > n) {
// //             res++;
// //             continue;
// //         }

// //         if (d == 1) {
// //             // 说法：X 和 Y 是同类
// //             // 冲突判定：如果 X 吃 Y (x的猎物域有y)，或者 Y 吃 X (x的天敌域有y)，则是假话
// //             if (find(x + n) == find(y) || find(x + 2 * n) == find(y)) {
// //                 res++;
// //             } else {
// //                 // 是真话，合并关系
// //                 merge(x, y);                 // X和Y是同类
// //                 merge(x + n, y + n);         // X的猎物也是Y的猎物
// //                 merge(x + 2 * n, y + 2 * n); // X的天敌也是Y的天敌
// //             }
// //         } else {
// //             // 说法：X 吃 Y
// //             // 冲突判定：如果 X 和 Y 是同类，或者 Y 吃 X，则是假话 (注意 x 吃 x 也会在这里被拦截，因为 find(x)==find(x) 必然成立)
// //             if (find(x) == find(y) || find(x + 2 * n) == find(y)) {
// //                 res++;
// //             } else {
// //                 // 是真话，确立环形关系
// //                 merge(x + n, y);         // X 的猎物是 Y 的同类
// //                 merge(x, y + 2 * n);     // X 的同类是 Y 的天敌
// //                 merge(x + 2 * n, y + n); // X 的天敌是 Y 的猎物 (因为 C吃A, A吃B -> C吃B是错的，C是Y的猎物才对，形成 A->B->C->A 的闭环)
// //             }
// //         }
// //     }
    
// //     cout << res << "\n";
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int fa[N];
// int res=0;
// //x 本体
// //x*n 猎物
// //x+2*n 天敌
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return ;
//     fa[yy]=xx;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
//     int n,k;cin>>n>>k;
//     for(int i=1;i<=3*n;i++)fa[i]=i;
//     for(int i=1;i<=k;i++)
//     {
//         int d;cin>>d;
//         int x,y;cin>>x>>y;
//         if(x>n||y>n)
//         {
//             res++;
//             continue;
//         }
//         if(d==1)
//         {
            
//             if(find(x+n)== find(y)||find(x+2*n)==find(y))
//             {
//                 res++;
//             }
//             else 
//             {
//                 merge(x,y);
//                 merge(x+n,y+n);
//                 merge(x+2*n,y+2*n);
//             }
//         }
//         else
//         {
//             //xchiy
//             //如果 y 吃 x 或者同类
//             if(find(x+2*n)==find(y)||find(x)==find(y))res++;
//             else{
//                 merge(x+n,y);
//                 merge(x,y+2*n);//x 和y的天敌是一类的
//                 merge(x+2*n,y+n);
//             }
//         }
//     }
//     cout<<res;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
const int N=50002*3;
int fa[N];
//本体
//猎物
//天敌

int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return;
    fa[yy]=xx;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=N;i++)fa[i]=i;
    int res=0;
    for(int i=0;i<k;i++)
    {
        int d,x,y;cin>>d>>x>>y;
        if(x>n||y>n)
        {
            res++;
            continue;
        }
        if(d==1)
        {
            //如果 x 吃y 或者 y 吃x(判断条件不唯一)

            if(find(x+2*n)==find(y)||find(y+2*n)==find(x))res++;
            else
            {
                merge(x,y);
                merge(x+n,y+n);
                merge(x+2*n,y+2*n);
            }
            
        }
        else if(d==2)
        {
            //ychix 或者 x 和y 是同一类就不对
            if(find(x)==find(y)||find(x+2*n)==find(y))res++;
            else
            {
                //x->y
                merge(x,y+2*n);
                //y->z->x
                merge(x+2*n,y+n);
                //x->z
                //x->y
                merge(x+n,y);
            }
        }
    }
    cout<<res;
    return 0;
}
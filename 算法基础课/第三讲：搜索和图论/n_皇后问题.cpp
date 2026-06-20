// //卡在不知道怎么遍历整个图，以行为切点
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define int long long
// // // const int N=20;
// // // int n;
// // // //bool st[N][N];//判断这个位置是否合法
// // // bool row[N];
// // // bool col[N];
// // // bool xie[N];
// // // char s[N][N];
// // // //左对角线
// // // void dfs(int x)
// // // {
// // //     if(y>n)
// // //     {
// // //         return;
// // //     }
// // //     if(row[x]||col[y])continue;
// // //     if()
// // //     s[x][y]='Q';

// // // }
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>n;
// // //     //行
// // //     dfs(1);
// // //     return 0;
// // // }



// // #include <iostream>
// // using namespace std;

// // const int N = 20; // 数据范围 n 最多是 9，开 20 足够了，对角线数组需要开到 2N
// // int n;
// // char g[N][N];     // 存储棋盘状态
// // bool col[N], dg[N], udg[N]; // col: 列, dg: 正对角线, udg: 反对角线
// // // 注意：按行搜索，每次必定在不同行，所以不需要记录 row 数组

// // // u 代表当前正在搜索第 u 行 (从 0 开始)
// // void dfs(int u) {
// //     // 递归边界：如果成功搜索到了第 n 行（0 到 n-1 都放好了），说明找到了一组解
// //     if (u == n) {
// //         for (int i = 0; i < n; i++) cout << g[i] << endl;
// //         cout << endl; // 每个方案后输出一个空行
// //         return;
// //     }

// //     // 尝试在当前第 u 行的第 i 列放置皇后
// //     for (int i = 0; i < n; i++) {
// //         // 如果当前列、正对角线、反对角线都没有放过皇后
// //         if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            
// //             // 1. 放置皇后，并记录占用状态
// //             g[u][i] = 'Q';
// //             col[i] = dg[u + i] = udg[n - u + i] = true;
            
// //             // 2. 递归进入下一行
// //             dfs(u + 1);
            
// //             // 3. 回溯（恢复现场），撤销皇后，以便尝试其他列的位置
// //             col[i] = dg[u + i] = udg[n - u + i] = false;
// //             g[u][i] = '.';
// //         }
// //     }
// // }

// // int main() {
// //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
// //     cin >> n;
    
// //     // 初始化棋盘全为空格 '.'
// //     for (int i = 0; i < n; i++)
// //         for (int j = 0; j < n; j++)
// //             g[i][j] = '.';

// //     // 从第 0 行开始搜索
// //     dfs(0);
    
// //     return 0;
// // }


// //按行搜索
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=20;
// int col[N];//只判断这一列有没有放过就行了，因为x按行搜索
// char s[N][N];
// int dg[N],udg[N];//主对角线：x+y 和为固定值 副对角线：x-y 是常数，但是下标不能为负数，所以+n
// int n;
// void dfs(int x)
// {
//     if(x>n)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)cout<<s[i][j];
//             cout<<endl;
//         }
//         cout<<endl;
//         return ;
//     }

//     //列
//     for(int y=1;y<=n;y++)
//     {
//         if(col[y]||dg[x+y]||udg[n+x-y])continue;
//         s[x][y]='Q';
//         col[y]=dg[x+y]=udg[n+x-y]=1;

//         dfs(x+1);

//         s[x][y]='.';
//         col[y]=dg[x+y]=udg[n+x-y]=0;
//     }
//     return;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)s[i][j]='.';
//     }
//     dfs(1);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int dg[N],udg[N];//主对角线 :x+y 为常数 ，副对角线：差为常数
int col[N];//按行搜索
char g[N][N];
int n;
void dfs(int x)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            cout<<g[i][j];
            cout<<endl;
        }
        cout<<endl;
    }

    for(int y=1;y<=n;y++)
    {
        if(col[y]||dg[x+y]||udg[x-y+n])continue;
        col[y]=dg[x+y]=udg[x-y+n]=1;
        g[x][y]='Q';
        dfs(x+1);
        g[x][y]='.';
        col[y]=dg[x+y]=udg[x-y+n]=0;
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)g[i][j]='.';
    }
    dfs(1);
    return 0;
}
// // // //这个交换的思路是什么
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define int long long
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

// // //     return 0;
// // // }


// // //难点：（1）距离数组 （2）转换的过程，如何讲字符串转换成矩阵，这个思路很巧妙
// // // #include <iostream>
// // // #include <algorithm>
// // // #include <unordered_map>
// // // #include <queue>

// // // using namespace std;

// // // int bfs(string start) {
// // //     // 目标状态
// // //     string end = "12345678x";
    
// // //     // 队列存储当前搜索到的状态（字符串形式）
// // //     queue<string> q;
    
// // //     // 距离数组，同时起到 st 数组判重的作用
// // //     unordered_map<string, int> dist;
    
// // //     // 初始化起点
// // //     q.push(start);
// // //     dist[start] = 0;
    
// // //     // 上下左右偏移量
// // //     int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
// // //     while (q.size()) {
// // //         auto t = q.front();
// // //         q.pop();
        
// // //         int d = dist[t];
        
// // //         // 找到终点，直接返回步数
// // //         if (t == end) return d;
        
// // //         // 找到 'x' 在一维字符串中的下标
// // //         int k = t.find('x');
// // //         // 将一维下标转化为二维矩阵中的坐标
// // //         int x = k / 3, y = k % 3; 技巧记好
        
// // //         // 尝试上下左右四个方向
// // //         for (int i = 0; i < 4; i++) {
// // //             int nx = x + dx[i], ny = y + dy[i];
            
// // //             // 如果移动没有越界
// // //             if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
// // //                 // 还原回一维下标，并交换位置生成新状态
// // //                 swap(t[k], t[nx * 3 + ny]);
                
// // //                 // 如果这个新状态之前没有搜到过（说明是最短路）
// // //                 if (!dist.count(t)) {
// // //                     dist[t] = d + 1;
// // //                     q.push(t);
// // //                 }
                
// // //                 // 恢复现场，为了下一个方向的尝试做准备
// // //                 swap(t[k], t[nx * 3 + ny]);
// // //             }
// // //         }
// // //     }
    
// // //     return -1; // 队列空了还没找到，说明无解
// // // }

// // // int main() {
// // //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// // //     string start;
    
// // //     // 读取 9 个字符组成的初始状态
// // //     for (int i = 0; i < 9; i++) {
// // //         char c;
// // //         cin >> c;
// // //         start += c;
// // //     }
    
// // //     cout << bfs(start) << "\n";
    
// // //     return 0;
// // // }

// // //

// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // string st;
// // int dx[]={1,-1,0,0};
// // int dy[]={0,0,-1,1};
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     for(int i=0;i<9;i++)
// //     {
// //         char s;cin>>s;
// //         st+=s;
// //     }
// //     string end="12345678x";
// //     unordered_map<string,int>d;//距离数组
// //     queue<string>q;
// //     q.push(st);
// //     d[st]=0;
// //     while(q.size())
// //     {
// //         string t=q.front();q.pop();
// //         if(t==end)
// //         {
// //             cout<<d[t];
// //             return 0;
// //         }
// //         int k=t.find('x');
// //         int x=k/3,y=k%3;
// //         int distance=d[t];
// //         for(int i=0;i<4;i++)
// //         {
// //             int xx=dx[i]+x;
// //             int yy=dy[i]+y;
// //             //0~2
// //             if(xx<0||xx>=3||yy<0||yy>=3)continue;
// //             int z=xx*3+yy;
// //             swap(t[z],t[k]);

// //             if(!d[t])//说明是最短的，因为还没走过
// //             {
// //                 d[t]=distance+1;
// //                 q.push(t);
// //             }
// //             swap(t[z],t[k]);
// //         }
// //     }
// //     cout<<-1;
// //     return 0;
// // }


// //还是不熟
// //这个题状态存的是整个图（巧妙的转换成字符串）
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// string s;
// int dx[]={0,0,1,-1};
// int dy[]={1,-1,0,0};
// typedef pair<int,int>PII;

// unordered_map<string,int>dist;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int i=0;i<9;i++)
//     {
//         char x;cin>>x;
//         s+=x;
//     }
//     queue<string>q;
//     string end="12345678x";
//     q.push(s);
//     dist[s]=0;
//     while(q.size())
//     {
//         string t=q.front();q.pop();
//         if(t==end)
//         {
//             cout<<dist[t];
//             return 0;
//         }
//         int distance=dist[t];
//         //将字符串转换成矩阵
//         int k=t.find('x');
//         int x=k/3,y=k%3;
//         for(int i=0;i<4;i++)
//         {
//             int xx=dx[i]+x;
//             int yy=dy[i]+y;
//             //0-2
//             if(xx<0||xx>=3||yy<0||yy>=3)continue;
//             int z=xx*3+yy;//再将矩阵下标转换成字符串对应的下标
//             // if(dist[z])continue;//走过了已经

//             swap(t[z],t[k]);
//             //if(dist[t])continue; 不能 continue 会影响t的还原
//             // if(!dist[t])
//             if(dist.count(t)==0)
//             {
//                 dist[t]=distance+1;
//                 q.push(t);
//             }
//             swap(t[z],t[k]);//还原原本的t
//         }
//     }
//     cout<<-1;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=0;i<9;i++)
    {
        char x;cin>>x;
        s+=x;
    }
    //queue<int>q;
    // int idx=s.find('x');
    // q.push(idx);
    // while(q.size())
    // {
    //     int x=q.front();q.pop();
        
    // }

    //状态应该是整个数组
    queue<string>q;
    string ed="12345678x";
    q.push(s);
    unordered_map<string,int>dist;
    dist[s]=0;
    while(q.size())
    {
        string t=q.front();q.pop();
        if(t==ed)
        {
            cout<<dist[t];
            return 0;
        }
        int k=t.find('x');
        int x=k/3,y=k%3;
        int distance=dist[t];//用一个变量存下 dist，因为后面 t 发生变化了
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>2||yy<0||yy>2)continue;
            int z=xx*3+yy;
            swap(t[k],t[z]);
            if(dist[t]==0)//注意这个，不要重复更新
            {   
                dist[t]=distance+1;
                q.push(t);
            }

            swap(t[k],t[z]);//还原t，是上一步的状态
        }
    }
    cout<<-1;
    return 0;
}
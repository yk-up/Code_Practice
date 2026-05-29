// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n;
// // const int N=502;
// // struct node
// // {
// //     int x_st,x_end;
// //     double k;//保证斜率相同，并且的话 x 的范围 对应的这个里面 (不用判断 y了吧)
// // }dat[N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     //在这个线上斜率相同并且 ux<=x<=vx
// //     for(int i=1;i<=n;i++) 
// //     {
// //         int ux,uy,vx,vy;cin>>ux>>uy>>vx>>vy;
// //         dat[i].x_st=ux,dat[i].x_end=vx;
// //         dat[i].k=(vy-uy)/(vy-ux);
// //     }

// //     return 0;
// // }



//我靠好聪明啊
// //不直接求线段和线段的交点，而是把每条线段上所有的“整数坐标点”全部找出来，扔进一个大“篮子”（map）里计数。最后看看篮子里哪些点出现了 2 次及以上，就是交点。
// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<map>

// using namespace std;
// typedef long long LL;
// typedef pair<int, int> PII;
// const int N = 505;

// int n, m;
// int ux[N], uy[N], vx[N], vy[N];
// map<PII, int> cnt_mp;

// int gcd(int a, int b)
// {
//     return b ? gcd(b, a % b) : a;   //当b为0时，a和0的最大公约数即为a，故返回a
// }

// // 记录每条线段经过的整数点
// void count(int i)
// {
//     int x1 = ux[i], x2 = vx[i];
//     int y1 = uy[i], y2 = vy[i];
//     int dx = x2 - x1, dy = y2 - y1;

////    这个地方不太理解！
//     int d = gcd(abs(dx), abs(dy));//说明这个距离可以分成d段
//     dx = dx / d, dy = dy / d;

//     for (int i = 0; ; i++) {
//         int x = x1 + i * dx, y = y1 + i * dy;
//         cnt_mp[{x, y}]++;   // 第i条线段经历的所有整数点的次数存到 map 中
//         if (x == x2 && y == y2) break;
//     }
// }


// void solve()
// {
//     cin >> n;

//     int mx = 0, my = 0;
//     for (int i = 0; i < n; i++) {
//         cin >> ux[i] >> uy[i] >> vx[i] >> vy[i];
//     }

//     // 遍历每条线段经过的整数点
//     for (int i = 0; i < n; i++) {
//         count(i);
//     }

//     // 遍历 map 统计交点数量
//     int ans = 0;
//     for (map<PII, int>::iterator it = cnt_mp.begin(); it != cnt_mp.end(); it++) {
//         if (it->second >= 2) ans++;
//     }

//     // 输出答案
//     cout << ans << endl;

// }


// int main()
// {
//     solve();
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// typedef pair<int,int>PII;
// map<PII,int>mp;
// const int N=502;
// int n;
// int ux[N],uy[N],vx[N],vy[N];
// int __gcd(int x,int y)
// {
//     if(y==0)return x;
//     return __gcd(y,x%y);
// }
// void count_(int i)
// {
//     int x=ux[i],y=uy[i];
//     int xx=vx[i],yy=vy[i];

//     int dx=xx-x;
//     int dy=yy-y;
//     //int d=abs(__gcd(dx,dy));
//     int d=__gcd(abs(dx),abs(dy));
    

//     // 修复除以零的隐藏 bug
//     if (d == 0) {
//         mp[{x, y}]++;
//         return;
//     }
//     dx=dx/d;
//     dy=dy/d;

//     for(int k=0;;k++)
//     {
//         int new_x=x+k*dx,new_y=y+k*dy;
//         mp[{new_x,new_y}]++;
//         if(new_x==xx&&new_y==yy)
//         {
//             break;
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>ux[i]>>uy[i]>>vx[i]>>vy[i];
//     for(int i=1;i<=n;i++)
//     {
//         count_(i);
//     }
//     int cnt=0;
//     for(auto it:mp)
//     {
//         if(it.second>=2)cnt++;
//     }
//     cout<<cnt<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
const int N=1000;
map<PII,int>mp;//记录每个点经过的次数
int n;
int ux[N],uy[N],vx[N],vy[N];
int __gcd(int x,int y)
{
    if(y==0)return x;
    return __gcd(y,x%y);
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ux[i]>>uy[i]>>vx[i]>>vy[i];
        //int dx=abs(ux[i]-vx[i]);
        //int dy=abs(uy[i]-vy[i]);

        // int dx=(ux[i]-vx[i]);
        // int dy=(uy[i]-vy[i]);

        int dx=(vx[i]-ux[i]);
        int dy=(vy[i]-uy[i]);//注意方向
        //int d=__gcd(dx,dy);//最多可以分的段数
        int d=__gcd(abs(dx),abs(dy));

        if(d==0)
        {
            mp[{x,y}]++;
            continue;
        }
        dx/=d;
        dy/=d;

        for(int j=0;;j++)
        {
            int x=ux[i]+j*dx;//这里是dx不是d
            int y=uy[i]+j*dy;
            mp[{x,y}]++;
            if(x==vx[i]&&y==vy[i])break;
        }
    }

    int cnt=0;
    for(auto it:mp)
    {
        if(it.second>=2)cnt++;
    }
    cout<<cnt<<endl;
    
    return 0;
}
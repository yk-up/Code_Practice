// #include <iostream>
// #include <set>

// using namespace std;

// int main() {
//     // 使用你提供的数组（有效下标 1 到 10）
//     bool a[11][11]={
//         {0,0,0,0,0,0,0,0,0,0,0},
//         {0,1,1,0,1,0,1,1,1,1,1},
//         {0,1,1,1,0,0,1,1,1,1,0},
//         {0,1,1,0,0,1,0,1,1,1,1},
//         {0,1,0,1,1,0,1,1,1,1,0},
//         {0,1,0,1,0,1,1,1,1,0,0},
//         {0,1,0,0,1,0,1,0,1,0,1},
//         {0,1,1,1,1,1,1,1,1,1,0},
//         {0,0,1,1,1,1,1,1,1,1,0},
//         {0,0,1,1,0,1,0,1,1,1,1},
//         {0,1,0,1,0,0,1,0,1,0,0}
//     };

//     set<int> square_sizes;

//     // 遍历所有可能的两个点作为正方形的一条边 (下标 1 到 10)
//     for (int r1 = 1; r1 <= 10; ++r1) {
//         for (int c1 = 1; c1 <= 10; ++c1) {
//             if (!a[r1][c1]) continue;

//             for (int r2 = 1; r2 <= 10; ++r2) {
//                 for (int c2 = 1; c2 <= 10; ++c2) {
//                     if (r1 == r2 && c1 == c2) continue;
//                     if (!a[r2][c2]) continue;

//                     // 计算向量 (dr, dc)
//                     int dr = r2 - r1;
//                     int dc = c2 - c1;

//                     // 旋转 90 度求另外两个点
//                     int r3 = r2 + dc;
//                     int c3 = c2 - dr;
//                     int r4 = r1 + dc;
//                     int c4 = c1 - dr;

//                     // 判断越界和是否为红钉
//                     if (r3 >= 1 && r3 <= 10 && c3 >= 1 && c3 <= 10 &&
//                         r4 >= 1 && r4 <= 10 && c4 >= 1 && c4 <= 10 &&
//                         a[r3][c3] && a[r4][c4]) {
                        
//                         int size_squared = dr * dr + dc * dc;
//                         square_sizes.insert(size_squared);
//                     }
//                 }
//             }
//         }
//     }

//     // // 打印集合里的所有边长平方，方便核对
//     // cout << "找到的不同边长（平方）有：" << endl;
//     // for (int sz : square_sizes) {
//     //     cout << sz << " ";
//     // }
//     // cout << "\n\n";
//     // cout << "最终答案（不同种类的正方形）：" << square_sizes.size() << endl;
//     cout<<square_sizes.size()<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
bool a[11][11]={
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,1,0,1,1,1,1,1},
        {0,1,1,1,0,0,1,1,1,1,0},
        {0,1,1,0,0,1,0,1,1,1,1},
        {0,1,0,1,1,0,1,1,1,1,0},
        {0,1,0,1,0,1,1,1,1,0,0},
        {0,1,0,0,1,0,1,0,1,0,1},
        {0,1,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,1,1,1,1,0},
        {0,0,1,1,0,1,0,1,1,1,1},
        {0,1,0,1,0,0,1,0,1,0,0}
    };
set<int>s;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    set<int>s;
    for(int r1=1;r1<=10;r1++)
    {
        for(int c1=1;c1<=10;c1++)
        {
            if(a[r1][c1]==0)continue;
            for(int r2=1;r2<=10;r2++)
            {
                for(int c2=1;c2<=10;c2++)
                {
                    if(r1==r2&&c1==c2)continue;
                    if(a[r2][c2]==0)continue;


                    int dr=r2-r1;
                    int dc=c2-c1;

                    int r3=r2+dc;
                    int c3=c2-dr;
                    int r4=r1+dc;
                    int c4=c1-dr;

                    if(r3>=1&&r3<=10&&c3>=1&&c3<=10&&r4>=1&&r4<=10&&c4>=1&&c4<=10&&a[r3][c3]&&a[r4][c4])
                    {
                        int size_=dr*dr+dc*dc;//边长的平方
                        s.insert(size_);
                    }
                }
            }
        }
    }
    cout<<s.size()<<endl;
    return 0;
}
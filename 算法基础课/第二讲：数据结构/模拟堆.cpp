#include <iostream>
#include <string.h>
using namespace std;
const int N = 100010;
int hp[N],ph[N],n,h[N],cnt,m,k,x;

void heap_swap(int a, int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void down(int u){
    int t = u;
    if(2*u <= cnt && h[t] > h[2*u]) t = 2*u;
    if(2*u + 1 <= cnt && h[t] > h[2*u+1]) t = 2*u+1;
    if(t!=u){
        heap_swap(t,u);
        down(t);
    }
}

void up(int u){
    while(u/2 && h[u/2] > h[u]){
        heap_swap(u,u/2);
        u/=2;
    }
}

int main(){
    cin >> n;
    while(n--){
        string op;
        cin >> op;
        if(op == "I"){
        cin >> x;
        cnt++;
        m++;
        h[cnt] = x;
        hp[cnt] = m;
        ph[m] = cnt;
        down(cnt),up(cnt);
        }
        else if(op == "PM"){
            cout << h[1] << endl;
        }
        else if(op == "DM"){
            heap_swap(1,cnt);
            cnt--;
            down(1);
        }
        else if(op == "D"){
            cin >> k;
            int t = ph[k];
            heap_swap(t,cnt);
            cnt--;
            down(t),up(t);
        }
        else if(op == "C"){
            cin >> k >> x;
            int t =ph[k];
            h[t] = x;
            down(t),up(t);
        }
    }
    
    return 0;
}
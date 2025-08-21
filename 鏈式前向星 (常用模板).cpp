//這簡單的模板還有存在的必要嗎 (惱

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F first
#define S second
using LL=long long;

struct CFS{
    //1-based存圖
    vector<int> head,nxt,to; //head下標節點u指向第一條邊，to下標邊編號指向去的節點v，nxt則表示對於當前的邊，下一條邊的下標索引為何(0表示無下一邊)
    int idx;
    CFS(int n,int m):head(n+1),nxt(m+1),to(n+1),idx(1){}//若無向圖要存兩個邊，需開2m+1;

    void add(int u,int v){
    to[idx]=v;
    nxt[idx]=head[u];
    head[u]=idx;
    ++idx;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}











#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct Fenwick{
    int n;
    vector<int> bit;

    Fenwick(int n):n(n), bit(n+2){}

    int lb(int x){return x&-x;}

    void add(int idx,int x){
        for (;idx<=n;idx+=lb(idx)){bit[idx]+=x;}
        return;
    }

    int psum(int idx){
        int ans=0;
        for (;idx>0;idx-=lb(idx)){ans+=bit[idx];}
        return ans;
    }

    int rsum(int a,int b){
        return psum(b)-psum(a-1);
    }






};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> A(n+1);
    for (int i=1;i<=n;++i){
        cin>>A[i];
    }
    Fenwick tree(n);

    for (int i=1;i<=n;++i){
        tree.add(i,A[i]);
    }

    int op,a,b;
    while (m--){
        cin>>op>>a>>b;
        if (op&1){
            tree.add(a,b);
        }
        else{
            cout<<tree.rsum(a,b)<<"\n";
        }
    }


    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
#define pb push_back
const LL MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct DSU{
    vector<int> pa,area;
    int marea=1;
    int cnt;
    DSU(int sizu,int cnt):pa(sizu), area(sizu, 1), cnt(cnt){iota(all(pa), 0);}

    int found(int x){return (x==pa[x]?x:found(pa[x]));}

    void unite(int x, int y){
        int p=found(x);
        int q=found(y);
        if (p==q) return;
        if (area[p]<area[q]){
            pa[p]=q;
            area[q]+=area[p];
            marea=max(marea, area[q]);
        }
        else {
            pa[q]=p;
            area[p]+=area[q];
            marea=max(marea, area[p]);
        }
        --cnt;
        return;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n,k,cnt=0;
    cin>>m>>n>>k;
    vector<vector<int>> grid(m,vector<int>(n));
    for (auto& x:grid){
        for (auto& y:x){
            cin>>y;
            if (y==1) ++cnt;
        }
    }

    vector<pair<int, int>> op(k);
    for (auto& x:op) cin>>x.fi>>x.se;

    DSU dsu(m*n, cnt);
    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            if (grid[i][j]==1){
                if (i-1>=0 && grid[i-1][j]==1){
                    dsu.unite((i-1)*n+j, i*n+j);
                }
                if (j-1>=0 && grid[i][j-1]==1){
                    dsu.unite(i*n+j-1, i*n+j);
                }
            }
        }
    }
    int fres=dsu.marea, sres=dsu.cnt;


    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int nx=0,ny=0;
    for (auto& X:op){
        if (grid[X.fi-1][X.se-1]==0){
            grid[X.fi-1][X.se-1]=1;
            ++dsu.cnt;
            for (int i=0;i<=3;++i){
                nx=X.fi-1+dx[i];
                ny=X.se-1+dy[i];
                if (nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                    dsu.unite(nx*n+ny, (X.fi-1)*n+X.se-1);
                }
            }
        }
        fres+=dsu.marea;
        sres+=dsu.cnt;
    }
    cout<<fres<<"\n"<<sres;


    return 0;

}






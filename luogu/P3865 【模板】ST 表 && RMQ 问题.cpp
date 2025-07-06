#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> A(n+1);
    int LOG = __lg(n)+1;
    vector<vector<int>> ST(n+1, vector<int>(LOG));

    for (int i=1;i<=n;++i){
        cin>>A[i];
        ST[i][0]=A[i];
    }
    for (int j=1;(1<<j)<=n;++j){
        for (int i=1;i+(1<<j)-1<=n;++i){
            ST[i][j]=max(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
        }
    }


    int l,r;
    while (m--){
        cin>>l>>r;
        int k=__lg(r-l+1);
        cout<<max(ST[l][k],ST[r-(1<<k)+1][k])<<"\n";

    }


    return 0;
}


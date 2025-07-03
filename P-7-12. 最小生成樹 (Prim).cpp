#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define LL long long
#define pb push_back
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> edge(n);
    int a,b,c;
    for (int i=0;i<m;++i){
        cin>>a>>b>>c;
        edge[a].pb({b,c});
        edge[b].pb({a,c});
    }

   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minpq;
   for (auto& x:edge[0]){
    minpq.push({x.se,x.fi});
   }

   vector<int> ved(n);
   ved[0]=1;
   int res=0;
   pair<int,int> x;
   while (!minpq.empty()){
        x=minpq.top();
        minpq.pop();
        if (ved[x.se]) continue;
        ved[x.se]=1;
        res+=x.fi;
        for (auto& y:edge[x.se]){
            if (ved[y.fi]) continue;
            minpq.push({y.se,y.fi});
        }
   }
   bool flag=false;
   for (auto& x:ved){
    if (!x){
        flag=true;
        break;
    }
   }
   cout<<(flag?-1:res);
    return 0;
}

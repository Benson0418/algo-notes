#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,time=0,cnt=0;
    cin>>n;
    vector<vector<P>> tree(n);
    for(int a,b,i=1;i<n;++i){
        cin>>a>>b;
        tree[i].push_back({a,b});
        tree[a].push_back({i,b});
    }
    deque<T> que={make_tuple(0,0,0)};
    vector<int> ved(n);
    T x;
    while (!que.empty()){
        x=que.front();
        que.pop_front();
        if (ved[get<0>(x)]) continue;
        ved[get<0>(x)]=1;
        cnt=max(cnt,get<2>(x));
        time=max(get<1>(x),time);
        for (auto& y:tree[get<0>(x)]){
            if (ved[y.first]) continue;
            que.push_back(make_tuple(y.first,get<1>(x)+y.second,get<2>(x)+1));
        }

    }

    cout<<time<<"\n"<<cnt;
    return 0;
}

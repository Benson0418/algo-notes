#include<bits/stdc++.h>
using namespace std;
typedef int64_t LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n,res=0;
    cin>>n;
    vector<LL> parent(n,-1),depth(n),cnt(n),deg(n);

    for (LL p,w,i=1;i<n;++i){
        cin>>p>>w;
        parent[i]=p;
        ++deg[p];
        depth[i]=w;
    }

    LL med=-1;
    deque<LL> que;
    for (LL i=0;i<n;++i){
        if (!deg[i]){
            que.push_front(i);
        }
    }

    int x;
    while (!que.empty()){
        x=que.front();
        que.pop_front();
        ++cnt[x];


        if (med==-1 && cnt[x]>=(n+1)/2){
            med=x;
        }

        if (parent[x]!=-1){
            res+=min(cnt[x],n-cnt[x])*depth[x];
            cnt[parent[x]]+=cnt[x];
            --deg[parent[x]];
            if (!deg[parent[x]]){
                que.push_back(parent[x]);
            }
        }
        else break;
    }

    cout<<med<<"\n"<<res;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,res=0;
    cin>>n;
    vector<int> parent(n),indeg(n);
    for (int a,i=1;i<n;++i){
        cin>>a;
        parent[i]=a;
        ++indeg[a];
    }
    deque<int> que;
    vector<int> pick(n);
    for(int i=0;i<n;++i){
        if (!indeg[i]) que.push_back(i);
    }

    int x;
    while (!que.empty()){
        x=que.front();
        que.pop_front();
        if (!x) {
            if (!pick[x]) ++res;
            break;
        }
        if (!pick[x]){
            ++res;
            pick[parent[x]]=1;
        }
        --indeg[parent[x]];
        if (!indeg[parent[x]]){
            que.push_back(parent[x]);
        }
    }
    cout<<res;

    return 0;
}




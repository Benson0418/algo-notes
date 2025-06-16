#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,P,L,R,lx=0,rx=0;
    pair<int,int> x;
    cin>>n>>P>>L>>R;
    vector<int> S(n);
    for (int& z:S) cin>>z;
    vector<int> visited(n);
    deque<pair<int,int>> que;
    que.push_back({0,0});

    while (!que.empty()){
        x=que.front();
        que.pop_front();
        if (P==x.first){
            cout<<x.second;
            return 0;
        }
        visited[x.first]=1;
        lx=x.first-L;
        rx=x.first+R;
        if (lx>=0 && lx<n && !visited[lx]){
            if (S[lx]!=lx){
                visited[lx]=1;
                lx=S[lx];
            }
            if (lx>=0 && lx<n){
                que.push_back({lx,x.second+1});
            }
        }
        if (rx<n && rx>=0 && !visited[rx]){
            if (S[rx]!=rx){
                visited[rx]=1;
                rx=S[rx];
            }
            if (rx>=0 && rx<n){
                que.push_back({rx,x.second+1});
            }
        }
    }

    cout<<-1;
    return 0;
}

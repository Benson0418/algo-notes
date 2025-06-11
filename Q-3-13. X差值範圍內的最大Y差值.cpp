#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,L;
    cin>>N>>L;
    vector<int> X;
    vector<pair<int,int>> M;
    deque<pair<int,int>> maxq,minq; //»¼´î´Ì »¼¼W´Ì
    int r=0,res=0;

    for (int a,i=0;i<N;++i){
        cin>>a;
        X.push_back(a);
    }
    for (int a,i=0;i<N;++i){
        cin>>a;
        M.push_back({X[i],a});
    }
    sort(M.begin(),M.end());
    while (r<N){
        while (!maxq.empty() && M[r].second>=maxq.back().second){
            maxq.pop_back();
        }
        maxq.push_back(M[r]);
        while (!minq.empty() && M[r].second<=minq.back().second){
            minq.pop_back();
        }
        minq.push_back(M[r]);
        while (!maxq.empty() && maxq[0].first<M[r].first-L){
            maxq.pop_front();
        }
        while (!minq.empty() && minq[0].first<M[r].first-L){
            minq.pop_front();
        }
        res=max(maxq[0].second-minq[0].second,res);
        ++r;
    }
    cout<<res<<"\n";





    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int N,L;
    cin>>N>>L;
    vector<int> seq;
    deque<pair<int,int>> max_q,min_q; //»¼´î´Ì¡B»¼¼W´Ì

    for (int a,i=0;i<N;++i){
        cin>>a;
        seq.push_back(a);
    }
    for (int i=0;i<L;++i){
        while (!max_q.empty() && max_q.back().first<seq[i]){
            max_q.pop_back();
        }
        max_q.push_back({seq[i],i});
        while (!min_q.empty() && min_q.back().first>seq[i]){
            min_q.pop_back();
        }
        min_q.push_back({seq[i],i});
    }
    int res=max_q[0].first-min_q[0].first;
    for (int l=0,r=L;r<N;++r,++l){
        if (max_q[0].second<=l){
            max_q.pop_front();
        }
        if (min_q[0].second<=l){
            min_q.pop_front();
        }
        while (!max_q.empty() && max_q.back().first<seq[r]){
            max_q.pop_back();
        }
        while (!min_q.empty() && min_q.back().first>seq[r]){
            min_q.pop_back();
        }
        max_q.push_back({seq[r],r});
        min_q.push_back({seq[r],r});
        res=max(res,max_q[0].first-min_q[0].first);
    }
    cout<<res<<"\n";



    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int N,K;
vector<int> P;
bool flag=0;

bool solve(int R) {
    int i=0,k=0,idx;
    while (k<K && i<N) {
        idx=P[i]+R;
        while (i<N && P[i]<=idx) ++i;
        ++k;
    }
    return i==N;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>K;
    P.resize(N);
    for(auto& x:P)cin>>x;
    sort(P.begin(),P.end());
    int l=0,r=P.back(),mid;
    while (l<r){
        mid=(l+r)/2;
        if (solve(mid)) r=mid;
        else l=mid+1;
    }

    cout<<r<<"\n";
    return 0;
}

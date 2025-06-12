#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> A,pair<int,int> B){
    return A.second<=B.second;
}

int main(){
    int o,n,t;
    bool flag;
    vector<int> T;
    vector<pair<int,int>> M;
    cin>>o;
    for (int i=0;i<o;++i){
        flag=1;
        t=0;
        cin>>n;
        T.resize(n);
        M.resize(n);
        for (int& x:T) cin>>x;
        for (int j=0;j<n;++j){
            M[j].first=T[j];
            cin>>M[j].second;
        }
        sort(M.begin(),M.end(),cmp);
        for (int k=0;k<n;++k){
            t+=M[k].first;
            if (t>M[k].second) {
                flag=0;
                break;
            }
        }
        if (flag){
            cout<<"yes"<<"\n";
        }
        else{
            cout<<"no"<<"\n";
        }
    }


    return 0;
}

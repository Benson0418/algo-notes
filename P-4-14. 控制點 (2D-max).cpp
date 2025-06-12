#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> X(N);
    vector<pair<int,int>> M(N);
    vector<int> monostack; //»¼´î´Ì
    for (int& x:X)cin>>x;
    for (int i=0;i<N;++i){
        M[i].first=X[i];
        cin>>M[i].second;
    }
    sort(M.begin(),M.end());
    for (int i=0;i<N;++i){
        while (!monostack.empty() && M[i].second>=monostack.back()) monostack.pop_back();
        monostack.push_back(M[i].second);
    }
    cout<<monostack.size()<<"\n";



    return 0;
}

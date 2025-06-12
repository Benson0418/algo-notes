#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y,res=0;
    cin>>n>>x>>y;
    vector<pair<int,int>> M(n);
    for (pair<int,int>& z:M) cin>>z.first>>z.second;
    sort(M.begin(),M.end());



    int i=0,z;
    while (x<y && i<n){
        z=x;
        while (i<n && M[i].first<=x){
            z=max(z,M[i].second);
            ++i;
        }
        if (z==x) break;
        x=z;
        ++res;
    }
    cout<<(x>=y?res:-1);
    return 0;
}

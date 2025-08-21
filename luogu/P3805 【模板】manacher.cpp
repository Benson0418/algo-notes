#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)x.size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,w="#";
    cin>>s;
    for (auto& x:s){
        w.pb(x);
        w.pb('#');
    }

    int n=sz(w);
    vector<int> p(n);
    int res=0;
    for (int i=0,c=0,r=0,rad;i<n;++i){
        rad=(r>i)?min(p[2*c-i],r-i):1;
        while (i+rad<n && i-rad>=0 && w[i+rad]==w[i-rad]){
            ++rad;
        }
        if (i+rad>r){
            r=i+rad;
            c=i;
        }
        res=max(res,rad);
        p[i]=rad;
    }
    cout<<res-1;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)x.size())

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S,T;
    int n,m;
    cin>>S>>T;
    n=sz(S),m=sz(T);
    vector<int> nxt(m);
    int pl=0,i=1;
    while (i<m){
        if (T[pl]==T[i]){
            nxt[i++]=++pl;
        }
        else{
            if (pl==0) ++i;
            else pl=nxt[pl-1];
        }
    }
    i=0;
    int j=0;
    vector<int> stk;
    vector<char> res;
    while (i<n){
        if (S[i]==T[j]){
            res.push_back(S[i++]);
            stk.push_back(j++);
        }
        else{
            if (j==0){
                res.push_back(S[i++]);
                stk.push_back(-1);
            }
            else{
                j=nxt[j-1];
            }
        }
        if (j==m){
            for (int k=0;k<m;++k){
                res.pop_back();
                stk.pop_back();
            }
            j=(stk.empty())?0:stk[sz(stk)-1]+1;
        }
    }
    for (auto& x:res){
        cout<<x;
    }
    return 0;
}

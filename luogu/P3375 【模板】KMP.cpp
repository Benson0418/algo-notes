#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())

using LL = long long;
const int BASE = 131;
const int MOD = 1e9 + 9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text,patt;
    cin>>text>>patt;
    int n=sz(text),m=sz(patt);
    vector<int> pi(m);
    int pl=0,r=1;
    while (r<m){
        if (patt[pl]==patt[r]){
            pi[r++]=++pl;
        }
        else {
            if (pl==0){
                pi[r++]=0;
            }
            else{
                pl=pi[pl-1];
            }
        }
    }


    int i=0,j=0;
    while (i<n){
        if (text[i]==patt[j]){
            ++j;
            if (j==m){
                cout<<i-m+1+1<<"\n";
                j=pi[j-1];
            }
            ++i;

        }
        else{
            if (j==0){
                ++i;
            }
            else{
                j=pi[j-1];
            }
        }
    }
    for (int& x:pi){
        cout<<x<<" ";
    }



    return 0;
}


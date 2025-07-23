#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F first
#define S second
using LL=long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin>>n;

    vector<int> isP(n+1,1);
    vector<int> Primes={0};

    for (int i=2;i<=n;++i){
        if (isP[i]) Primes.pb(i);
        for (j=1;j<Primes.size() && i*Primes[j]<=n;++j){
            isP[i*Primes[j]]=0;
            if (i%Primes[j]==0) break;
        }

    }



    return 0;
}




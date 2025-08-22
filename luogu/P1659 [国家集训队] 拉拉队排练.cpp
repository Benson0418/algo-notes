#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 19930726LL;

ll qp(ll a, ll p){
    ll res=1;
    a%=MOD;
    while (p){
        if (p&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        p >>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,K;
    cin>>n>>K;
    string s;
    cin>>s;
    vector<ll> p(n);

    ll c=0, r=0;
    for (ll i=0;i<n;i++) {
        ll len=(i<r)?min(p[2*c-i],r-i):1;
        while (i+len<n&&i-len>=0&&s[i+len]==s[i-len]){
            len++;
        }
        if (i+len>r) {
            r=i+len;
            c=i;
        }
        p[i]=len;
    }



    vector<ll> cnt(n+1);
    for (ll i=0;i<n;i++) {
        cnt[2*p[i]-1]++;
    }

    ll total=0;
    for (ll i=n;i>=1;--i) {
        if (i%2==1) {
            total+=cnt[i];
        }
        cnt[i]=total;
    }

    ll ans=1;
    for (ll i = n; i >= 1 && K > 0; i--) {
        if (i%2==0 || cnt[i]==0) continue;
        ll take = min(K,cnt[i]);
        ans = (ans*qp(i, take)) % MOD;
        K -= take;
    }

    cout <<(K?-1:ans);


    return 0;
}

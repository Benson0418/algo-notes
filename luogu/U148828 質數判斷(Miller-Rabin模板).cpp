#include <bits/stdc++.h>
using namespace std;

/*
待測數據保證在10**18以內
對於要測試的數num，令變數
num-1=2^s*d，d為奇數、s為num-1質因數分解中2的最大個數
米勒-拉賓法告訴我們，若對於隨機挑選的憑證i，符合以下兩條件之一，則所測試的數極有可能為質數，而若不符合必為合數
i^d≡±1 (mod num)
i^(d*2^j)≡-1 (mod num) 其中j可為1~s-1中的任何數
*/

using ll=unsigned long long;
constexpr ll witness[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll qpow(ll a, ll b, ll mod=0){
    if (mod==1) return 0;
    ll res=1;
    if (mod==0){
        while (b){
            if (b&1) res*=a;
            a*=a;
            b>>=1;
        }
    }
    else{
        a%=mod;
        while (b){
            if (b&1) res=(__int128)res*a%mod;
            a=(__int128)a*a%mod;
            b>>=1;
        }
    }
    return res;
}

bool isPrime(ll num){
    if (num<=2) return num==2;
    if (~num&1) return false;
    ll s=0;
    ll d=num-1;
    while (~d&1){
        ++s;
        d>>=1;
    }
    for (auto& i:witness){

        if (i>=num) break;
        ll x=qpow(i,d,num);
        if (x==1 || x==num-1) continue;
        bool flag=false;
        for (ll j=1;j<s;++j){
            x=(__int128)x*x%num;
            if (x==num-1){
                flag=true;
                break;
            }
        }
        if (flag) continue;
        else return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while (n--){
        ll x;
        cin>>x;
        cout<< (isPrime(x)?"Yes":"No") <<endl;
    }

    return 0;
}

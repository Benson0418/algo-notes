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


   function<LL(LL,LL,LL&,LL&)> exgcd=[&](LL a,LL b, LL &x, LL &y){
       if (b==0) return x=1,y=0,a;
       LL d=exgcd(b,a%b,y,x);
       y-=a/b*x;
       return d;
   };

   auto modinv=[&](LL a, LL mod)->LL{
    LL x,y;
    LL g=exgcd(a,mod,x,y);
    if (g!=1) return -1;
    return (x%mod+mod)%mod;
   };


    return 0;
}










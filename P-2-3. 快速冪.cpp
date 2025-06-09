#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int qpow(ull x,ull y,ull p){
    if (y==1){
        return x%p;
    }
    else{
        if (y&1){
            return (qpow(x,y/2,p)%p)*(qpow(x,y/2+1,p)%p)%p;
        }
        else{
            return (qpow(x,y/2,p)%p)*(qpow(x,y/2,p)%p)%p;
        }
    }
    return 1;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull x,y,p;
    cin>>x>>y>>p;
    cout<<qpow(x,y,p)<<endl;



    return 0;
}

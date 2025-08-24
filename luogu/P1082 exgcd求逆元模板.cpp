#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,P;
    cin>>n>>P;

    int x,y,d;
    auto exgcd=[&](auto&& self,int a,int b) ->int{
        if (b==0){
            d=a;
            x=1;
            y=0;
            return a;
        }
        d=self(self,b,a%b);
        tie(x,y)=make_pair(y,x-(a/b)*y);
        return d;
    };
    auto inv=[&](int a,int m) ->int{
        return (exgcd(exgcd,a,m)==1?(x%m+m)%m:-1);
    };

    cout<< inv(n,P) << " ";



    return 0;
}

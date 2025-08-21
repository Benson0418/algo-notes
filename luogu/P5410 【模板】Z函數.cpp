#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin>>a>>b;
    int n=sz(a),m=sz(b);
    vector<int> z(m),p(n);

    z[0]=m;
    for (int i=1,c=0,r=0,len;i<m;++i){
        len=i<r?min(z[i-c],r-i):0;
        while (i+len<m && b[i+len]==b[len]){
            len++;
        }
        if (r<i+len){
            r=i+len;
            c=i;
        }
        z[i]=len;
    }

    for (int i=0,c=0,r=0,len;i<n;++i){
        len=i<r?min(z[i-c],r-i):0;
        while (i+len<n && len<m && a[i+len]==b[len]){
            ++len;
        }
        if (r<i+len){
            r=i+len;
            c=i;
        }
        p[i]=len;
    }

    unsigned long long res=0;
    for (int i=0;i<m;++i){
        res^=(unsigned long long)(i+1)*(z[i]+1);
    }
    cout<<res<<"\n";
    res=0;
    for (int i=0;i<n;++i){
        res^=(unsigned long long)(i+1)*(p[i]+1);
    }
    cout<<res;

    return 0;
}


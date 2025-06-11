#include<bits/stdc++.h>
using namespace std;
typedef long long LL;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    LL cnt=0,cost=0,a,b;
    cin>>n;
    vector<LL> A(n);
    for (LL& x:A){
        cin>>x;
        cnt+=x;
    }
    LL x;
    priority_queue<LL,vector<LL>,greater<LL>> pq(A.begin(),A.end());
    while (pq.size()>1){
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        x=a+b;
        cost+=x;
        pq.push(x);
    }
    cout<<cnt<<"\n"<<cost<<"\n";


    return 0;
}

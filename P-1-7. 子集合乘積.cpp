#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;

int n,res=0;
vector<uLL> LS,RS,L;
void enumerateLS(int curr,int idx,bool flag){
    if (idx>=LS.size()){
        return;
    }
    enumerateLS(curr,idx+1,flag);
    curr=curr*LS[idx]%10009;
    if (curr==1){++res;}
    L.push_back(curr);
    enumerateLS(curr,idx+1,1);

    return;
}
void enumerateRS(int curr,int idx,bool flag){
    if (idx>=RS.size()){
        return;
    }
    enumerateRS(curr,idx+1,flag);
    curr=curr*RS[idx]%10009;
    if (curr==1){++res;}
    for (int i=0;i<L.size();++i){
        if (curr*L[i]%10009==1){
            res=res+1;
        }
    }
    enumerateRS(curr,idx+1,1);
    return;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int a,i=0;i<n/2;++i){
        cin>>a;
        LS.push_back(a);
    }
    for (int a,i=n/2;i<n;++i){
        cin>>a;
        RS.push_back(a);
    }
    enumerateLS(1,0,0);
    enumerateRS(1,0,0);
    cout<<res<<endl;




    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int res=0,ct=0,x=0;
    int n,K;
    cin>>n>>K;
    vector<int> A;
    int l=0,r=0;
    for (int a,i=0;i<n;++i){
        cin>>a;
        A.push_back(a);
    }
    while (r<n){
        x+=A[r];
        ++r;
        while (x>K){
            x-=A[l];
            ++l;
        }
        if (x>res){
            res=x;
            ct=1;
        }
        else if (x==res){
            ct+=1;
        }
    }
    cout<<res<<"\n"<<ct<<"\n";



    return 0;
}

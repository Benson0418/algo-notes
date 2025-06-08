#include<bits/stdc++.h>
using namespace std;
string S;
int idx=0;
int solve(int x){
    int res=0;
    for (int i=0;i<4;++i){
        ++idx;
        if (S[idx-1]=='1'){
            res=res+x*x;
        }
        else if (S[idx-1]=='2'){
            res=res+solve(x/2);
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>S>>n;
    cout<<solve(n)<<endl;





    return 0;
}

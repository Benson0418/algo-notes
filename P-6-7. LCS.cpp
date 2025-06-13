#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A,B;
    cin>>A>>B;
    int lenA=A.size(),lenB=B.size();
    //cout<<lenA<<" "<<lenB<<endl;
    vector<vector<int>> LCS(lenA+1,vector<int>(lenB+1,0));
    //cout<<LCS.size()<<' '<<LCS[0].size()<<endl;
    for (int i=1;i<=lenA;++i){
        for (int j=1;j<=lenB;++j){
            LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            if (A[i-1]==B[j-1]) LCS[i][j]=max(LCS[i][j],LCS[i-1][j-1]+1);
        }
    }
    /*
    for (int i=0;i<=lenA;++i){
        for (int j=0;j<=lenB;++j){
            cout<<LCS[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    cout<<LCS[lenA][lenB];

    return 0;
}

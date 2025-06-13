#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A,B;
    cin>>A>>B;
    int lenA=A.size(),lenB=B.size();
    vector<int> pLCS(lenB+1),cLCS(lenB+1);

    for (int i=0;i<lenA;++i){
        for (int j=1;j<=lenB;++j){
            cLCS[j]=max(pLCS[j],cLCS[j-1]);
            if (A[i]==B[j-1]) cLCS[j]=max(cLCS[j],pLCS[j-1]+1);
        }
        swap(pLCS,cLCS);
    }
    cout<<cLCS.back();

    return 0;
}

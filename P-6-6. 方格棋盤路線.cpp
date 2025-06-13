#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m);
    for (int i=0;i<m;++i){
        grid[i].resize(n);
        for (int& z:grid[i]) cin>>z;
        for (int j=0;j<n;++j){
            if (i==0 && j==0) continue;
            else if (i==0) grid[0][j]+=grid[0][j-1];
            else if (j==0) grid[i][0]+=grid[i-1][0];
            else grid[i][j]+=max(grid[i-1][j],grid[i][j-1]);
        }
    }
    cout<<grid[m-1][n-1];


    return 0;
}

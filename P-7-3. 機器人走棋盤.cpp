#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n,mins=0x3f3f3f3f,a,x=0,y=0,nx,ny,curr,_x,_y,res=0;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    vector<vector<int>> ved(m,vector<int>(n));
    vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool flag=0;


    for (int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            cin>>a;
            grid[i][j]=a;
            if (a<mins){
                x=i;
                y=j;
                mins=a;
            }
        }
    }

    while (1){
        ved[x][y]=1;
        res+=grid[x][y];
        flag=1;
        curr=0x3f3f3f3f;
        for (auto& z:dir){
            nx=x+z.first;
            ny=y+z.second;
            if (nx>=0 && nx<m && ny>=0 && ny<n && !ved[nx][ny]){
                flag=0;
                if (grid[nx][ny]<curr){
                    curr=grid[nx][ny];
                    _x=nx;
                    _y=ny;
                }
            }
        }
        if (flag) break;
        x=_x;
        y=_y;
    }

    cout<<res;


    return 0;
}

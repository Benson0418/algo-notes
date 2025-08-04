class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        for (int i=0;i<n;++i){
            int sum=0;
            for (int j = 0;j<piles[i].size();++j){
                piles[i][j]+=sum;
                sum=piles[i][j];
            }
        }
        vector<int> dp(k+1);
        for (int i=0;i<n;++i){

            for (int j=k;j>=0;--j){
                for (int x = 0;x<piles[i].size();++x){
                    if (j<x+1) break;
                    dp[j]=max(dp[j], dp[j-x-1] + piles[i][x]);
                }
            }
        }
        return dp[k];
    }
};

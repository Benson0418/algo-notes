class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()/2;
        sort(costs.begin(),costs.end(), [](vector<int>& A,vector<int>& B){
            return A[0]-A[1]<B[0]-B[1];
        });
        int res=0;
        for (int i=0;i<n;++i){
            res+=costs[i][0];
        }
        for (int i=n;i<2*n;++i){
            res+=costs[i][1];
        }
        return res;
    }
};

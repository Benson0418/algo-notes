class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        using LL = long long;
        function<bool(vector<int>&,vector<int>&)> cmp=[](vector<int>& A, vector<int>& B){
            return A[0]>B[0];
        };
        sort(items.begin(),items.end(),cmp);
        int len=(int)items.size();
        LL total_profit=0;
        LL distinct_categories=0;
        unordered_map<int,int> isd;
        int i=0;
        LL max_res=0;
        vector<int> stk;
        while (k){
            if (!isd[items[i][1]]){
                isd[items[i][1]]=items[i][0];
                total_profit+=items[i][0];
                distinct_categories++;
            }
            else{
                total_profit+=items[i][0];
                stk.push_back(items[i][0]);
            }
            --k;
            ++i;
        }
        max_res=total_profit+distinct_categories*distinct_categories;
        for (;i<len;++i){
            if (!isd[items[i][1]]){
                if (stk.empty()) continue;
                total_profit-=stk.back();
                stk.pop_back();
                distinct_categories++;
                total_profit+=items[i][0];
                isd[items[i][1]]=items[i][0];
                max_res=max(max_res,total_profit+distinct_categories*distinct_categories);
            }
        }
        return max_res;
    }
};

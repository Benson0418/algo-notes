class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(), 0);
        if (abs(target)>sum) return 0;
        target+=sum;
        if (target&1) return 0;
        target/=2;
        vector<int> res(target+1);
        res[0]=1;
        for (int i=0;i<nums.size();++i){
            for(int j=target;j>=nums[i];--j){
                res[j]+=res[j-nums[i]];
            }
        }
        return res[target];
    }
};

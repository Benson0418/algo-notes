class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        vector<int> kns(target+1);
        kns[0]=1;
        for (auto& num:nums){
            for (int i=target;i>=num;--i){
                kns[i]+=kns[i-num];
            }
        }
        int i;
        for (i=target;i>=0;--i){
            if (kns[i]) break;
        }
        return sum-2*i;
    }  
};

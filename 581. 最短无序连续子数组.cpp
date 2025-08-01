class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(),a=0,b=0;
        int e=INT_MIN;
        for (int i=0;i<n;++i){
            if (nums[i]<e){
                b=i;
            }
            else{
                e=nums[i];
            }
        }
        if (b==0) return 0;
        e=INT_MAX;
        for (int i=n-1;i>=0;--i){
            if (nums[i]>e) a=i;
            else e=nums[i];
        }
        return b-a+1; 
    }
};

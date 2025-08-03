class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int maxi=INT_MIN,diff=INT_MAX,ml=0,mr=0;
        vector<int> p(k);
        for (int i=0;i<k;++i){
            maxi=max(maxi,nums[i][0]);
            pq.push({nums[i][0],i});
        }
        ml=pq.top().first;
        mr=maxi;
        diff=mr-ml;
        int a,b;

        for (;;){
            a=pq.top().first;
            b=pq.top().second;
            pq.pop();
            ++p[b];
            if (p[b]>=(nums[b].size())) break;
            maxi=max(maxi,nums[b][p[b]]);
            pq.push({nums[b][p[b]],b});
            if (diff>maxi-pq.top().first){
                diff=maxi-pq.top().first;
                mr=maxi;
                ml=pq.top().first;
            }
        }
        return {ml,mr};

    }
};

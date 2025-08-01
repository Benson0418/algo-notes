class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        int time=events[0][0];
        int p=0,cnt=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        while (p<n || !pq.empty()){
            while (p<n && events[p][0]<=time){
                pq.push(events[p][1]);
                ++p;
            }
            while (!pq.empty() && pq.top()<time){
                pq.pop();
            }
            if (!pq.empty()){
                pq.pop();
                ++cnt;
            }
            ++time;
        }
        return cnt;
    }
};

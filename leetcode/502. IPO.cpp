class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> E(n);
        for (int i=0;i<n;++i){
            E[i]={capital[i],profits[i]};
        }
        sort(E.begin(),E.end());
        priority_queue<int> pq;
        int p=0;
        while (k--){
            while (p<n && E[p].first<=w){
                pq.push(E[p].second);
                ++p;
            }
            if (pq.empty()) break;

            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};

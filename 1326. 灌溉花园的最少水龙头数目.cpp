class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> E(n+1);
        for (int i=0;i<=n;++i){
            if (ranges[i]){
                int a=max(0,i-ranges[i]);
                int b=min(n,i+ranges[i]);
                E[a]=max(E[a],b);
            }
        }
        int i=0,cnt=0,nxt_cover=0,nxt_candidate=0;
        for (;i<=n;++i){
            if (i>nxt_cover) break;
            nxt_candidate=max(nxt_candidate,E[i]);
            if (i==nxt_cover && i<n){
                nxt_cover=nxt_candidate;
                ++cnt;
            }
        }


        if (i<n || nxt_cover<n){
            return -1;
        }
        else{
            return cnt;
        }

    }
};

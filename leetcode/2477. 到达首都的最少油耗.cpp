class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<int> head(n,-1),edges(2*n-2,-1),to(2*n-2,-1);
        int i=0;
        for (auto& ed : roads){
            int u=ed[0],v=ed[1];
            edges[i]=head[u];
            head[u]=i;
            to[i++]=v;
            edges[i]=head[v];
            head[v]=i;
            to[i++]=u;
        }
        
        function<pair<long long,long long>(int,int)> f=[&](int idx,int pa){
            long long res=0,ppl=0;
            for (int k=head[idx];k!=-1;k=edges[k]){
                if (to[k]==pa) continue;
                pair<long long,long long> e=f(to[k],idx);
                res+=e.first;
                ppl+=e.second;
            }
            ++ppl;
            res+=(ppl-1)/seats+1;

            if (idx==0) return make_pair(res-((ppl-1)/seats+1),ppl);
            return make_pair(res,ppl);
        };

        return  f(0,-1).first;
    }
};

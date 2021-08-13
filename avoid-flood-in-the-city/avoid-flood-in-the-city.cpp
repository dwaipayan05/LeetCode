class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();
        
        vector<int>ans(n, -1);
        unordered_map<int, int>mp;
        set<int>dry;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(rains[i] == 0)
            {
                dry.insert(i);
                continue;
            }
            if(mp.find(rains[i])!=mp.end())
            {
                auto it = dry.lower_bound(mp[rains[i]]);
                if(it == dry.end())
                    return {};
                ans[*it] = rains[i];
                dry.erase(it);
            }
            
            mp[rains[i]] = i;
        }
        
        for(auto x : dry)
            ans[x] = 1;
        
        
        return ans;
    }
};
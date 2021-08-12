class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>res;
        map<string,vector<string>>mp;
        
        for(int i = 0 ; i < strs.size(); i++)
        {
            string x = strs[i];
            sort(x.begin(), x.end());
            mp[x].push_back(strs[i]);
        }
        
        for(auto x : mp)
        {
            vector<string>temp = x.second;
            res.push_back(temp);
        }
        
        return res;
        
        
    }
};
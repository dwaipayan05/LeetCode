class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>res;
        
        map<int,int>mp;
        for(auto ch : p)
            mp[ch]++;
        
        int begin = 0;
        int end = 0;
        
        int count = mp.size();
        
        
        while(end < s.length())
        {
            if(mp.find(s[end])!=mp.end())
            {
                mp[s[end]]--;
                
                if(mp[s[end]] == 0)
                    count--;
            }
            
            end++;
            
            while(count == 0)
            {
                if(mp.find(s[begin])!=mp.end())
                {
                    mp[s[begin]]++;
                    if(mp[s[begin]] > 0)
                        count++;
                }            
            
            
                if(end - begin == p.length())
                    res.push_back(begin);
            
                begin++;
           }
                
        }
        
        return res;
        
    }
};
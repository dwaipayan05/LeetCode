class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>mp;
        
        for(auto ch : t)
            mp[ch]++;
        
        
        int start = 0;
        int end = 0;
        
        int min_len = INT_MAX;
        int min_start = 0;
        
        int count = 0;
        
        for(int end = 0; end < s.length(); end++)
        {
            if(mp[s[end]] > 0)
                count++;
            
            mp[s[end]]--;
            if(count == t.length())
            {
                while(start < end && mp[s[start]] < 0)
                {
                    mp[s[start]]++;
                    start++;
                }
            
                if(end - start + 1 < min_len)
                {
                    min_start = start;
                    min_len = end - start + 1;
                }
            
                mp[s[start]]++;
                start++;
                count--;
                
             }
        
        
        }
           
        if(min_len == INT_MAX)
            return "";
        return s.substr(min_start, min_len);
    }
};
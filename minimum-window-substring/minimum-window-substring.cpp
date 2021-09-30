class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>mp;
        
        for(auto c : t)
            mp[c]++;
        
        
        int start = 0;
        int end = 0;
        int count = 0;
        
        int minLen = INT_MAX;
        int minStart = 0;
        
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
                
                if(end - start + 1 < minLen)
                {
                    minLen = end - start + 1;
                    minStart = start;
                }
                
                mp[s[start]]++;
                start++;
                count--;
            }
                
        }
        
        if(minLen == INT_MAX)
            return "";
        
        return s.substr(minStart, minLen);
    }
};
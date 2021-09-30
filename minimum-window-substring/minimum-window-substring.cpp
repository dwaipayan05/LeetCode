class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> char_fq;
        
        for(auto c : t)
            char_fq[c]++;
        
        int ans = INT_MAX;
        int min_start = 0;
        int count = 0;
        
        
        int i = 0, j = 0;
    
        for(i = 0; i < s.length(); i++)
        {
            if(char_fq[s[i]] > 0)
                count++;
            
            char_fq[s[i]]--;
            
            if(count == t.length())
            {
                while(j < i && char_fq[s[j]]<0)
                {
                    char_fq[s[j]]++;
                    j++;
                }
                
                if(i - j + 1 < ans)
                {
                    min_start = j;
                    ans = i-j+1;
                }
                
                
                char_fq[s[j]]++;
                j++;
                count--;
            }
        }
        
        
        if(ans == INT_MAX)
            return "";
        
        return s.substr(min_start, ans);
            
            
        
    }
};
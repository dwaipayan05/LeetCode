class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        return longestSubstringHelper(s,0,n,k);
    }
    
    int longestSubstringHelper(string s, int start, int end, int k)
    {
        if(end < k)
            return 0;
        
        int mp[26] = {0};
        
        for(int i = start ; i < end; i++)
            mp[s[i] - 'a']++;
        
        for(int mid = start; mid < end; mid++)
        {
            if(mp[s[mid] - 'a'] >= k) continue;
            
            int midNext = mid + 1;
            
            while(midNext < end && mp[s[midNext] - 'a'] < k)
                midNext++;
            
            return max(longestSubstringHelper(s,start, mid, k), longestSubstringHelper(s, midNext, end, k));
        }
        
        
        return end - start;
        
    }
};
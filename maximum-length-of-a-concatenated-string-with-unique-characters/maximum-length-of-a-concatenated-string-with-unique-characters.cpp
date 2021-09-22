class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        //Create a Vector of a Bitset of 26 Chars
        //To Keep Track of All Possible Concatenations
        vector<bitset<26>>dp = {bitset<26>()};
        int n = arr.size();
        
        int res = 0;
        
        //Iterate through the Array of Strings
        for(int i = 0 ; i < n; i++)
        {
            //Create a bitset for the Particular String
            bitset<26> a;
            string x = arr[i];
            
            //Set Bits for each character
            //If It Occurs Twice, it's reset to 0
            for(char c : x)
                a.set(c - 'a');
            
            //Check if Count of Set Bits == Size of String
            //If Not, Character is repeated, Ignore & Continue
            int cnt = a.count();
            if(cnt < x.size())
                continue;
            
            //Traverse through Every Possible Concatenation
            for(int j = dp.size() - 1; j >= 0; --j)
            {
                
                bitset<26>b = dp[j];
                
                //For Current Concatenation, 
                //If Any Bit Matches with 1, Duplicate Characters, Continue
                if((b & a).any())
                    continue;
                
                //Push back the Concatenation 
                dp.push_back(b|a);
                
                //Find Max of the Size with Current Bitset Size
                res = max(res, (int)b.count() + cnt);
            }
            
        }
        
        
        return res;
        
    }
};
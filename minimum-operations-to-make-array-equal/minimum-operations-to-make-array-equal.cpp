class Solution {
public:
    int minOperations(int n) {
        
        int ans = 0;
        int tar = n;
        while(n--)
        {
            if(n%2==1)
            {
                int x = tar - n;
                ans += x;
            }
         
        }
        
        
            return ans;
    }
    
};

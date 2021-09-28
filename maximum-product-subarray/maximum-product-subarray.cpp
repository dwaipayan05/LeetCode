class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN;
        int product = 1;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            ans = max(ans, product*=nums[i]);
            if(nums[i] == 0)
                product = 1;
        }
        
        product = 1;
        
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            ans = max(ans, product*=nums[i]);
            if(nums[i] == 0)
                product = 1;
        }
        
        return ans;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int end = nums.size() - 1;
        int max_pos = 0;
        
        for(int i = 0; i <= max_pos; i++)
        {
            max_pos = max(max_pos, nums[i] + i);
            if(max_pos >= end)
                return true;
        }
        
        return false;
    }
};
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int Sum = 0;
        for(auto n : nums)
            Sum += n;
        
        if(Sum%k != 0 || k == 0)
            return false;
        
        vector<bool>used(nums.size(), false);
        
        return canPartition(nums, used, k,  0, 0, Sum/k);
    }
    
    bool canPartition(vector<int> nums, vector<bool>used, int k, int currIdx, int currSum, int targetSum)
        
    {
        if(k==1)
            return true;
        
        if(currSum == targetSum)
            return canPartition(nums, used, k-1, 0, 0, targetSum);
        
        
        for(int i = currIdx; i < nums.size(); i++)
        {
            if(!used[i])
            {
                used[i] = true;
                if(canPartition(nums, used, k, i+1, currSum + nums[i], targetSum))
                    return true;
                used[i] = false;
                
            }
        }
        
        
        return false;
    }
};
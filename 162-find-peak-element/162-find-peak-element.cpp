class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        if(r == 1)
            return 0;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(mid + 1 < nums.size() and nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
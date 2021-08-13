class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        
        while(left < right && arr[left+1] >= arr[left])
            left++;
        
        if(left == n-1)
            return 0;
        
        while(right > left && arr[right] >= arr[right-1])
            right--;
        
        int min_Len = min(n - left - 1, right);
        
        int j = right;
        for(int i = 0 ; i < left+1 ; i++)
        {
            if(arr[i] <= arr[j])
            {
                min_Len = min(min_Len, j-i-1);
                
            }
            
            else if (j < n-1)
            {
                j++;
            }
            
            else
            {
                break;
            }
        }
        
        return min_Len;
        
        
    }
};
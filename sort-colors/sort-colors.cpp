class Solution {
public:
    void sortColors(vector<int>& arr) {
        
        int hi = arr.size()-1;
        int lo = 0;
        int mid = 0;
        
        while(mid <= hi)
        {
            if(arr[mid] == 2)
            {
                int temp = arr[hi];
                arr[hi] = arr[mid];
                arr[mid] = temp;
                hi--;
            }
            
            else if(arr[mid] == 0)
            {
                int temp = arr[lo];
                arr[lo] = arr[mid];
                arr[mid] = temp;
                lo++;
                mid++;
            }
            
            else
                mid++;
        }
        
    }
};
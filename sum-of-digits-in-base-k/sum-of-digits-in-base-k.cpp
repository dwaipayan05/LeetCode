class Solution {
public:
    int sumBase(int n, int k) {
        vector<int>digits;
        
        int digit;
        while(n>0)
        {
            digit = n%k;
            digits.push_back(digit);
            n /= k;
        }
        
        int sum = accumulate(digits.begin(), digits.end(), 0);
        return sum;
    }
};
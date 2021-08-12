class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(m == 1 || n == 1)
            return 1;
        
        m--;
        n--;
        
        long res = 1;
        if(m < n)
        {
            int temp = m;
            m = n;
            n = temp;

        }
        
        int j = 1;
        for(int i = m + 1; i <= m+n ; i++, j++)
        {
            res *= i;
            res /= j;
        }
        
        return (int)res;
    }
};
class Solution {
public:    
    long long binomialCoef(long long n, long long k)
    {
        if(k > n-k)
            k = n-k;
        
        long long res = 1;
        for(int i = 0; i < k; i++)
        {
            res *= (n-i);
            res /= (i+1);
        }
        
        return res;
    }
    
    long long catalan(long long n)
    {
        long long res = binomialCoef(2*n, n);
        return res/(n+1);
    }
    
    int numTrees(int n) {
        
        return catalan(n);
    }
};
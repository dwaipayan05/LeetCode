class Solution {
public:
    int countOrders(int n) {
        long mod = 1e9 + 7;
        long res = 1L;
        long spots = 2*n;
        
        for(int i = n ; i != 1; i--)
        {
            res = (res * (spots*(spots-1))/2L)%mod;
            spots-=2;
        }
        
        
        return (int)res;
    }
};

/*
4 -> P1 D1 P2 D2 P3 D3 P4 D4

P1 _ _ _ _ _ _ _
P1 P2 _ _ _ _ _
P1 D1 _ _ _ _ _


P2 _ _ _ _ _ _ _ 
P3 _ _ _ _ _ _ _
P4 _ _ _ _ _ _ _

4 * 4 * 

Initially 2n Spots
Pick 2 for P1 D1
Pick 2 for P2 D2
.
.
.
.



*/
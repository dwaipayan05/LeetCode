class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start = 0;
        int end = 0;
        int ans = INT_MAX;
        int balance_fuel = 0;
        int n = gas.size();
        
        if(!n)
            return -1;
        
        while(end < 2*n && start < n)
        {
            while(end < 2*n)
            {
                if(balance_fuel >=0)
                {
                    balance_fuel += (gas[end%n] - cost[end%n]);
                }
                
                else
                {
                    break;
                }
                
                end++;
            }
            
            if(end < 2*n)
                start = end;
            balance_fuel = 0;
        }
        
        
        return (start < n) ? start : -1;
        
        
        
    }
};
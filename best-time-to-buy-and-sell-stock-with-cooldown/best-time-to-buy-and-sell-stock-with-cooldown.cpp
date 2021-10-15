class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0)
            return 0; 
        // Since nothing is done intially
        int cooldown = 0, cooldown_prev = 0;
        // Buying first item gives us no profit value initially
        int bought = -1 * prices[0], bought_prev = -prices[0];
        // Buying and selling on the first day gives profit of 0
        int sold = 0, sold_prev = 0;        
        
        for(int i = 1; i < prices.size(); i++) {
            // State 1
            bought = max(bought_prev, cooldown_prev - prices[i]);
            // State 2
            sold = bought_prev + prices[i];
            // State 3
            cooldown = max(cooldown_prev, sold_prev);
            
            // update previous values
            bought_prev = bought, sold_prev = sold, cooldown_prev = cooldown;
        }
        
        return max(cooldown, sold);
    }
};
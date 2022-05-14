class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        int m = heaters.size();
        int n = houses.size();
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        map<int, int> mp; 
        for(int i = 0; i < n; i++)
        {
            int currHouse = houses[i];
            int nextHeater = upper_bound(heaters.begin(), heaters.end(), currHouse) - heaters.begin();
            
            int prevHeater = nextHeater - 1;
            
            if(nextHeater == 0)
                mp[houses[i]] = heaters[nextHeater] - houses[i];
            else if(nextHeater == m)
                mp[houses[i]] = houses[i] - heaters[prevHeater];
            else
                mp[houses[i]] = min(houses[i] - heaters[prevHeater], heaters[nextHeater] - houses[i]);
        }
        
        
        int ans = INT_MIN;
        for(auto house : mp)
            ans = max(ans, house.second);
        
        return ans;
    }
};
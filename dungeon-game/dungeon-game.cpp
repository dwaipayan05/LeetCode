class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int r = dungeon.size();
        int c = dungeon[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,INT_MAX));
        dp[r][c-1]=1;
        dp[r-1][c]=1;
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                int need=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                if(need<=0)
                    dp[i][j]=1;
                else
                    dp[i][j]=need;
            }
        }
        return dp[0][0];
    }
};
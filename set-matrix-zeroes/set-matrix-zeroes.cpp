class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        map<int,int>mp_r;
        map<int,int>mp_c;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(mp_r.find(i)==mp_r.end())
                        mp_r[i] = 1;
                    if(mp_c.find(j)==mp_c.end())
                        mp_c[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c ; j++)
            {
                if(mp_r.find(i)!=mp_r.end())
                    matrix[i][j] = 0;
                
                if(mp_c.find(j)!=mp_c.end())
                    matrix[i][j] = 0;
            }
        }
    }
};
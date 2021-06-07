class Solution {
public:
    double distance(int x1, int y1, int x2, int y2)
    {
        double sqr1 = (x1-x2)*(x1-x2);
        double sqr2 = (y1-y2)*(y1-y2);
        
        double sqr = sqr1+sqr2;
        double root = sqrt(sqr);
        
        return root;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int>ans;
        int n = queries.size();
        
        for(int i = 0 ; i < n; i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            
            int point_size = points.size();
            
            int count = 0;
            for(int j = 0 ; j < point_size; j++ )
            {
                int x_pnt = points[j][0];
                int y_pnt = points[j][1];
                
                double dist = distance(x_pnt, y_pnt, x , y);
                double rad = r;
                
                if(rad >= dist)
                    count++;
            }
            
            ans.push_back(count);
        }
        
        
        return ans;
        
    }
};
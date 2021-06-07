class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log10(label)/log10(2);
        vector<int>res;
        
        while(level >= 0)
        {
            res.insert(res.begin(), label);
            
            int frst = (int)pow(2,level-1);
            int scnd = (int)pow(2,level) - 1;
            int nxt = label/2;
            
            label = frst + scnd - nxt;
            level--;
        }
        
        
        return res;
    }
};


// 1
// 2
// 4
// 8
// 16
// 32

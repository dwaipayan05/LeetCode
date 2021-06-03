class Solution {
public:
    string generateTheString(int n) {
        string s = "";
        
        if(n%2 == 0)
        {
            s += 'a';
            n--;
        }
        
         while(n--)
                s += 'b';

        
        return s;
    }
};
    
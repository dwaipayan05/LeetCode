class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char x = coordinates[0];
        char y = coordinates[1];
        
        int x1 = x - 'a' + 1;
        int y1 = y - '0';
        
        return (x1%2==0&&y1%2==0 || x1%2==1&&y1%2==1) ? false : true;
    }
};
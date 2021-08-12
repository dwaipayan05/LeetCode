class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_char = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int sum = roman_char[s.back()];
        
        for(int i = s.length() - 2; i >= 0 ; i--)
        {
            if(roman_char[s[i]] < roman_char[s[i+1]])
                sum -= roman_char[s[i]];
            else
                sum += roman_char[s[i]];
        }
            
        
        return sum;
    }
};
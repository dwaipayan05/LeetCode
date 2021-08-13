class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
    
    string s;
    
    int acount=0;
    int bcount=0;
    int ccount=0;
    
    while(1) {
        
        if(a==0 && b==0 && c==0) {
            break;
        }
        
        
        if(acount==2 || bcount==2 || ccount==2) {
            

            if(acount==2) {
                
                if(b==0 && c==0) {
                    return s;
                }
                
                if(b>=c) {
                    b--;
                    s += "b";
                    bcount++;
                    
                }
                else {
                    c--;
                    s += "c";
                    ccount++;
                }
                
                acount = 0;
                
            }
            
            else if(bcount==2) {
                
                if(a==0 && c==0) {
                    return s;
                }
                
                if(a>=c) {
                    a--;
                    s += "a";
                    acount++;
                    
                }
                else {
                    c--;
                    s += "c";
                    ccount++;
                }
                bcount = 0;
                
            }

            else {
                
                if(a==0 && b==0) {
                    return s;
                }
                
                if(a>=b) {
                    a--;
                    s += "a";
                    acount++;
                    
                }
                else {
                    b--;
                    s += "b";
                    bcount++;
                }
                ccount = 0;
            }
            
            continue;
            
        }
        
        
        if(a>=b) {
            if(a>=c) {
                a--;
                s += "a";
                acount++;
                bcount = 0;
                ccount = 0;
                
            }
            else {
                c--;
                s += "c";
                ccount++;
                acount = 0;
                bcount = 0;
                    
            }
        }
        else {
            if(b>=c) {
                b--;
                s += "b";
                bcount++;
                acount = 0;
                ccount = 0;
            }
            else {
                c--;
                s += "c";
                ccount++;
                acount = 0;
                bcount = 0;
            }
        }
        
        
        
        
    }
    
    return s;
    }
};
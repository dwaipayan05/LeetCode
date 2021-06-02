class Solution {
public:
    bool isInterleaved(
    char* A, char* B, char* C)

 {
    int M = strlen(A), N = strlen(B);
    bool IL[M + 1][N + 1];

    memset(IL, 0, sizeof(IL));

    if ((M + N) != strlen(C))
        return false;
 
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            
            if (i == 0 && j == 0)
                IL[i][j] = true;
 
            // A is empty
            else if (i == 0) {
                if (B[j - 1] == C[j - 1])
                    IL[i][j] = IL[i][j - 1];
            }
 
            // B is empty
            else if (j == 0) {
                if (A[i - 1] == C[i - 1])
                    IL[i][j] = IL[i - 1][j];
            }
 
            else if (
                A[i - 1] == C[i + j - 1]
                && B[j - 1] != C[i + j - 1])
                IL[i][j] = IL[i - 1][j];

            else if (
                A[i - 1] != C[i + j - 1]
                && B[j - 1] == C[i + j - 1])
                IL[i][j] = IL[i][j - 1];
 
            else if (
                A[i - 1] == C[i + j - 1]
                && B[j - 1] == C[i + j - 1])
                IL[i][j]
                    = (IL[i - 1][j]
                       || IL[i][j - 1]);
        }
    }
 
    return IL[M][N];
}
    
    bool isInterleave(string s1, string s2, string s3) {
        
        
        int n = s1.length();
        int m = s2.length();
        int o = s3.length();
        
        char n_arr[n+1];
        char m_arr[m+1];
        char o_arr[o+1];
        
        strcpy(n_arr, s1.c_str());
        strcpy(m_arr, s2.c_str());
        strcpy(o_arr, s3.c_str());
        
        char *a = n_arr;
        char *b = m_arr;
        char *c = o_arr;
        
        bool ans = isInterleaved(a,b,c);
        return ans;
    }
};

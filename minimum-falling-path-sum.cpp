class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        int dp[rows][cols];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(i==0) {
                    dp[i][j] = A[i][j];
                } else {
                    int topLeft = j == 0 ? INT_MAX : dp[i-1][j-1];
                    int top = dp[i-1][j];
                    int topRight = j == (cols-1) ? INT_MAX : dp[i-1][j+1];
                    int minim = min({topLeft, top, topRight});
                    dp[i][j] = A[i][j] + minim;
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<cols;i++) {
            ans = min(ans, dp[rows-1][i]);
        }
        return ans;
    }
};

class Solution {
public:
    int dp[40001][3];
    
    int maxSumDivThree(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int ans = 0;
        
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;

        int a,b,c;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%3 == 0) {
                dp[i+1][0] = dp[i][0] + nums[i];
                dp[i+1][1] = dp[i][1] + nums[i];
                dp[i+1][2] = dp[i][2] + nums[i];
            } else if(nums[i]%3==1) {
                dp[i+1][1] = max(dp[i][1],dp[i][0] + nums[i]);
                dp[i+1][2] =  max(dp[i][2],dp[i][1] + nums[i]);
                dp[i+1][0] =  max(dp[i][0],dp[i][2] + nums[i]);
            } else {
                
                dp[i+1][2] =  max(dp[i][2],dp[i][0] + nums[i]);
                dp[i+1][0] =  max(dp[i][0],dp[i][1] + nums[i]);
                dp[i+1][1] =  max(dp[i][1],dp[i][2] + nums[i]);
            }
        }
        return dp[nums.size()][0];
    }
};
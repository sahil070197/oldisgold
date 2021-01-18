class Solution {
public:
    int dp[101][101][21];
    long long solve(int curHouse, int remTargets, int prevCol, vector<int>& houses, vector<vector<int>>& cost, int m, int n) {
        
        if(curHouse == houses.size()) {
            return remTargets == 0 ? 0 : INT_MAX;
        }
        
        if(remTargets == -1) {
            return INT_MAX;
        }
        
        if(dp[curHouse][remTargets][prevCol]) {
            return dp[curHouse][remTargets][prevCol];
        }
        
        if(houses[curHouse]!=0) {
            
            int tempTargets= remTargets - (curHouse==0 || (houses[curHouse] == prevCol) ? 0 : 1);
            return solve(curHouse+1, tempTargets, houses[curHouse], houses, cost, m, n);
        }
        
        long long ans = INT_MAX;
        for(int i=0;i<n;i++) {
            int costVal = cost[curHouse][i];
            int color = i+1;
            int tempTargets= remTargets - (curHouse==0 || (color == prevCol) ? 0:1);
            ans = min(ans, solve(curHouse+1, tempTargets, color, houses, cost, m, n) + costVal);
        }
        return dp[curHouse][remTargets][prevCol] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int a = solve(0, target-1, 0, houses, cost, m, n) ;
        return a==INT_MAX ? -1:a;
    }
};
class Solution {
public:
    int dp[366];
    int getNextDay(vector<int> &days, int nextDay) {
        int index = lower_bound(days.begin(), days.end(), nextDay) - days.begin();
        if(index < days.size()) {
            return days[index];
        }
        return *days.rbegin()+1;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        return solve(*days.begin(), days, costs);
    }
    
    int solve(int curDay, vector<int> &days, vector<int> &costs) {
        if(curDay > *days.rbegin()) {
            return 0;
        }
        
        if(dp[curDay]) {
            return dp[curDay];
        }
        int next_1 = getNextDay(days, curDay+1);
        int next_2 = getNextDay(days, curDay+7);
        int next_3 = getNextDay(days, curDay+30);
        
        int option_1 = INT_MAX, option_2 = INT_MAX, option_3 = INT_MAX;
        
        option_1 = solve(next_1, days, costs) + costs[0];
        
        option_2 = solve(next_2, days, costs) + costs[1];
        
        option_3 = solve(next_3, days, costs) + costs[2];
        
        
        return dp[curDay] = min({option_1, option_2, option_3});
    }
};
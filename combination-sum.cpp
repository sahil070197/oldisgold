class Solution {
public:
    vector<vector<int>> ans;
    int n;
    int dp[500][500];
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        memset(dp, 0, sizeof(dp));
        n = candidates.size();
        vector<int> v;
        memset(dp, 0, sizeof(dp));
        solve(target, 0, v, candidates);
        
        return ans;
    }
    void solve(int weight, int index, vector<int> &curSet, vector<int> &candidates) {
        if(weight < 0) {
            return;
        }
        if(weight == 0) {
            vector<int> v(curSet);
            ans.push_back(v);
            return;
        }
        if(index >= n) {
            return;
        }
        
        dp[weight][index] = 1;
        curSet.push_back(candidates[index]);
        solve(weight - candidates[index], index, curSet, candidates);
        curSet.pop_back();
        solve(weight, index+1, curSet, candidates);
    }
};
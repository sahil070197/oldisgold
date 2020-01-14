class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<char> v;
        solve(0, 0, v, n);
        return ans;
    }
    void solve(int close, int open, vector<char> &curSet, int n) {
        if(open > n) {
            return;
        }
        if(open == close && open == n) {
            string a(curSet.begin(), curSet.end());
            ans.push_back(a);
            return;
        }
        
        if(open > close) {
            curSet.push_back(')');
            solve(close+1, open, curSet, n);
            curSet.pop_back();
        }
        curSet.push_back('(');
        solve(close, open+1, curSet, n);
        curSet.pop_back();
    }
};
class Solution {
public:
    #define mod 1000000007
    int mul(int a, int b) {
        return (a%mod * b%mod)%mod;
    }
    int add(int a, int b) {
        return (a%mod + b%mod)%mod;
    }
    int numTilings(int n) {
        if(n==0)
            return 0;
        
        long long int dp[max(3, n+1)];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++) {
            dp[i] = add(mul(dp[i-1],2),dp[i-3]);
        }
        return dp[n];
    }
};

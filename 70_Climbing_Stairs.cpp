class Solution {
public:
    int climbStairs(int n) {
        vector <int> dp {0,1,2};
        if (n == 1) return 1;
        if (n == 2) return 2;
        int i=3;
        while (i<=n){
            dp.push_back(dp[i-1]+dp[i-2]);
            i++;
        }
        return dp[dp.size()-1];
    }
};

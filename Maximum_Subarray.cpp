class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector <int> dp{nums[0]};
        int i =1;
        int sum=nums[0];
        while (i<nums.size()){
            dp.push_back(max(dp[i-1]+nums[i],nums[i]));
            sum=max(sum,dp[i]);
            i++;
            
        }
        return sum;
    }
};

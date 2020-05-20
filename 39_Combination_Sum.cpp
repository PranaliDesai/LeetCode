class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> nums;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, nums, res);
    return res;
}

void dfs(vector<int>& candidates, int target, int index, vector<int>& nums, vector<vector<int>>& res) {
    if (target < 0)
        return;
    if (target == 0) {
        res.push_back(nums);
        return;
    }
    for (int i=index; i<candidates.size(); i++) {
        nums.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], i, nums, res);
        nums.pop_back();
    }
}
};

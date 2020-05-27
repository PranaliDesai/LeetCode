class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;
        vector<int> ans {-1,-1};
        bool first = false;
        bool second = false;
        while(l<=r){
            if (nums[l] != target ) l++;
            else {
                ans[0]=l;
                first=true;
            }
            if (nums[r] != target ) r--;
            else {
                ans[1]=r;
                second=true;
            }
            if (first && second) break;

        }
        return ans;
    }
};

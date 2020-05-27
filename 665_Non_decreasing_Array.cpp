class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int check=0;
        for(int i = 0; i<nums.size()-1;i++){
            if (nums[i]>nums[i+1]) {
                check +=1;
                if (i != 0 && i != nums.size()-2 && nums[i-1] > nums[i+1] && nums[i] > nums[i+2])  
                    return false;
            }
            if (check>1) return false;
        }
        return true;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int l = 0, r = nums.size() - 1;
        int mid;
        if (nums[r] > nums[0]) return nums[0];
        while(l <= r){ 
            mid = l + (r - l) / 2;
            //cout<<nums[mid];
            if (nums[mid]>nums[mid+1] ) return nums[mid+1];
            if (nums[mid - 1] > nums[mid]) return nums[mid];
            if(nums[mid] < nums[0]){
                r = mid - 1;    
            }else{
                l = mid + 1;   
            } 
        }
        return -1;
    }
};
